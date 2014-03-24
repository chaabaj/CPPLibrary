#ifndef MATH_HPP
# define MATH_HPP

# include <stdexcept>

namespace Math
{

	template<int n> 
	inline double power(double x)
	{
		return x * power<n - 1>(x);
	}

	template<>
	inline double power<0>(double x)
	{
		return 1.0;
	}

	template<int n>
	inline double factorial()
	{
		return n * factorial<n - 1>();
	}

	template<>
	inline double factorial<0>()
	{
		return 1.0;
	}

	template <int n>
	inline double _exponential(double x)
	{
		return _exponential<n - 1>(x) + power<n>(x) / factorial<n>();
	}

	template<>
	inline double _exponential<0>(double x)
	{
		return 0.0;
	}

	template <int n> inline double exponential(double x)
	{
		return x < 0.0 ? 1.0 / _exponential<n>(-x) : _exponential<n>(x);
	}

	template <int n> 
	inline double cosinus(double x)
	{
		return cosinus<n - 1>(x) + (n % 2 ? -1 : 1) * power<2 * n>(x) / factorial<2 * n>(x);
	}

	template<>
	inline double cosinus<0>(double x)
	{
		return 1.0;
	}

	template<int n>
	inline double arctanh(double x)
	{
		return arctanh<n - 1>(x) + (power<2 * n + 1>(x)) / (2 * n + 1);
	}

	template<>
	inline double arctanh<1>(double x)
	{
		return x;
	}

	template<>
	inline double arctanh<0>(double x)
	{
		return 0;
	}

	template<int n>
	inline double sinus(double x)
	{
		return sinus<n - 1>(x) + (n % 2 ? -1 : 1) * (power<2 * n + 1>(x)) / factorial<2 * n + 1>();
	}

	template<>
	inline double sinus<0>(double x)
	{
		return 0.0;
	}

	template<int n>
	inline double logarithm(double x)
	{
		return logarithm<n - 1>(x) + (power<n + 1>(x)) / (n + 1);
	}

	template<>
	inline double logarithm<1>(double x)
	{
		return 0.0;
	}

	template<> 
	inline double logarithm<0>(double x)
	{
		throw std::runtime_error("Logarithm of 0 doesn't exist");
		return 0.0;
	}

	#if !(_MSC_VER > 1000)
		#ifdef __GNUC_
			__attribute__ ((mode(V4SF)))
			union Vec4 
			{
				v4sf v;
				float elems[4];
			}
		#endif
	#endif

	double sqrt(double x)
	{
		#if (_MSC_VER > 1000)
			return sqrt(x);
		#else 
			#ifdef __GNUC_ 
				Vec4 vector;
				vector.v = __builtin_ia32_sqrtss(x);
				return vector.elems[0]
			#endif
		#endif
	}
}

#endif