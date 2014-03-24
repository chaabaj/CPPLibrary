#ifndef LOGGER_EXCEPTION_HPP
# define LOGGER_EXCEPTION_HPP

# include <stdexcept>

class LoggerException : public std::runtime_error
{
public:
  explicit LoggerException(std::string const &arg) : std::runtime_error(arg) {}
};

#endif