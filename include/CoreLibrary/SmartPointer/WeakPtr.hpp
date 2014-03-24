#ifndef WEAK_PTR_HPP
# define WEAK_PTR_HPP

# include "CoreLibrary/SmartPointer/SmartPointer.hpp"
# include "CoreLibrary/Policies/SmartPointer/Checking/AssertCheck.hpp"
# include "CoreLibrary/Policies/SmartPointer/Storage/LockedStorage.hpp"
# include "CoreLibrary/Policies/SmartPointer/Storage/ArrayStorage.hpp"
# include "CoreLibrary/Policies/SmartPointer/Storage/DefaultStorage.hpp"
# include "CoreLibrary/Policies/SmartPointer/Ownership/Nothing.hpp"

template<typename T>
struct WeakPtrTypes
{
  typedef SmartPointer<T, DefaultStorage, Nothing, AssertCheck>	WeakPtr;
  typedef SmartPointer<T, ArrayStorage, Nothing, AssertCheck>		WeakPtrArray;
  typedef SmartPointer<T, DefaultStorage, Nothing, AssertCheck>	WeakPtrMT;
  typedef SmartPointer<T, ArrayStorage, Nothing, AssertCheck>		WeakPtrArrayMT;
};

#endif