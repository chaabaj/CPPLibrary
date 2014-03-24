
#include "CoreLibrary/Thread/AThreadException.hpp"
#include "CoreLibrary/Thread/windows/ThreadWindows.h"

ThreadWindows::ThreadWindows()
{
  _thread = NULL;
}

ThreadWindows::~ThreadWindows()
{
  if (_thread)
    CloseHandle(_thread);
}

bool 	ThreadWindows::waitThread(long int time)
{
	DWORD error = WaitForMultipleObjects(1, &_thread, true, time == LONG_MAX ? INFINITE : time);
  if (error != 0)
  {
    switch (error)
    {
      case WAIT_TIMEOUT:
	return (false);
      default:
	throw tekLib::AThreadException("Wait Thread Failed");
    }
  }
  return (true);
}

bool	ThreadWindows::startThread(ptr pptr, void *data)
{
  _ptr = pptr;
  _data = data;
  if (!(_thread = CreateThread(NULL, 0, &proxy, this, 0, NULL)))
  {
    throw tekLib::AThreadException("Error Create Thread in Windows");
  }
  return (true);
}

bool	ThreadWindows::isRunning() const
{
  DWORD error = WaitForMultipleObjects(1, &_thread, true, 0);
  if (error != 0)
  {
    switch (error)
    {
      case WAIT_TIMEOUT:
	return (true);
      default:
	throw tekLib::AThreadException("Wait Thread Failed");
    }
  }
  return (false);
}

DWORD WINAPI  ThreadWindows::proxy(LPVOID data)
{
  ThreadWindows	*ptr;
  
  ptr = reinterpret_cast<ThreadWindows *>(data);
  ptr->_ptr(ptr->_data);
  return (0);
}