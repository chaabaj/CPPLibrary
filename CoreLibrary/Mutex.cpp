
#ifdef __gnu_linux__
#include <cerrno>
#include <ctime>
#endif

#include "CoreLibrary/Mutex/Mutex.h"
#include "CoreLibrary/Mutex/MutexException.h"
#include <CoreLibrary/FactoryPlateform/FactoryPlateform.h>


tekLib::Mutex::Mutex(void) : _sharedMutexInterface(::FactoryPlateform::createMutexPlateform())
{
}

tekLib::Mutex::~Mutex(void)          /////// WHHHHHAAATTT !!!!!!
{
}

void tekLib::Mutex::lock() 
{
  _sharedMutexInterface->lock();
}

void tekLib::Mutex::unlock() 
{
  _sharedMutexInterface->unlock();
}

bool tekLib::Mutex::trylock(unsigned int time) 
{
  return (_sharedMutexInterface->trylock(time));
}