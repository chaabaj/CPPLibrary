#ifndef NO_CHECK_HPP
# define NO_CHECK_HPP


/*!
 * \class NoCheck NoCheck.hpp
 * \tparam ContainerClass : the stl container class
 * 
 * NoCheck don't check anything it use for unsafe and performance issue
 * The class is a policy (Search on google c++ policy design if you don't know what it is)
 */
template<class ContainerClass>
class NoCheck
{
  typedef typename ContainerClass::iterator	iterator;
  
public:
  
  
  /*!
   * \brief Static method to check a valid index of container
   * 
   * \param container : the reference to the container
   * \param index : the index to check (it used to test it is a valid index)
   */
  static void	check(ContainerClass &container, unsigned int index)
  {
  }
  
  /*!
   * \brief Static method to check a valid iterator of container
   * 
   * \param container : the reference to the container
   * \param pos : the iterator to check (it used to test it is a valid iterator)
   */
  static void	check(ContainerClass &container, iterator pos)
  {
  }
};

#endif