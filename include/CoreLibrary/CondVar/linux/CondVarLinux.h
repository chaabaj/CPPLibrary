#ifndef CONDVARLINUX_H_
#define CONDVARLINUX_H_

#include <pthread.h>
#include <climits>

#include "CoreLibrary/CondVar/ICondVarPlateform.h"
#include "CoreLibrary/Mutex/linux/MutexLinux.h"

class CondVarLinux : public ICondVarPlateform, public MutexLinux
{
  typedef	pthread_cond_t	type;
  
public:
  CondVarLinux();
  virtual ~CondVarLinux();
  
  bool		wait(long int = LONG_MAX);
  void		signal();
  void		broadcast();
  void		lock()
  {
    MutexLinux::lock();
  }
  void		unlock()
  {
    MutexLinux::unlock();
  }
  bool		trylock(unsigned int time)
  {
    return (MutexLinux::trylock(time));
  }
  
private:
  type _condVar;
};

#endif