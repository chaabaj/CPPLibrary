#ifndef CONVERSION_HPP
#define CONVERSION_HPP

# include "Type2Type.hpp"
# include "TypeList.hpp"
# include "TypeTraits.hpp"

template<typename T, typename U>
struct Conversion
{
    enum
    {
        exist = sizeof(T) >= sizeof(U),
        sameType = false
    };
};


template<typename T>
struct Conversion<T, T>
{
    enum { exist = true, sameType = true };
};

template<class Type, class TypeList> struct	InheritsOneOf;

template<class Type, class Head, class Tail>
struct	InheritsOneOf<Type, TypeList<Head, Tail> >
{
  static bool	inherits(typename TypeTraits<Type>::ParameterType val)
  {
    if (dynamic_cast<Head*>(&val) == NULL)
      return InheritsOneOf<Type, Tail>::inherits(val);
    return true;
  }
};

template<class Type, class U>
bool	inherits(typename TypeTraits<Type>::ParameterType val)
{
  if (dynamic_cast<U*>(&val) == NULL)
    return false;
  return true;
}

template<class Type, class Head>
struct InheritsOneOf<Type, TypeList<Head, NullType> >
{
  static bool	inherits(typename TypeTraits<Type>::ParameterType val)
  {
    if (dynamic_cast<Head*>(&val) == NULL)
      return false;
    return true;
  }
};

template<class Type, class TypeList> struct	InheritsOf;

template<class Type, class Head, class Tail>
struct InheritsOf<Type, TypeList<Head, Tail> >
{
  static bool inherits(typename TypeTraits<Type>::ParameterType val)
  {
    if (dynamic_cast<Head*>(&val) == NULL)
      return false;
    return InheritsOf<Type, Tail>::inherits(val);
  }
};

template<class Type, class Head>
struct InheritsOf<Type, TypeList<Head, NullType> >
{
  static bool inherits(typename TypeTraits<Type>::ParameterType val)
  {
    if (dynamic_cast<Head*>(&val) == NULL)
      return false;
    return true;
  }
};



#endif // CONVERSION_HPP
