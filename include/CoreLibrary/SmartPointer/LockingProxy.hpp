#ifndef LOCKINGPROXY_HPP
# define LOCKINGPROXY_HPP

#include "CoreLibrary/Mutex/Mutex.h"

template<typename T>
class LockingProxy
{
  
public:
  typedef T*		PointerType;
public:
  explicit LockingProxy<T>(tekLib::Mutex &mutex, PointerType pointer) : _pointer(pointer), _mutex(mutex), _owner(true)
  {
    _mutex.lock();
  }
  
  ~LockingProxy<T>()
  {
    if (_owner == true)
      _mutex.unlock();
  }
  
  
  PointerType	operator->()
  {
    return _pointer;
  }
  
  LockingProxy<T>(LockingProxy<T> const &other) :  _pointer(other._pointer), _mutex(other._mutex), _owner(true)
  {
    const_cast<LockingProxy<T>&>(other)._owner = false;
  }
  
private:
  LockingProxy<T>	operator=(LockingProxy<T> const &other);
  
  PointerType		_pointer;
  tekLib::Mutex		&_mutex;
  bool			_owner;
};


#endif