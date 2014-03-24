#ifndef MUTEXWINDOWS_H__
#define MUTEXWINDOWS_H__

# define WIN32_LEAN_AND_MEAN
# include <windows.h>

#include "CoreLibrary/Mutex/IMutexPlateform.h"
#include "CoreLibrary\DllExport.h"

class EXPORT_DLL MutexWindows : public IMutexPlateform
{
  typedef 	CRITICAL_SECTION		type;
  
public:
  MutexWindows();
  virtual ~MutexWindows();
  void lock();
  void unlock();
  bool trylock(unsigned int time = 0);
  
  type	getMutexType()
  {
    return _mutex;
  }
  
private:
  MutexWindows(const MutexWindows &) {}
  const MutexWindows & operator= (const MutexWindows &)
  {
    return *this;
  }
  
protected:
  type	_mutex;
};

#endif