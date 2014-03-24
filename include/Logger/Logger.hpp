#ifndef LOGGER_HH_
# define LOGGER_HH_

# include <iostream>
# include <string>
# include <set>
# include <fstream>
# include "CoreLibrary/Policies/Singleton/SingleThreaded.hpp"
# include "CoreLibrary/Exceptions/IOException.hpp"
# include <CoreLibrary/Container/SetContainer.hpp>
# include "Logger/Exceptions/LoggerException.hpp"

template<template<class> ThreadingModel = SingleThreaded>
class Logger
{
public:
  Logger() : _type(outputStream)
  {
    _stream = &std::cout;
  }
  
  Logger(std::string const &filename) : _type(fileStream)
  {
    std::ofstream	*fstream = new std::ofstream;
    
    fstream->open(filename, std::ofstream::out | std::ofstream::app);
    if (!fstream->is_open())
      throw IOException("Cannot open file : " + filename);
    _stream = fstream;
  }
  
  ~Logger()
  {
    if (_type == fileStream)
    {
      std::ofstream	*fstream = dynamic_cast<std::ofstream*>(_stream);
      
      fstream->close();
      delete fstream;
    }
  }
  
  void	createLevel(std::string const &level)
  {
    if (_levels.find(level) == _levels.end())
      _levels.insert(level);
  }
  
  void	write(std::string const &level, std::string const &str)
  {
    Lock	lock(_mutex);
    
    if (_levels.find(level) == _levels.end())
      throw LoggerException("Cannot find level", level);
    _stream << "[" << level << "]" << " : " << str << std::endl;
  }
  
private:
  
  typedef typename ThreadingModel<std::ostream>::Lock		Lock;
  typedef typename ThreadingModel<std::ostream>::Mutex		Mutex;
  
  typedef SetContainer<std::string, RejectInvalidIndex, ThreadingModel>	LevelContainer;
  
  Logger(Logger const &other);
  
  Logger	&operator=(Logger const &other);
  
  enum StreamType { outputStream = 1, fileStream = 2 };
  
  LevelContainer 		_levels;
  std::ostream			*_stream;
  StreamType			_type;
  Mutex				_mutex;
};

#endif