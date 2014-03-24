#ifndef INTRUSIVECOUNTERMT_HPP
#define INTRUSIVECOUNTERMT_HPP

#include "CoreLibrary/Mutex/ScopedLock.h"
#include "CoreLibrary/Policies/SmartPointer/Ownership/IntrusiveCounter.hpp"

template<typename PointerType>
class IntrusiveCounterMT : public IntrusiveCounter<PointerType>
{
protected:
    ~IntrusiveCounterMT() {}

public:
  PointerType	clone(PointerType &val)
  {
    tekLib::ScopedLock(this->_mutex);
    return IntrusiveCounter<PointerType>::clone(val);
  }

  bool		release(PointerType val)
  {
    tekLib::ScopedLock(this->_mutex);
    return IntrusiveCounter<PointerType>::release(val);
  }

protected:
    tekLib::Mutex	_mutex;
};

#endif // INTRUSIVECOUNTERMT_HPP
