#ifndef SMALLOBJECT_H
#define SMALLOBJECT_H

#include <iostream>
#include "CoreLibrary/Pattern/SingletonHolder.hpp"
#include "CoreLibrary/Policies/Singleton/PhoenixSingleton.hpp"
#include "CoreLibrary/Policies/ThreadingModel/SingleThreaded.hpp"
#include "SmallObjectAllocator.hh"
#include <cstddef>

/*! \class SmallObject SmallObject.hpp
 *
 * \brief
 *	SmallObject class destinate to be herited by another class to be a small object
 *
 * \tparam ThreadingModel : The threading model (ex : SingleThreaded, MultiThreaded)
 */

template<template<class T> class ThreadingModel = SingleThreaded>
class SmallObject
{
public:

  /*!
   * \brief Constructor of SmallObject
   *
   * Construct a SmallObject instance
   */
    SmallObject()
    {

    }

    /*!
     * \brief Destructor of small object
     */
    virtual ~SmallObject() {}

    /*!
     * \brief overloaded new operator
     *
     * when you use new operator with SmallObject then use this method
     * The method allocate a new object with the a Singleton SmallObjectAllocator instance
     *
     * \param size : the size(passed automatically by new operator don't need to pass it explicitly)
     * \return the pointer to SmallObject instance
     */
    void    *operator new(std::size_t size)
    {
        typename ThreadingModel<SmallObject>::Lock  lock;

	(void)lock;
        return SingletonHolder<SmallObjectAllocator,
                               NewCreator,
                               PhoenixSingleton,
                               ThreadingModel>::getInstance().allocate(size);
    }

    /*!
     * \brief overloaded delete operator
     *
     * when you use the delete operator with SmallObject then use this method
     * The method deallocate the SmallObject instance
     *
     * \param p : a valid pointer to the SmallObject
     * \param size : the size of the SmallObject instance
     * (You don't need to pass the parameters explicitly delete do it for you)
     */
    void    operator delete(void *p, std::size_t size)
    {
        typename ThreadingModel<SmallObject>::Lock  lock;

	(void)lock;
        SingletonHolder<SmallObjectAllocator,
                        NewCreator,
                        PhoenixSingleton,
                        ThreadingModel>::getInstance().deallocate(p, size);
    }
};

#endif // SMALLOBJECT_H
