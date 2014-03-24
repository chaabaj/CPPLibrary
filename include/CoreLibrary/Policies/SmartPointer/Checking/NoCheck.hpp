#ifndef NOCHECK_HPP
# define NOCHECK_HPP

template<typename PointerType>
class NoCheck
{
protected:
    ~NoCheck() {}
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
      (void)pointer;
  }
};

#endif
