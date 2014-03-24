#pragma once

#include <string>
#include <exception>

namespace tekLib
{

	class CondVarException : std::bad_exception
	{
	public:
		CondVarException(std::string const & msg) : _msg(msg)
		{
		}

		~CondVarException(void) throw ()
		{
		}

		const char * what() const throw()
		{
			return (_msg.c_str());
		}

	private:
		std::string	_msg;
	};
}