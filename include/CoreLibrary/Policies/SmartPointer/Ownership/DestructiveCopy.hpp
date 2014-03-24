#ifndef DESTRUCTIVECOPY_HPP
# define DESTRUCTIVECOPY_HPP

template<class PointerType>
class DestructiveCopy
{
protected:
    ~DestructiveCopy() {}
public:
  PointerType	clone(PointerType &val)
  {
    PointerType	result;
    
    result = val;
    val = NULL;
    return (result);
  }
  
  bool	release(PointerType val)
  {
    if (val != NULL)
      return true;
    return false;
  }
  
  enum { destructiveCopy = true };
};

#endif
