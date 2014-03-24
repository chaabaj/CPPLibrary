# include <iostream>

#include "CoreLibrary/Thread/AThread.hpp"
#include <CoreLibrary/FactoryPlateform/FactoryPlateform.h>

tekLib::AThread::AThread() : _sharedThreadInterface(::FactoryPlateform::createThreadPlateform())
{
  _isStarted = false;
}

tekLib::AThread::~AThread()
{
}

bool	tekLib::AThread::waitThread(long int timewait)
{
  if (!_isStarted)
    return (true);
  return (_sharedThreadInterface->waitThread(timewait));
}

void	tekLib::AThread::start()
{
  _isStarted = true;
  _sharedThreadInterface->startThread(&proxy, this);
}

bool	tekLib::AThread::isRunning() const
{
  return (_sharedThreadInterface->isRunning());
}

void tekLib::AThread::proxy(void *data)
{
  reinterpret_cast<AThread*>(data)->run();
}