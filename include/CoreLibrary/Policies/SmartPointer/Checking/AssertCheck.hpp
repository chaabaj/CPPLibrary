#ifndef ASSERTCHECK_HPP
# define ASSERTCHECK_HPP

#include <cassert>

template<typename PointerType>
class AssertCheck
{
protected:
    ~AssertCheck() {}
public:
  void	onDefault(PointerType pointer) const
  {
    (void)pointer;
  }
  
  void onInit(PointerType pointer) const
  {
    (void)pointer;
  }
  
  void onDereference(PointerType pointer) const
  {
    assert(pointer != NULL);
  }
};

#endif
