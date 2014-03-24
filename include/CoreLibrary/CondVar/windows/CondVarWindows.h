/*
 *
*/

#ifndef CONDVARWINDOWS_H_
#define CONDVARWINDOWS_H_

#include <climits>
#include <windows.h>

#include "CoreLibrary/CondVar/ICondVarPlateform.h"
#include "CoreLibrary/Mutex/windows/MutexWindows.h"
#include "CoreLibrary/DllExport.h"

class EXPORT_DLL CondVarWindows : public ICondVarPlateform, public MutexWindows
{
  typedef	CONDITION_VARIABLE		type;
  
public:
  CondVarWindows();
  virtual ~CondVarWindows();
  
  bool		wait(long int = LONG_MAX);
  void		signal();
  void		broadcast();
  void		lock()
  {
	  MutexWindows::lock();
  }
  void		unlock()
  {
	  MutexWindows::unlock();
  }
  bool		trylock(unsigned int time)
  {
	  return (MutexWindows::trylock(time));
  }

private:
  type 		_condVar;
};

#endif