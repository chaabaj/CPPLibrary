/*
 * 
 */

#include <string.h>
#include <cerrno>
#include <ctime>
#include "CoreLibrary/CondVar/CondVarException.hpp"
#include "CoreLibrary/CondVar/linux/CondVarLinux.h"


CondVarLinux::CondVarLinux() : MutexLinux()
{
  int error = pthread_cond_init(&_condVar, NULL);
  if (error != 0)
    throw tekLib::CondVarException(strerror(error));
}

CondVarLinux::~CondVarLinux()
{
  pthread_cond_destroy(&_condVar);
}

bool		CondVarLinux::wait(long int time)
{
  if (time == LONG_MAX)
  {
    int error = pthread_cond_wait(&_condVar, &this->_mutex);
    if (error != 0)
      throw tekLib::CondVarException("Wait CondVar Failed");
  }
  else
  {
    struct timespec	_time;
    
    _time.tv_nsec = 0;
    _time.tv_sec = time;
    int error = pthread_cond_timedwait(&_condVar, &this->_mutex, &_time);
    if (error != 0)
    {
      switch (error)
      {
	case ETIMEDOUT:
	  return (false);
	default:
	  throw tekLib::CondVarException("Error on condVar");
      }
    }
  }
}

void		CondVarLinux::signal()
{
  int error = pthread_cond_signal(&_condVar);
  if (error != 0)
    throw tekLib::CondVarException(strerror(error));
}

void		CondVarLinux::broadcast()
{
  int error = pthread_cond_broadcast(&_condVar);
  if (error != 0)
    throw tekLib::CondVarException(strerror(error));
}