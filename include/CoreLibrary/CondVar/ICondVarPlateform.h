#ifndef ICONDVARPLATEFORM_H_
#define ICONDVARPLATEFORM_H_

#include "CoreLibrary/Mutex/IMutexPlateform.h"
#include "CoreLibrary/DllExport.h"

class EXPORT_DLL ICondVarPlateform
{
public:
  virtual ~ICondVarPlateform()
  {
  }
  
  virtual bool		wait(long int) = 0;
  virtual void		signal() = 0;
  virtual void		broadcast() = 0;
  virtual void		lock() = 0;
  virtual void		unlock() = 0;
  virtual bool		trylock(unsigned int) = 0;
};

#endif