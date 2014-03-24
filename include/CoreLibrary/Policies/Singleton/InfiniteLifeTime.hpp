#ifndef INFINITELIFETIME_HPP
#define INFINITELIFETIME_HPP

template<class T>
class InfiniteLifeTime
{
public:
    static void onDeadReference(void (*create)())
    {
        (void)create;
    }

    static void scheduleCall(void (*destroy)())
    {
        (void)destroy;
    }
};

#endif // INFINITELIFETIME_HPP
