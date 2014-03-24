#ifndef SEARCH_MOST_DERIVATED_HPP_
# define SEARCH_MOST_DERIVATED_HPP_

# include "CoreLibrary/Type/Conversion.hpp"
# include "CoreLibrary/Type/TypeInfo.hpp"
# include "CoreLibrary/Type/Type2Type.hpp"

template<class Type, class TypeList> struct SearchMostDerivated;

template<class Type, typename Head, typename Tail>
struct SearchMostDerivated<Type, TypeList<Head, Tail> >
{
  static TypeInfo	find(Type &value, std::size_t size, bool found)
  {
    Head	*tmp;
    
    tmp = dynamic_cast<Head*>(&value);
    if (tmp == NULL)
      return SearchMostDerivated<Type, Tail>::find(value, size, found);
    else if (sizeof(Head) > size)
    {
      size = sizeof(Head);
      return SearchMostDerivated<Head, Tail>::find(*tmp, sizeof(Head), true);
    }
    return SearchMostDerivated<Type, Tail>::find(value, size, true);
  }
};

template<class Type>
struct SearchMostDerivated<Type, NullType>
{
  static TypeInfo	find(Type &value, std::size_t size, bool found)
  {
    (void)size;
    if (found == false)
      return TypeInfo(typeid(NullType()));
    return TypeInfo(typeid(value));
  }
};

#endif