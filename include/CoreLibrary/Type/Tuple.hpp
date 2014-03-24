#ifndef TUPLES_HPP
#define TUPLES_HPP
#include "NullType.hpp"

#if !(_MSC_VER > 1000)
//If you use a real compiler

	template<int ... values> struct Tuple
	{
	};

	template<int head, int ... tail>
	struct Tuple<head, tail...>
	{
		enum { value = head };
		typedef Tuple<tail...>	Next;
	};

	template<int last>
	struct Tuple<last>
	{
		enum { value = last };
		typedef NullType	Next;
	};

	namespace TPL
	{
		template<unsigned int index, class TupleClass>
		struct At
		{
			enum { result = At<index - 1, typename TupleClass::Next>::result };
		};
  
		template<class TupleClass>
		struct At<0, TupleClass>
		{
			enum { result = TupleClass::value };
		};

		template<class TupleClass, unsigned int value> struct Add
		
		template<class TupleClass, unsigned int value>
		struct Add
		{
			enum { value = TupleClass::value };
			typedef TupleClass::Next	Next;
		};

		template<unsigned int value>
		struct Add<NullType, unsigned int value>
		{
			enum { value = value };
			typedef NullType	Next;
		}
  
	}
#endif
#endif // TUPLES_HPP
