#ifndef TYPELIST_HPP
#define TYPELIST_HPP

#include "NullType.hpp"

template<class T, class U>
struct TypeList
{
    typedef T   Head;
    typedef U   Tail;
};

//Use Theses macros for msvc compatibility

#define TYPELIST_1(T1)  TypeList<T1, NullType>
#define TYPELIST_2(T1, T2) TypeList<T1, TYPELIST_1(T2) >
#define TYPELIST_3(T1, T2, T3) TypeList<T1, TYPELIST_2(T2, T3) >
#define TYPELIST_4(T1, T2, T3, T4) TypeList<T1, TYPELIST_3(T2, T3, T4) >
#define TYPELIST_5(T1, T2, T3, T4, T5) TypeList<T1, TYPELIST_4(T2, T3, T4, T5) >
#define TYPELIST_6(T1, T2, T3, T4, T5, T6) TypeList<T1, TYPELIST_5(T2, T3, T4, T5, T6) >
#define TYPELIST_7(T1, T2, T3, T4, T5, T6, T7) TypeList<T1, TYPELIST_6(T2, T3, T4, T5, T6, T7) >
#define TYPELIST_8(T1, T2, T3, T4, T5, T6, T7, T8) TypeList<T1, TYPELIST_7(T2, T3, T4, T5, T6, T7) >



namespace TL
{	
    template<class TList> struct Length;

    template <>
    struct Length<NullType>
    {
        enum { value = 0 };
    };

    template<class T, class U>
    struct Length<TypeList<T, U > >
    {
        enum { value = 1 + Length<U>::value };
    };

    template<class TList, unsigned int i> struct TypeAt;

    template<class Head, class Tail>
    struct TypeAt<TypeList<Head, Tail>, 0>
    {
        typedef Head Result;
    };

    template<class Head, class Tail, unsigned int i>
    struct TypeAt<TypeList<Head, Tail>, i>
    {
        typedef typename TypeAt<Tail, i - 1>::Result    Result;
    };

    template<class TList, unsigned int i> struct TypeAtNotStrict;

    template<unsigned int i>
    struct TypeAtNotStrict<NullType, i>
    {
        typedef NullType    Result;
    };

	template<>
	struct TypeAtNotStrict<NullType, 0>
	{
		typedef NullType	Result;
	};

    template<class Head, class Tail>
    struct TypeAtNotStrict<TypeList<Head, Tail>, 0>
    {
        typedef Head Result;
    };

    template<class Head, class Tail, unsigned int i>
    struct TypeAtNotStrict<TypeList<Head, Tail>, i>
    {
        typedef typename TypeAtNotStrict<Tail, i - 1>::Result    Result;
    };

    template<class TList, typename T> struct IndexOf;

    template<typename T>
    struct IndexOf<NullType, T>
    {
        enum { value = -1 };
    };

    template<class Tail, typename T>
    struct IndexOf<TypeList<T, Tail>, T>
    {
        enum { value = 0 };
    };

    template<class Head, class Tail, typename T>
    struct IndexOf<TypeList<Head, Tail>, T>
    {
    private:
        enum { tmp = IndexOf<Tail, T>::value };
    public:
        enum { value = tmp == -1 ? -1 : 1 + tmp };
    };

    template<class TList, typename T> struct Append;

    template <> struct Append<NullType, NullType>
    {
        typedef NullType    Result;
    };

    template <class T>
    struct Append<NullType, T>
    {
        typedef TYPELIST_1(T)   Result;
    };

    template <class Head, class Tail>
    struct Append<NullType, TypeList<Head, Tail> >
    {
        typedef TypeList<Head, Tail>    Result;
    };

    template<class Head, class Tail, typename T>
    struct Append<TypeList<Head, Tail>, T>
    {
      typedef TypeList<Head, typename Append<Tail, T>::Result>   Result;
    };
    

    template<class TList, typename T> struct Erase;

    template<class T>
    struct Erase<NullType, T>
    {
        typedef NullType Result;
    };

    template<class Tail, typename T>
    struct Erase<TypeList<Tail, T>, T>
    {
        typedef Tail    Result;
    };

    template<class Head, class Tail, typename T>
    struct Erase<TypeList<Head, Tail>, T>
    {
        typedef TypeList<Head, typename Erase<Tail, T>::Result> Result;
    };

    template<class TList, typename T, typename U> struct Replace;

    template<typename T, typename U>
    struct Replace<NullType, T, U>
    {
        typedef NullType    Result;
    };

    template<class Tail, typename T, typename U>
    struct Replace<TypeList<T, Tail>,T, U>
    {
        typedef TypeList<U, Tail>   Result;
    };

    template<class Head, class Tail, typename T, typename U>
    struct Replace<TypeList<Head, Tail>, T, U>
    {
        typedef TypeList<Head, typename Replace<Tail,T, U>::Result> Result;
    };
}


#endif // TYPELIST_HPP
