#ifndef SINGLETHREADED_HPP
#define SINGLETHREADED_HPP

#include "CoreLibrary/Type/NullType.hpp"

template<class T>
class SingleThreaded
{
public:
    typedef T           VolatileType;
    typedef NullType    Lock;

    static void lock(Lock &lock)
    {
        (void)lock;
    }

    static void unlock(Lock &lock)
    {
        (void)unlock;
    }
};

#endif // SINGLETHREADED_HPP
