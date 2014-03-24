#ifndef AUTO_PTR_HPP
# define AUTO_PTR_HPP

# include "CoreLibrary/SmartPointer/SmartPointer.hpp"
# include "CoreLibrary/Policies/SmartPointer/Checking/AssertCheck.hpp"
# include "CoreLibrary/Policies/SmartPointer/Ownership/DestructiveCopy.hpp"
# include "CoreLibrary/Policies/SmartPointer/Storage/LockedStorage.hpp"
# include "CoreLibrary/Policies/SmartPointer/Storage/ArrayStorage.hpp"
# include "CoreLibrary/Policies/SmartPointer/Storage/DefaultStorage.hpp"

template<typename T>
struct AutoPtrTypes
{
  typedef SmartPointer<T, DefaultStorage, DestructiveCopy, AssertCheck>	AutoPtr;
  typedef SmartPointer<T, ArrayStorage, DestructiveCopy, AssertCheck>		AutoPtrArray;
  typedef SmartPointer<T, LockedStorage, DestructiveCopy, AssertCheck>	AutoPtrMT;
  typedef SmartPointer<T, ArrayStorage, DestructiveCopy, AssertCheck>	AutoPtrArrayMT;
};

#endif