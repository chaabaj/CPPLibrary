#ifndef ATHREAD_HPP_
#define ATHREAD_HPP_

#include <climits>

#include "CoreLibrary/Thread/IThreadPlateform.h"
#include "CoreLibrary/SmartPointer/SmartPointer.hpp"
#include "CoreLibrary/Policies/SmartPointer/Checking/AssertCheck.hpp"
#include "CoreLibrary/Policies/SmartPointer/Ownership/RefCounted.hpp"
#include "CoreLibrary/Policies/SmartPointer/Storage/DefaultStorage.hpp"

#include "CoreLibrary/DllExport.h"

namespace tekLib
{
  
  class EXPORT_DLL AThread
  {
  public:
    AThread();
    virtual ~AThread();
    
    bool	waitThread(long int = LONG_MAX);
    
    virtual void	run() = 0;
    
    bool		isRunning() const;
    void		start();
    static void proxy(void *data);
  private:
    bool			_isStarted;
    ::SmartPointer<IThreadPlateform, DefaultStorage, RefCounted, AssertCheck>	_sharedThreadInterface;
  };
  
}

#endif