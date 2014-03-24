#ifndef UNIQUE_PTR_HPP
# define UNIQUE_PTR_HPP

# include "CoreLibrary/Policies/SmartPointer/Checking/AssertCheck.hpp"
# include "CoreLibrary/Policies/SmartPointer/Storage/DefaultStorage.hpp"
# include "CoreLibrary/Policies/SmartPointer/Storage/ArrayStorage.hpp"
# include "CoreLibrary/Policies/SmartPointer/Storage/LockedStorage.hpp"
# include "CoreLibrary/Policies/SmartPointer/Ownership/NoCopy.hpp"
# include "CoreLibrary/SmartPointer/SmartPointer.hpp"

template<typename T, template<class> class CheckPolicy = AssertCheck>
struct UniquePtrTypes
{
  typedef SmartPointer<T, DefaultStorage, NoCopy, CheckPolicy>	UniquePtr;
  typedef SmartPointer<T, ArrayStorage, NoCopy, CheckPolicy>		UniqueArrayPtr;
  typedef SmartPointer<T, LockedStorage, NoCopy, CheckPolicy>		UniquePtrMT;
  typedef SmartPointer<T, ArrayStorage, NoCopy, CheckPolicy>		UniqueArrayPtrMT;
};

#endif