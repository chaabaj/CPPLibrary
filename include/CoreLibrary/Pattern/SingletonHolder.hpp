#ifndef SINGLETONHOLDER_HPP
#define SINGLETONHOLDER_HPP

#include "CoreLibrary/Policies/Singleton/NewCreator.hpp"
#include "CoreLibrary/Policies/Singleton/DefaultLifeTime.hpp"
#include "CoreLibrary/Policies/ThreadingModel/SingleThreaded.hpp"

template<class T,
         template <class> class CreationPolicy = NewCreator,
         template <class> class LifeTimePolicy = DefaultLifeTime,
         template <class> class ThreadingModel = SingleThreaded>
class SingletonHolder
{

public:

    typedef typename ThreadingModel<T>::VolatileType InstanceType;

    static InstanceType &getInstance()
    {
        if (!_instance)
        {
            typename ThreadingModel<T>::Lock    lock(_mutex);
            if (!_instance)
            {
                if (_destroyed)
                {
                    LifeTimePolicy<T>::onDeadReference(create);
                    _destroyed = false;
                }
                create();
                LifeTimePolicy<T>::scheduleCall(destroySingleton);
            }
        }
        return (*_instance);
    }

private:
    SingletonHolder();
    ~SingletonHolder();
    SingletonHolder(SingletonHolder const &other);
    SingletonHolder &operator=(SingletonHolder const &other);

    typedef typename ThreadingModel<T>::Mutex   Mutex;

    static void destroySingleton()
    {

        CreationPolicy<T>::destroy(_instance);
        _instance = NULL;
        _destroyed = false;
    }



    static InstanceType         *_instance;
    static Mutex                _mutex;
    static bool                 _destroyed;

    static void         create()
    {
        _instance = CreationPolicy<T>::create();
    }

};

template<class T,
         template <class> class CreationPolicy,
         template <class> class LifeTimePolicy,
         template <class> class ThreadingModel>
bool    SingletonHolder<T,
                        CreationPolicy,
                        LifeTimePolicy,
                        ThreadingModel>::_destroyed = false;

template<class T,
         template <class> class CreationPolicy,
         template <class> class LifeTimePolicy,
         template <class> class ThreadingModel>

typename SingletonHolder<T,
                        CreationPolicy,
                        LifeTimePolicy,
                        ThreadingModel>::InstanceType*   SingletonHolder<T,
                                                                         CreationPolicy,
                                                                         LifeTimePolicy,
                                                                         ThreadingModel>::_instance = NULL;

#endif // SINGLETONHOLDER_HPP
