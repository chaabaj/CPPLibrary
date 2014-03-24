#ifndef PHOENIXSINGLETON_HPP
#define PHOENIXSINGLETON_HPP

#include <cstdlib>

template<class T>
class PhoenixSingleton
{
public:
    static void onDeadReference(void (*create)())
    {
        create();
    }

    static void scheduleCall(void (*destroy)())
    {
        atexit(destroy);
    }
};

#endif // PHOENIXSINGLETON_HPP
