#ifndef IOEXCEPTION_HPP
# define IOEXCEPTION_HPP

# include <stdexcept>

class IOException : public std::runtime_error
{
public:
  explicit IOException(std::string const &arg) : std::runtime_error(arg) {}
};

#endif