#pragma once

#include <climits>

#include "CoreLibrary/FactoryPlateform/FactoryPlateform.h"
#include "CoreLibrary/SmartPointer/SmartPointer.hpp"
#include "CoreLibrary/Policies/SmartPointer/Checking/AssertCheck.hpp"
#include "CoreLibrary/Policies/SmartPointer/Ownership/RefCounted.hpp"
#include "CoreLibrary/Policies/SmartPointer/Storage/DefaultStorage.hpp"
#include "CoreLibrary/DllExport.h"

namespace tekLib
{
  
	class EXPORT_DLL CondVar
  {
  public:
    CondVar();
    ~CondVar();
    
    bool	wait(long int = LONG_MAX);
    void	signal();
    void	broadcast();
    void 	lock();
    void 	unlock();
  private:
    ::SmartPointer<ICondVarPlateform, DefaultStorage, RefCounted, AssertCheck>	_sharedCondVarInterface;
    
  };
}
