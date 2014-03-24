#include <ctime>
#include <errno.h>
#include "CoreLibrary/Mutex/linux/MutexLinux.h"
#include "CoreLibrary/Mutex/MutexException.h"

MutexLinux::MutexLinux()
{
  pthread_mutex_init(&_mutex, NULL);
}

MutexLinux::~MutexLinux()
{
}

void MutexLinux::lock()
{
    int error;
  
  error = pthread_mutex_lock(&_mutex);
  if (error == EINVAL)
    throw tekLib::MutexException("Error Mutex Lock");
}

void MutexLinux::unlock()
{
    int error;
  
  error = pthread_mutex_unlock(&_mutex);
  if (error == EINVAL)
    throw tekLib::MutexException("Error Mutex UnLock");
}

bool	MutexLinux::trylock(unsigned int time)
{
    int error;
  
  if (time == 0)
  {
    error = pthread_mutex_trylock(&_mutex);
  } 
  else
  {
    struct timespec time_struct;
    
    time_struct.tv_nsec = 0;
    time_struct.tv_sec = time;
    error = pthread_mutex_timedlock(&_mutex, &time_struct);
  }
  if (error == EINVAL)
    throw tekLib::MutexException("Error Mutex Trylock");
  else if (error == 0)
  {
    return (true);
  }
  return (false);
}
