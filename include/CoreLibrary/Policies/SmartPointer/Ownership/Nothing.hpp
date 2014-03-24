#ifndef NOTHING_HPP
# define NOTHING_HPP

template<typename PointerType>
class Nothing
{
protected:
    ~Nothing() {}
public:
  PointerType	clone(PointerType &pointer)
  {
    return pointer;
  }
  
  bool		release(PointerType pointer)
  {
      (void)pointer;
      return false;
  }
};

#endif
