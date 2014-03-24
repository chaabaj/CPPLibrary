#ifndef SHAREDPTR_HPP
# define SHAREDPTR_HPP

# include "SmartPointer.hpp"
# include "CoreLibrary/Policies/SmartPointer/Checking/AssertCheck.hpp"
# include "CoreLibrary/Policies/SmartPointer/Ownership/RefCounted.hpp"
# include "CoreLibrary/Policies/SmartPointer/Ownership/RefCountedMT.hpp"
# include "CoreLibrary/Policies/SmartPointer/Storage/DefaultStorage.hpp"
# include "CoreLibrary/Policies/SmartPointer/Storage/ArrayStorage.hpp"
# include "CoreLibrary/Policies/SmartPointer/Storage/LockedStorage.hpp"

template<typename T>
struct SharedPtrTypes
{
  typedef SmartPointer<T, DefaultStorage, RefCounted, AssertCheck>		SharedPtr;
  typedef SmartPointer<T, LockedStorage, RefCountedMT, AssertCheck>		SharedPtrMT;
  typedef SmartPointer<T, ArrayStorage, RefCounted, AssertCheck>		SharedArrayPtr;
  typedef SmartPointer<T, ArrayStorage, RefCountedMT, AssertCheck>		SharedArrayPtrMT;
};

template<typename T>
typename SharedPtrTypes<T>::SharedPtr	makeSharedPtr(T *ptr = NULL)
{
  return SharedPtrTypes<T>::SharedPtr(ptr);
}

template<typename T>
typename SharedPtrTypes<T>::SharedPtrMT	makeSharedMTPtr(T *ptr = NULL)
{
  return SharedPtrTypes<T>::SharedPtrMT(ptr);
}

template<typename T>
typename SharedPtrTypes<T>::SharedArrayPtr	makeSharedArrayPtr(T *ptr = NULL)
{
  return SharedPtrTypes<T>::SharedArrayPtr(ptr);
}

template<typename T>
typename SharedPtrTypes<T>::SharedArrayPtrMT	makeSharedArrayMTPtr(T *ptr = NULL)
{
  return SharedPtrTypes<T>::SharedArrayPtrMT(ptr);
}

#endif