#ifndef STRING_CONVERTER_HPP
# define STRING_CONVERTER_HPP

# include <string>
# include <sstream>
# include <vector>
# include "CoreLibrary/Type/TypeTraits.hpp"

class StringUtils
{
private:

  union Int2Bytes
  {
    int			value;
    unsigned char	bytes[4];
  };
  union shortInt2Bytes
  {
    short			value;
    unsigned char	bytes[2];
  };
public:

  template<typename T>
  static std::string	toString(typename TypeTraits<T>::ParameterType parameter)
  {
    std::stringstream	ss;

    ss << parameter;
    return ss.str();
  }

  template<typename T>
  T				valueOf(std::string const &str)
  {
    T				value;
    std::stringstream		ss;

    ss.str(str);
    ss >> value;
    return value;
  }


  static std::vector<unsigned char>	toBytes(std::string const &str)
  {
    std::vector<unsigned char>	bytes;

    for (unsigned int i = 0; str[i]; ++i)
    {
      bytes.push_back(str[i]);
    }
    bytes.push_back(0);
    return bytes;
  }

  static std::vector<unsigned char>	toBytes(std::string const &str, std::size_t size)
  {
    std::vector<unsigned char>		bytes;

    for (unsigned int i = 0; i < size; ++i)
      bytes.push_back(str[i]);
    return bytes;
  }

  static std::vector<unsigned char>	intToBytes(int value)
  {
    std::vector<unsigned char> bytes;
    Int2Bytes			converter;

    converter.value = value;
    for (unsigned int i = 0; i < 4; ++i)
      bytes.push_back(converter.bytes[i]);
    return bytes;
  }
  
  static std::vector<unsigned char>	shortIntToBytes(short int value)
  {
    std::vector<unsigned char> bytes;
    shortInt2Bytes			converter;

    converter.value = value;
    for (unsigned int i = 0; i < 2; ++i)
      bytes.push_back(converter.bytes[i]);
    return bytes;
  }
};

#endif