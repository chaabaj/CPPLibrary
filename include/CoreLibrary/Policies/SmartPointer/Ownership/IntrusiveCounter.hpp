#ifndef INTRUSIVECOUNTER_HPP
# define INTRUSIVECOUNTER_HPP

template<typename PointerType>
class IntrusiveCounter
{
protected:
    ~IntrusiveCounter() {}

public:
  PointerType	clone(PointerType &val)
  {
    val->addRef();
    return val;
  }
  
  bool		release(PointerType val)
  {
    return val->delRef();
  }
};

#endif
