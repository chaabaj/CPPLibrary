#pragma once

#include "CoreLibrary/Mutex/Mutex.h"
#include "CoreLibrary/Mutex/ScopedLock.h"
//#include "CoreLibrary/Garbage/enable_if.hpp"
#include "CoreLibrary/Type/TypeTraits.hpp"

namespace tekLib
{
	template <class T>
	class Atomic
	{
	public:
		Atomic(T value)
		{
		  _data = value;
		}
		
		Atomic(void) { }
        ~Atomic(void) { }
		
		Atomic(T & value)
		{
		  _data = value;
		}
		
		T	operator =(T value) volatile
		{
		  store(value);
		  return (value);
		}
		
		T	operator =(T value)
		{
		  store(value);
		  return (value);
		  
		}
		
		template <class U>
		U	operator =(U value) volatile
		{
		  store(static_cast<T>(value));
		  return (value);
		  
		}
		
		template <class U>
		U	operator =(U value)
		{
		  store(static_cast<T>(value));
		  return (value);
		  
		}
	
		T*	operator ->()
		{
		  return (&_data);
		}
		
		T	load() const volatile
		{
		  return (_data);
		}
		
		void	store(T value) volatile
		{
		  ScopedLock	lock(&_mutex);
		  
		  _data = value;
		}
		
		void	store(T value)
		{
		  ScopedLock	lock(&_mutex);
		  
		  _data = value;
		}
		
		operator T() const volatile
		{
		  return (_data);
		}
		
		operator T() const
		{
		  return (_data);
		}

		
	private:
		T		_data;
		Mutex		_mutex;
	};
	
	typedef Atomic<bool>			atomic_bool;
	typedef Atomic<char>			atomic_char;
	typedef Atomic<signed char>		atomic_schar;
	typedef Atomic<unsigned char>		atomic_uchar;
	typedef Atomic<short>			atomic_short;
	typedef Atomic<unsigned short>		atomic_ushort;
	typedef Atomic<int>			atomic_int;
	typedef Atomic<unsigned int>		atomic_uint;
	typedef Atomic<long>			atomic_long;
	typedef Atomic<unsigned long>		atomic_ulong;
	typedef Atomic<long long>		atomic_llong;
	typedef Atomic<unsigned long long>	atomic_ullong;
}
