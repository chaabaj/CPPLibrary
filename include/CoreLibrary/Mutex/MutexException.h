#ifndef MUTEXEXCEPTION_H_
#define MUTEXEXCEPTION_H_

#include <string>
#include <exception>

namespace tekLib
{

	class MutexException : std::bad_exception
	{
	public:
		MutexException(std::string const & msg) : _msg(msg)
		{
		}

		virtual ~MutexException(void) throw ()
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

#endif	/* !MUTEX_EXCEPTION_H_ */

