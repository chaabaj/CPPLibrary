#ifndef THREADWINDOWS_H_
#define THREADWINDOWS_H_

#include <windows.h>
#include <windef.h>

#include "CoreLibrary/Thread/IThreadPlateform.h"
#include "CoreLibrary\DllExport.h"

class EXPORT_DLL ThreadWindows : public IThreadPlateform
{
public:
  ThreadWindows();
  virtual ~ThreadWindows();
  
  bool 	waitThread(long int);
  bool	startThread(ptr, void *);
  bool	isRunning() const;
  
private:
  HANDLE	_thread;
  
  void *_data;
  IThreadPlateform::ptr	_ptr;
  
  static DWORD WINAPI  proxy(LPVOID);
};

#endif