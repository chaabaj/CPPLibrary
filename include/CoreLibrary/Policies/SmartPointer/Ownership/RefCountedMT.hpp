#ifndef REFCOUNTEDMT_HPP
# define REFCOUNTEDMT_HPP

#include "RefCounted.hpp"
#include "CoreLibrary/Mutex/ScopedLock.h"

template<typename PointerType>
class RefCountedMT : public RefCounted<PointerType>
{
protected:
    ~RefCountedMT() {}
public:
  PointerType	clone(PointerType &val)
  {
    tekLib::ScopedLock(this->_mutex);
    return RefCounted<PointerType>::clone(val);
  }
  
  bool		release(PointerType val)
  {
    tekLib::ScopedLock(this->_mutex);
    return RefCounted<PointerType>::release(val);
  }
  
private:
  tekLib::Mutex	_mutex;
};

#endif
