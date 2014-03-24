/*
 * 
 */

#include "CoreLibrary/FactoryPlateform/FactoryPlateform.h"

#ifdef _WIN32
# include "CoreLibrary/Mutex/windows/MutexWindows.h"
# include "CoreLibrary/CondVar/windows/CondVarWindows.h"
#include "CoreLibrary/Thread/windows/ThreadWindows.h"
#else
# include "CoreLibrary/Mutex/linux/MutexLinux.h"
# include "CoreLibrary/CondVar/linux/CondVarLinux.h"
#include "CoreLibrary/Thread/linux/ThreadLinux.h"
#endif


IMutexPlateform		*FactoryPlateform::createMutexPlateform()
{
  #ifdef _WIN32
  return (new MutexWindows());
  #else
  return (new MutexLinux());
  #endif
}

ICondVarPlateform	*FactoryPlateform::createCondVarPlateform()
{
  #ifdef _WIN32
  return (new CondVarWindows());
  #else
  return (new CondVarLinux());
  #endif
}

IThreadPlateform	*FactoryPlateform::createThreadPlateform()
{
  #ifdef _WIN32
  return (new ThreadWindows());
  #else
  return (new ThreadLinux());
  #endif
}
