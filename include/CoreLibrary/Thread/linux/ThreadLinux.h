#ifndef THREADLINUX_H_
#define THREADLINUX_H_

#include <pthread.h>
#include "CoreLibrary/Thread/IThreadPlateform.h"

class ThreadLinux : public IThreadPlateform
{
public:
  
  ThreadLinux();
  virtual ~ThreadLinux();;
  
  bool 	waitThread(long int);
  bool	startThread(ptr, void *);
  bool	isRunning() const;
  
private:
  static void *proxy(void *data);
  
  
  IThreadPlateform::ptr	_ptr;
  void *_data;
  pthread_t		_thread;
};

#endif