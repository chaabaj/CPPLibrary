/*
 * 
 */

#ifndef FACTORYPLATEFORM_H
#define FACTORYPLATEFORM_H

#include "CoreLibrary/CondVar/ICondVarPlateform.h"
#include "CoreLibrary/Thread/IThreadPlateform.h"
#include "CoreLibrary/DllExport.h"

class EXPORT_DLL FactoryPlateform
{
  public:
    static IMutexPlateform		*createMutexPlateform();
    static ICondVarPlateform		*createCondVarPlateform();
    static IThreadPlateform		*createThreadPlateform();
  
};

#endif // FACTORYPLATEFORM_H
