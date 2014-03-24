#ifndef REJECTNULLSTATIC_HPP
# define REJECTNULLSTATIC_HPP

#include <stdexcept>
#include "RejectNullStrict.hpp"

template<typename PointerType>
class RejectNullStatic : public RejectNullStrict<PointerType>
{
protected:
    ~RejectNullStatic() {}
private:
  void	onDefault(PointerType pointer);
};


#endif
