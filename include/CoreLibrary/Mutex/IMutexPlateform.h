#ifndef IMUTEXPLATEFORM_H__
#define IMUTEXPLATEFORM_H__

#include "CoreLibrary/DllExport.h"

class EXPORT_DLL IMutexPlateform
{
public:
  virtual ~IMutexPlateform()
  {
  }
  virtual void lock() = 0;
  virtual void unlock() = 0;
  virtual bool trylock(unsigned int) = 0;
};

#endif