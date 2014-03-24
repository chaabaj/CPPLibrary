#pragma once

#include <string>
#include <exception>

namespace tekLib
{

	class AThreadException : std::bad_exception
	{
	public:
		AThreadException(std::string const & msg) : _msg(msg)
		{
		}

		virtual ~AThreadException(void) throw ()
		{
		}

		virtual const char * what() const throw()
		{
			return (_msg.c_str());
		}

	private:
		std::string	_msg;
	};
}

