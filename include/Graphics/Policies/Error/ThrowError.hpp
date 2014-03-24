#ifndef THROW_ERROR_HPP
# define THROW_ERROR_HPP

# include <exception>
# include <string>
# include <stdexcept>

class ThrowError
{
public:

  static void onError(std::string const &str)
  {
    throw std::runtime_error(str);
  }
};

#endif