#ifndef MUTEXLINUX_H__
#define MUTEXLINUX_H__

#include "CoreLibrary/Mutex/IMutexPlateform.h"

#include <pthread.h>

class MutexLinux : public IMutexPlateform
{
public:
   typedef	pthread_mutex_t	type;
  
public:
  MutexLinux();
  virtual ~MutexLinux();
  void lock();
  void unlock();
  bool trylock(unsigned int time = 0);
  
  type	getMutexType()
  {
    return _mutex;
  }
  
private:
  MutexLinux(const MutexLinux &) {}
  const MutexLinux & operator= (const MutexLinux &)
  {
    return *this;
  }
  
protected:
  type		_mutex;
};

#endif