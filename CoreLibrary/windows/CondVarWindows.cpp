#include "CoreLibrary/CondVar/windows/CondVarWindows.h"
#include "CoreLibrary/CondVar/CondVarException.hpp"

CondVarWindows::CondVarWindows() : MutexWindows()
{
  InitializeConditionVariable(&_condVar);
}

CondVarWindows::~CondVarWindows()
{
}

bool		CondVarWindows::wait(long int time)
{
  if (time == LONG_MAX)
  {
    int error = SleepConditionVariableCS(&_condVar, &this->_mutex, INFINITE);
    if (error != 0)
      throw tekLib::CondVarException("Wait CondVar Failed");
  }
  else
  {
    int error = SleepConditionVariableCS(&_condVar, &this->_mutex, time * 1000);
    if (error != 0)
    {
      switch (error)
      {
	case ERROR_TIMEOUT:
	  return (false);
	default:
	  throw tekLib::CondVarException("Error on condVar");
      }
    }
  }
  return (true);
}

void		CondVarWindows::signal()
{
}

void		CondVarWindows::broadcast()
{
}