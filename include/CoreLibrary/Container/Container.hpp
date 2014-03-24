#ifndef CONTAINER_HPP
# define CONTAINER_HPP

# include <vector>
# include "CoreLibrary/Container/Policies/RejectInvalidIndex.hpp"
# include "CoreLibrary/Policies/ThreadingModel/SingleThreaded.hpp"

/*!
 * \class Container
 * 
 * \brief
 * Container class 
 * \tparam T : the type to register into the container
 * \tparam ContainerCheckPolicy : a check policy class by default it use RejectInvalidIndex policy class
 * \tparam ThreadingModel : a threading model(ex : SingleThreaded, MultiThreaded) by default it use SingleThreaded class
 * \tparam Allocator : a allocator to use for the container by default it use std::allocator
 */
template< 
	  class T,
	  template<class, class> class ContainerClass,
	  template<class> class 	ContainerCheckPolicy = RejectInvalidIndex,
	  template<class> class     	ThreadingModel = SingleThreaded,
	  template<class> class		Allocator = std::allocator
	 >
class Container : public ContainerClass<T, std::allocator<T> >
{
public:

  typedef typename ContainerClass<T, Allocator<T> >::reference              reference;
  typedef typename ContainerClass<T, Allocator<T> >::const_reference        const_reference;
  typedef typename ContainerClass<T, Allocator<T> >::iterator               iterator;
  typedef typename ContainerClass<T, Allocator<T> >::const_iterator	    const_iterator;
  typedef typename ThreadingModel<T>::Mutex                                 Mutex;
  typedef typename ThreadingModel<T>::Lock                                  Lock;
  
  reference	operator[](unsigned int index)
  {

    ContainerCheckPolicy<ContainerClass<T, Allocator<T> > >::check(*this, index);
    return ContainerClass<T, Allocator<T> >::operator[](index);
  }
  
  const_reference	operator[](unsigned int index) const
  {
    ContainerCheckPolicy<ContainerClass<T, Allocator<T> > >::check(*this, index);
    return ContainerClass<T, Allocator<T> >::operator[](index);
  }
  
  reference	at(unsigned int index)
  {
    ContainerCheckPolicy<ContainerClass<T, Allocator<T> > >::check(*this, index);
    return ContainerClass<T, Allocator<T> >::at(index);
  }
  
  const_reference	at(unsigned int index) const
  {
    ContainerCheckPolicy<ContainerClass<T, Allocator<T> > >::check(*this, index);
    return ContainerClass<T, Allocator<T> >::at(index);
  }
  
  iterator		erase(iterator pos)
  {
    Lock        lock(_mutex);

    ContainerCheckPolicy<ContainerClass<T, Allocator<T> > >::check(*this, pos);
    return ContainerClass<T, Allocator<T> >::erase(pos);
  }

  iterator      erase(iterator pos, iterator last)
  {
      Lock        lock(_mutex);

      ContainerCheckPolicy<ContainerClass<T, Allocator<T> > >::check(*this, pos);
      return ContainerClass<T, Allocator<T> >::erase(pos, last);
  }

  void          swap(ContainerClass<T, Allocator<T> > &container)
  {
      Lock      lock(_mutex);

      return ContainerClass<T, Allocator<T> >::swap(container);
  }

  void          clear()
  {
      Lock      lock(_mutex);

      return ContainerClass<T, Allocator<T> >::clear();
  }

protected:
  Mutex     _mutex;
};
#endif
