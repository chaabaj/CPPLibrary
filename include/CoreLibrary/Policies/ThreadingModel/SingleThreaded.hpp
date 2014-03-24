#ifndef SINGLETHREADED_HPP
#define SINGLETHREADED_HPP

#include "CoreLibrary/Type/NullType.hpp"
#include "CoreLibrary/SmartPointer/SharedPtr.hpp"
#include "CoreLibrary/SmartPointer/AutoPtr.hpp"
#include "CoreLibrary/SmartPointer/IntrusivePtr.hpp"
#include "CoreLibrary/SmartPointer/WeakPtr.hpp"
#include "CoreLibrary/Functor/Functor.hpp"

template<class T>
class SingleThreaded
{
public:
    typedef T                                                VolatileType;
    typedef NullType                                         Lock;
    typedef NullType                                         Mutex;
    typedef typename SharedPtrTypes<T>::SharedArrayPtr       SharedArrayPtr;
    typedef typename SharedPtrTypes<T>::SharedPtr            SharedPtr;
    typedef typename AutoPtrTypes<T>::AutoPtr                AutoPtr;
    typedef typename AutoPtrTypes<T>::AutoPtrArray           AutoPtrArray;
    typedef typename IntrusivePtrTypes<T>::IntrusiveArrayPtr IntrusiveArrayPtr;
    typedef typename IntrusivePtrTypes<T>::IntrusivePtr      IntrusivePtr;
    typedef typename WeakPtrTypes<T>::WeakPtr                WeakPtr;
    typedef typename WeakPtrTypes<T>::WeakPtrArray           WeakPtrArray;

    template<class ThreadTask>
    void    launchTask(ThreadTask task)
    {
        task();
    }
};

#endif // SINGLETHREADED_HPP
