#ifndef MULTITHREADED_HPP
#define MULTITHREADED_HPP

# include "CoreLibrary/Mutex/Mutex.h"
# include "CoreLibrary/Mutex/ScopedLock.h"
# include "CoreLibrary/SmartPointer/SharedPtr.hpp"
# include "CoreLibrary/SmartPointer/AutoPtr.hpp"
# include "CoreLibrary/SmartPointer/IntrusivePtr.hpp"
# include "CoreLibrary/SmartPointer/WeakPtr.hpp"
# include "CoreLibrary/Functor/Functor.hpp"
# include "CoreLibrary/Thread/ThreadFunctor.hpp"
# include <vector>


template<class T>
class MultiThreaded
{
public:
    typedef volatile T                                         VolatileType;
    typedef tekLib::Mutex                                      Mutex;
    typedef tekLib::ScopedLock                                 Lock;
    typedef typename SharedPtrTypes<T>::SharedArrayPtrMT       SharedArrayPtr;
    typedef typename SharedPtrTypes<T>::SharedPtrMT            SharedPtr;
    typedef typename AutoPtrTypes<T>::AutoPtrMT                AutoPtr;
    typedef typename AutoPtrTypes<T>::AutoPtrArrayMT           AutoPtrArray;
    typedef typename IntrusivePtrTypes<T>::IntrusiveArrayPtrMT IntrusiveArrayPtr;
    typedef typename IntrusivePtrTypes<T>::IntrusivePtrMT      IntrusivePtr;
    typedef typename WeakPtrTypes<T>::WeakPtrMT                WeakPtr;
    typedef typename WeakPtrTypes<T>::WeakPtrArrayMT           WeakPtrArray;


    template<class ThreadTask>
    void    launchTask(ThreadTask task)
    {
      static bool	firstPass;
      tekLib::AThread	*thread;
           
      thread = makeThread(task);
      thread->start();
      _threadLaunched.push_back(thread);
      if (!firstPass)
      {
	atexit(onProgramExit);
	firstPass = true;
      }
      MultiThreaded<T>::checkFinishedThread();
    }
    
private:
    static std::vector<tekLib::AThread*>	_threadLaunched;
    
    static void		checkFinishedThread()
    {
      std::vector<tekLib::AThread*>::iterator	it;
      
      for (it = _threadLaunched.begin(); it != _threadLaunched.end(); ++it)
      {
	if (!(*it)->isRunning())
	{
	  (*it)->waitThread();
	  delete (*it);
	  it = _threadLaunched.erase(it);
	}
      }
    }
    
    static void		onProgramExit()
    {
      std::vector<tekLib::AThread*>::iterator	it;
      
      for (it = _threadLaunched.begin(); it != _threadLaunched.end(); ++it)
      {
	(*it)->waitThread();
	delete (*it);
	it = _threadLaunched.erase(it);
      }
    }
};

template<class T>
std::vector<tekLib::AThread*>	MultiThreaded<T>::_threadLaunched;

#endif // MULTITHREADED_HPP
