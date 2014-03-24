#ifndef GENSCATTERHIERARCHY_HPP
#define GENSCATTERHIERARCHY_HPP

#include "TypeList.hpp"

template<class TList, template<class> Unit> class GenScatterHierarchy;

template<class T1, class T2, template<class> Unit>
class GenScatterHierarchy<TypeList<T1, T2>, Unit>
        : public GenScatterHierarchy<T1, Unit>
        ,public GenScatterHierarchy<T2, Unit>
{
public:
    typedef TypeList<T1, T2>    TList;
    typedef GenScatterHierarchy<T1, Unit>   LeftBase;
    typedef GenScatterHierarchy<T2, Unit>   RightBase;
};

template<typename AtomicType, template<class> Unit>
class GenScatterHierarchy
        : public Unit<AtomicType>
{
  public:
    typedef Unit<AtomicType>    LeftBase;
};

template<template<class> Unit>
class GenScatterHierarchy<NullType, Unit>
{
};

#endif // GENSCATTERHIERARCHY_HPP
