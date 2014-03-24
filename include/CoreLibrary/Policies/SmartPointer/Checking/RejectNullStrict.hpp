#ifndef REJECTNULLSTRICT_HPP
# define REJECTNULLSTRICT_HPP

#include <stdexcept>

template<typename PointerType>
class RejectNullStrict
{
protected:
    ~RejectNullStrict() {}
public:
  void	onDefault(PointerType pointer) const
  {
    this->onInit();
  }
  
  void	onInit(PointerType pointer) const
  {
    if (!pointer)
      throw std::runtime_error("Null pointer is not allowed");
  }
  
  void	onDereference(PointerType pointer) const
  {
    this->onInit();
  }
};

#endif
