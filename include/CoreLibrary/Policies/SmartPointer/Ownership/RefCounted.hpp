#ifndef REFCOUNTED_HPP
# define REFCOUNTED_HPP

#include <map>

template<typename PointerType>
class RefCounted
{
protected:
    ~RefCounted() {}
public:
  PointerType	clone(PointerType &val)
  {
    if (val != NULL)
      _refCounter[val]++;
    return val;
  }
  
  bool		release(PointerType val)
  {
    if (val != NULL && --_refCounter[val] == 0)
      return true;
    return false;
  }
  
protected:
  static std::map<PointerType, unsigned int>	_refCounter;
};

template<typename PointerType>
std::map<PointerType, unsigned int>	RefCounted<PointerType>::_refCounter;

#endif
