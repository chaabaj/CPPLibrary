#ifndef REJECT_INVAlID_INDEX_HPP
# define REJECT_INVAlID_INDEX_HPP

#include <stdexcept>
#include "CoreLibrary/String/StringConverter.hpp"


/*!
 * \class RejectInvalidIndex RejectInvalidIndex.hpp
 * \tparam ContainerClass : the stl container class
 *
 * RejectInvalidIndex throw a exception if you pass a invalid index or iterator
 * This is used for safe container (no overflow can be happen with this policy)
 * The class is a policy (Search on google c++ policy design if you don't know what it is)
 */
template<class ContainerClass>
class RejectInvalidIndex
{
  typedef typename ContainerClass::iterator iterator;

public:

  /*!
   * \brief Static method to check the index
   *
   * \param container : the reference to the container
   * \param pos : the index in the container
   * \throws std::range_error if the index is invalid
   */
  static void	check(ContainerClass const &container, unsigned int pos)
  {
    if (pos >= container.size())
      throw std::range_error("Invalid index : " +  StringUtils::toString<unsigned int>(pos));
  }

  /*!
   * \brief Static method to check the index
   *
   * \param container : the reference to the container
   * \param pos : the iterator
   * \throws std::range_error if the iterator is invalid
   */
  static void	check(ContainerClass const &container, iterator pos)
  {
    if (pos >= container.end())
      throw std::range_error("Invalid iterator");
  }
};

#endif
