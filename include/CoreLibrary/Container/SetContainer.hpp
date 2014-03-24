#ifndef SETCONTAINER_HPP
# define SETCONTAINER_HPP

# include <algorithm>
# include "CoreLibrary/Policies/ThreadingModel/SingleThreaded.hpp"
# include "CoreLibrary/Container/Policies/RejectInvalidIndex.hpp"

/*!
 * \class SetContainer
 * 
 * \brief Class for secure set container(set, multiset)
 * \tparam T : the value type
 * \tparam SetContainerClass : the container class to secure
 * \tparam ContainerCheckPolicy : The Checking policy by default it use RejectInvalidIndex policy
 * \tparam ThreadingModel : the threading model (SingleThreaded, MultiThreaded) by default it's SingleThreaded
 * \tparam Comparator : The comparator to use for the container by default it is std::less
 * \tparam Allocator : The allocator to use for the container by default it use std::allocator
 */

template<class T,
	 template<class, class, class> class	SetContainerClass,
	 template<class> class			ContainerCheckPolicy = RejectInvalidIndex,
	 template<class> class     		ThreadingModel = SingleThreaded,
	 template<class> class 			Comparator = std::less,
	 template<class> class 			Allocator = std::allocator>
class SetContainer : public SetContainerClass<T, Comparator<T>, Allocator<T> >
{
public:
  typedef typename SetContainerClass<T, Comparator<T>, Allocator<T> >::reference              reference;
  typedef typename SetContainerClass<T, Comparator<T>, Allocator<T> >::const_reference        const_reference;
  typedef typename SetContainerClass<T, Comparator<T>, Allocator<T> >::iterator               iterator;
  typedef typename SetContainerClass<T, Comparator<T>, Allocator<T> >::const_iterator	      	 const_iterator;
  typedef typename ThreadingModel<T>::Mutex                                			 Mutex;
  typedef typename ThreadingModel<T>::Lock                                 			 Lock;

  iterator	insert(iterator pos, const typename TypeTraits<T>::ParameterType p1)
  {
    Lock	lock(_mutex);
    
    ContainerCheckPolicy<SetContainerClass<T, Comparator<T>, Allocator<T> >::check(*this, pos);
    return SetContainerClass<T, Comparator<T>, Allocator<T> >::insert(pos, p1);
  }
  
  std::pair<iterator, bool>	insert(const typename TypeTraits<T>::ParameterType p1)
  {
    Lock	lock(_mutex);
    
    return SetContainerClass<T, Comparator<T>, Allocator<T> >::insert(p1);
  }
  
  template<class InputIterator>
  void		insert(InputIterator first, InputIterator last)
  {
    Lock	lock(_mutex);
    
    return SetContainerClass<T, Comparator<T>, Allocator<T> >::insert(first, last);
  }
  
  void		erase(iterator position)
  {
    Lock	lock(_mutex);
    
    return SetContainerClass<T, Comparator<T>, Allocator<T> >::erase(position);
  }
  
  void		erase(iterator first, iterator last)
  {
    Lock	lock(_mutex);
    
    return SetContainerClass<T, Comparator<T>, Allocator<T> >::erase(first, last);
  }
  
  std::size_t	erase(const T &val)
  {
    Lock	lock(_mutex);
    
    return SetContainerClass<T, Comparator<T>, Allocator<T> >::erase(val);
  }
  
private:
  Mutex		_mutex;
  
};
#endif