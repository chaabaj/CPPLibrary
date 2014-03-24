#ifndef LOCKEDSTORAGE_HPP
# define LOCKEDSTORAGE_HPP

# include "CoreLibrary/Mutex/ScopedLock.h"
# include "CoreLibrary/SmartPointer/SmartPointer.hpp"
# include "CoreLibrary/Policies/SmartPointer/Ownership/RefCounted.hpp"
# include "CoreLibrary/Policies/SmartPointer/Checking/RejectNull.hpp"
# include "CoreLibrary/Policies/SmartPointer/Storage/DefaultStorage.hpp"
# include "CoreLibrary/SmartPointer/LockingProxy.hpp"

template<typename T>
class LockedStorage
{

  
public:
  typedef const T*		ReturnConstPointerType;
  typedef const T&		ReturnConstReferenceType;
  typedef LockingProxy<T>	ReturnPointerType;
  typedef T&			ReturnReferenceType;
  typedef T*			PointerType;

  
  LockedStorage<T>() : _data(NULL)
  {
    _mutex = MutexPtr(new tekLib::Mutex);
  }
  
  LockedStorage<T>(PointerType data)
  {
    _mutex = MutexPtr(new tekLib::Mutex);
    this->_data = data;
  }
  
  LockedStorage<T>(LockedStorage<T> const &other) : _mutex(other._mutex), _data(other._data)
  {
  }
  
  LockedStorage<T>	operator=(LockedStorage<T> const &other)
  {
    this->_data = other._data;
    this->_mutex = other._mutex;
    return *this;
  }
  
  ~LockedStorage<T>()
  {
  }
  
  ReturnConstPointerType	operator->() const
  {
    return _data;
  }
  
  ReturnConstReferenceType	operator*() const
  { 
    return (*_data);
  }
  
  ReturnPointerType	operator->()
  {
    return LockingProxy<T>(*_mutex, _data);
  }
  
  ReturnReferenceType operator*() 
  {
    return (*_data);
  }
  
protected:
  
  void	destroy()
  {
    delete _data;
  }
  
  typedef  SmartPointer<tekLib::Mutex, DefaultStorage, RefCounted, RejectNull>	MutexPtr;
  
  MutexPtr	_mutex;
  PointerType	_data;
};

#endif