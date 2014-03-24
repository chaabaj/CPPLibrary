#ifndef SAFE_CAST_HPP
# define SAFE_CAST_HPP

# include "CoreLibrary/Utils/StaticAssert.hpp"
# include "CoreLibrary/Type/TypeTraits.hpp"

template<typename From, typename To>
To	*safeReinterpretCast(From *parameter)
{
  STATIC_ASSERT(sizeof(To) <= sizeof(From), InvalidReinterpretCast)
  return reinterpret_cast<To*>(parameter);
}



#endif