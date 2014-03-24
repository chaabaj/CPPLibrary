#ifndef TYPETRAITS_HPP
#define TYPETRAITS_HPP

#include <string>
#include "TypeList.hpp"
#include "SelectType.hpp"
#include "CoreLibrary/Atomic/Atomic.h"

template<typename T, typename U>
struct isTypeOf
{
  static const bool 	result = false;
  typedef T		ResultType;
};

template<typename T>
struct isTypeOf<T, T>
{
  static const bool 	result = true;
  typedef T		ResultType;
};

template<typename T>
class TypeTraits
{
    template<class U>
    struct MemberFunctionTrait
    {
        static const bool       result = false;
        typedef NullType        MemberFunctionType;
    };


    template<class U, class V>
    struct MemberFunctionTrait<U V::*>
    {
        static const bool       result = true;
        typedef U               MemberFunctionType;
    };

    public:

    typedef TYPELIST_5(unsigned int, unsigned char,
                       unsigned short int,
		       unsigned long int,
		       unsigned long long int
		      ) UnsignedInts;
    typedef TYPELIST_3(double, float, long double)  Floats;

    typedef TYPELIST_1(bool) Boolean;

    typedef TYPELIST_5(int, char, short int, long int, long long int) SignedInts;

    typedef TYPELIST_7(tekLib::atomic_bool,
		       tekLib::atomic_char,
		       tekLib::atomic_int,
		       tekLib::atomic_short,
		       tekLib::atomic_long,
		       tekLib::atomic_llong,
		       tekLib::atomic_schar)	SignedAtomics;

    typedef TYPELIST_5(tekLib::atomic_uchar,
		       tekLib::atomic_uint,
		       tekLib::atomic_ushort,
		       tekLib::atomic_ulong,
		       tekLib::atomic_ullong)	UnsignedAtomics;

    enum { isSignedAtomic = TL::IndexOf<SignedAtomics, T>::value >= 0 };

    enum { isUnsignedAtomic = TL::IndexOf<UnsignedAtomics, T>::value >= 0 };

    enum { isAtomic = isSignedAtomic || isUnsignedAtomic };

    enum { isSignedInt = TL::IndexOf<SignedInts, T>::value >= 0 };

    enum { isUnsignedInt = TL::IndexOf<UnsignedInts, T>::value >= 0 };

    enum { isBoolean = TL::IndexOf<Boolean, T>::value >= 0 };

    enum { isFloat = TL::IndexOf<Floats, T>::value >= 0 };


    enum { isInteger = isSignedInt || isUnsignedInt };

    enum { isScalar = isInteger || isFloat };

    enum { isArith = isInteger || isFloat };
    
    enum { isMemberPointer = MemberFunctionTrait<T>::result };
    typedef typename MemberFunctionTrait<T>::MemberFunctionType    MemberFunctionType;

    enum { isPointer = isTypeOf<T, T*>::result };
    typedef typename isTypeOf<T, T*>::ResultType   PointerType;

    enum { isReference = isTypeOf<T, T&>::result };
    typedef typename isTypeOf<T, T&>::ResultType ReferenceType;
    
    enum { isConstReference = isTypeOf<T, const T&>::result };
    typedef typename isTypeOf<T, const T&>::ResultType  ConstReferenceType;

    enum { isConst = isTypeOf<T, const T>::result };
    typedef typename isTypeOf<T, const T>::ResultType ConstType;

    typedef typename SelectType<isPointer || isArith || isMemberPointer || isReference,
                                T, T&>::Result  ParameterType;

    typedef typename SelectType<isPointer || isArith || isMemberPointer || isReference,
				  const T, const T&>::Result  ConstParameterType;

};

#endif // TYPETRAITS_HPP
