#ifndef DEFAULT_ERROR_HPP
# define DEFAULT_ERROR_HPP

#include "CoreLibrary/Type/TypeTraits.hpp"
#include <exception>
#include <stdexcept>

template<typename IdentifierType, class AbstractClass>
class DefaultError
{
public:
  static AbstractClass	*onUnknownId(typename TypeTraits<IdentifierType>::ParameterType parameter)
  {
    throw std::runtime_error("Cannot create a object of abstract class with unknow identifier" + parameter);
  }
};

#endif