#include <cstring>
#include <ctime>
#include <climits>
#include <cerrno>
#include "CoreLibrary/Thread/AThreadException.hpp"
#include "CoreLibrary/Thread/linux/ThreadLinux.h"

ThreadLinux::ThreadLinux()
{
  std::memset(&_thread, 0, sizeof(pthread_t));
}

ThreadLinux::~ThreadLinux()
{
}

bool 	ThreadLinux::waitThread(long int time)
{
  struct timespec       timed;
  int                   error;
  
  if (time == LONG_MAX)
  {
    error = pthread_join(_thread, NULL);
  }
  else
  {
    timed.tv_nsec = 0;
    timed.tv_sec = std::time(NULL) + time;
    error = pthread_timedjoin_np(_thread, NULL, &timed);
  }
  if (error != 0)
  {
    switch (error)
    {
      case ETIMEDOUT:
	return (false);
      default:
	throw tekLib::AThreadException(strerror(error));
    }
  }
  return (true);
}

bool	ThreadLinux::startThread(ptr pptr, void *data)
{
  _ptr = pptr;
  _data = data;
  int error = pthread_create(&_thread, NULL, &proxy, this);
  if (error != 0)
    throw tekLib::AThreadException(strerror(error));
}

bool	ThreadLinux::isRunning() const
{
  int error = pthread_tryjoin_np(_thread, NULL);
  if (error != 0)
  {
    switch (error)
    {
      case EBUSY:
	return (true);
      default:
	throw tekLib::AThreadException(strerror(error));
    }
  }
  return (false);
}

void *ThreadLinux::proxy(void *data)
{
  ThreadLinux *thread;
  
  thread = reinterpret_cast<ThreadLinux *>(data);
  
  thread->_ptr(thread->_data);
}