#ifndef DEFAULTLIFETIME_HPP
#define DEFAULTLIFETIME_HPP

#include <stdlib.h>
#include <stdexcept>

template<class T>
class DefaultLifeTime
{
public:

    static void onDeadReference(void (*create)())
    {
        throw std::runtime_error("Dead reference was found");
        (void)create;
    }

    static void scheduleCall(void (*destroy)())
    {
        atexit(destroy);
    }
};

#endif // DEFAULTLIFETIME_HPP
