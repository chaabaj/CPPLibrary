#include "CoreLibrary/CondVar/CondVar.hpp"
#include "CoreLibrary/CondVar/CondVarException.hpp"

tekLib::CondVar::CondVar() : _sharedCondVarInterface(::FactoryPlateform::createCondVarPlateform())
{
}

bool	tekLib::CondVar::wait(long int time)
{
	return (_sharedCondVarInterface->wait(time));
}

void	tekLib::CondVar::signal()
{
  _sharedCondVarInterface->signal();
}

void	tekLib::CondVar::broadcast()
{
  _sharedCondVarInterface->broadcast();
}

void 	tekLib::CondVar::lock()
{
  _sharedCondVarInterface->lock();
}

void 	tekLib::CondVar::unlock()
{
  _sharedCondVarInterface->unlock();
}