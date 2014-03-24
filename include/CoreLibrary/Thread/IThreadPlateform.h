#ifndef ITHREADPLATEFORM_H_
#define ITHREADPLATEFORM_H_

#include "CoreLibrary/DllExport.h"

class EXPORT_DLL IThreadPlateform
{
public:
  typedef void (*ptr)(void *);
  
  virtual ~IThreadPlateform()
  {
  }
  
  virtual bool 	waitThread(long int) = 0;
  virtual bool	startThread(ptr, void *) = 0;
  virtual bool	isRunning() const = 0;
};

#endif