#ifndef ASSERTCHECKSTRICT_HPP
# define ASSERTCHECKSTRICT_HPP

#include "AssertCheck.hpp"

template<typename PointerType>
class AssertCheckStrict : public AssertCheck<PointerType>
{
protected:
    ~AssertCheckStrict() {}
public:
  void	onInit(PointerType pointer)
  {
    assert(pointer != NULL);
  }
};

#endif
