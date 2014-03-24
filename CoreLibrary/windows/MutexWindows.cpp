#include "CoreLibrary/Mutex/windows/MutexWindows.h"

MutexWindows::MutexWindows()
{
  InitializeCriticalSection(&_mutex);
}

MutexWindows::~MutexWindows()
{
  DeleteCriticalSection(&_mutex);
}

void MutexWindows::lock()
{
  EnterCriticalSection(&_mutex);
}

void MutexWindows::unlock()
{
  LeaveCriticalSection(&_mutex);
}

bool	MutexWindows::trylock(unsigned int time)
{
  (void)time;
  return static_cast<bool>(TryEnterCriticalSection(&_mutex));
}