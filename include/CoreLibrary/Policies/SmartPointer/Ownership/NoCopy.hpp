#ifndef NOCOPY_HPP
# define NOCOPY_HPP

template<typename PointerType>
class NoCopy
{
protected:
    ~NoCopy() {}
public:
  bool	release(PointerType pointer)
  {
    return true;
  }
};

#endif
