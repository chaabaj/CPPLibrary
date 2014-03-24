#ifndef REJECTNULL_HPP
# define REJECTNULL_HPP

#include <stdexcept>

template<typename PointerType>
class RejectNull
{
protected:
    RejectNull() {}
public:
  void	onDefault(PointerType const pointer) const
  {
    (void)pointer;
  }
  
  void onInit(PointerType const pointer) const
  {
    if (!pointer)
      throw std::runtime_error("Null pointer is not allowed");
  }
  
  void onDereference(PointerType const pointer) const
  {
    if (!pointer)
      throw std::runtime_error("Null pointer is not allowed");
  }
};

#endif
