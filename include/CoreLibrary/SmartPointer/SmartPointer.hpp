#pragma once

#include <stdexcept>

#include "CoreLibrary/DllExport.h"

template<typename T,
	 template<class> class StoragePolicy,
	 template<class> class OwnershipPolicy,
	 template<class> class CheckingPolicy,
	 bool allowImplicitConversion = true>
class EXPORT_DLL SmartPointer : public StoragePolicy<T>,
			private OwnershipPolicy<T*>,
			private CheckingPolicy<T*>
{

public:
  typedef SmartPointer<T, StoragePolicy, OwnershipPolicy, CheckingPolicy, allowImplicitConversion>	SmartPointerType;

  typedef typename StoragePolicy<T>::ReturnPointerType      	ReturnPointerType;
  typedef typename StoragePolicy<T>::ReturnReferenceType	ReturnReferenceType;
  typedef typename StoragePolicy<T>::ReturnConstPointerType	ReturnConstPointerType;
  typedef typename StoragePolicy<T>::ReturnConstReferenceType	ReturnConstReferenceType;
  typedef T							StorageType;

  enum { hasImplicitConversion = allowImplicitConversion };

  SmartPointer<T, StoragePolicy, OwnershipPolicy, CheckingPolicy, allowImplicitConversion>() : StoragePolicy<T>(),
  OwnershipPolicy<T*>(), CheckingPolicy<T*>()
  {
    this->onDefault(this->_data);
  }

  SmartPointer<T, StoragePolicy, OwnershipPolicy, CheckingPolicy, allowImplicitConversion>(typename StoragePolicy<T>::PointerType data) : StoragePolicy<T>(data),
  OwnershipPolicy<T*>(), CheckingPolicy<T*>()
  {
    this->onInit(this->_data);
    this->clone(this->_data);
  }

  SmartPointer<T, StoragePolicy, OwnershipPolicy, CheckingPolicy, allowImplicitConversion>(SmartPointerType const &other) : StoragePolicy<T>(other), OwnershipPolicy<T*>(), CheckingPolicy<T*>()
  {
    this->onInit(this->_data);
    this->clone(this->_data);
  }

  SmartPointerType	&operator=(SmartPointerType const &other)
  {

    this->_data = other._data;
    this->onInit(this->_data);
    this->clone(this->_data);
    return (*this);
  }

  ~SmartPointer<T, StoragePolicy, OwnershipPolicy, CheckingPolicy, allowImplicitConversion>()
  {
    if (this->release(this->_data))
      this->destroy();
  }

  bool	operator==(SmartPointerType const &other) const
  {
    return this->_data == other._data;
  }

  bool	operator==(typename StoragePolicy<T>::PointerType pointer) const
  {
    return this->_data == pointer;
  }

  template<typename U>
  bool	operator==(U *pointer) const
  {
    return this->_data == pointer;
  }

  bool	operator>(SmartPointerType const &other) const
  {
    return this->_data = other._data;
  }

  bool	operator>(typename StoragePolicy<T>::PointerType pointer) const
  {
    return this->_data > pointer;
  }

  template<typename U>
  bool	operator>(U *pointer) const
  {
    return this->_data > pointer;
  }

  bool operator>=(SmartPointerType const &other) const
  {
    return this->_data >= other._data;
  }

  bool	operator>=(typename StoragePolicy<T>::PointerType pointer) const
  {
    return this->_data >= pointer;
  }

  template<typename U>
  bool	operator>=(U *pointer) const
  {
    return this->_data >= pointer;
  }

  bool operator<(SmartPointerType const &other) const
  {
    return this->_data < other._data;
  }

  bool	operator<(typename StoragePolicy<T>::PointerType pointer) const
  {
    return this->_data < pointer;
  }

  template<typename U>
  bool	operator<(U *pointer) const
  {
    return this->_data < pointer;
  }

  bool	operator<=(SmartPointerType const &other) const
  {
    return this->_data <= other._data;
  }

  bool	operator<=(typename StoragePolicy<T>::PointerType pointer) const
  {
    return this->_data <= pointer;
  }

  template<typename U>
  bool	operator<=(U *pointer) const
  {
    return this->_data <= pointer;
  }

  bool	operator!=(SmartPointerType const &other) const
  {
    return this->_data != other._data;
  }

  bool	operator!=(typename StoragePolicy<T>::PointerType pointer) const
  {
    return this->_data != pointer;
  }

  template<typename U>
  bool	operator!=(U *pointer) const
  {
    return this->_data != pointer;
  }

  bool	operator!() const
  {
    return !this->_data;
  }

  ReturnConstPointerType get() const
  {
      this->onDereference(this->_data);
      return StoragePolicy<T>::operator->();
  }

  operator T*()
  {
    if (allowImplicitConversion == true)
    {
      this->onDereference(this->_data);
      return this->_data;
    }
    throw std::runtime_error("Implicit conversion is not allowed");
  }

  operator const T*() const
  {
    if (allowImplicitConversion == true)
    {
      this->onDereference(this->_data);
      return this->_data;
    }
    throw std::runtime_error("Implicit conversion is not allowed");
  }

  ReturnPointerType		get()
  {
    this->onDereference(this->_data);
    return StoragePolicy<T>::operator->();
  }

  ReturnConstPointerType	operator->() const
  {
    this->onDereference(this->_data);
    return StoragePolicy<T>::operator->();
  }

  ReturnConstReferenceType	operator*() const
  {
    this->onDereference(this->_data);
    return StoragePolicy<T>::operator*();
  }

  ReturnPointerType	operator->()
  {
    this->onDereference(this->_data);
    return StoragePolicy<T>::operator->();
  }

  ReturnReferenceType	operator*()
  {
    this->onDereference(this->_data);
    return StoragePolicy<T>::operator*();
  }
};

