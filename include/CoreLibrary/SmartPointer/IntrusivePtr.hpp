#ifndef INTRUSIVEPTR_HPP
# define INTRUSIVEPTR_HPP

# include "CoreLibrary/SmartPointer/SmartPointer.hpp"
# include "CoreLibrary/Policies/SmartPointer/Checking/AssertCheck.hpp"
# include "CoreLibrary/Policies/SmartPointer/Ownership/IntrusiveCounter.hpp"
# include "CoreLibrary/Policies/SmartPointer/Storage/LockedStorage.hpp"
# include "CoreLibrary/Policies/SmartPointer/Storage/ArrayStorage.hpp"
# include "CoreLibrary/Policies/SmartPointer/Storage/DefaultStorage.hpp"
# include "CoreLibrary/Policies/SmartPointer/Ownership/IntrusiveCounterMT.hpp"

template<typename T>
struct IntrusivePtrTypes
{
  typedef SmartPointer<T, DefaultStorage, IntrusiveCounter, AssertCheck>	        IntrusivePtr;
  typedef SmartPointer<T, ArrayStorage, IntrusiveCounter, AssertCheck>			IntrusiveArrayPtr;
  typedef SmartPointer<T, LockedStorage, IntrusiveCounterMT, AssertCheck>		IntrusivePtrMT;
  typedef SmartPointer<T, ArrayStorage, IntrusiveCounterMT, AssertCheck>		IntrusiveArrayPtrMT;
};



#endif
