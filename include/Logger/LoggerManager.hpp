#ifndef LOGGER_MANAGER_HPP_
# define LOGGER_MANAGER_HPP_

# include "CoreLibrary/Policies/Singleton/SingleThreaded.hpp"
# include "Logger/Logger.hpp"
# include <map>

template<template<class> ThreadingModel = SingleThreaded>
class LoggerManager
{
  typedef typename ThreadingModel<Logger<ThreadingModel> >::SharedPtr	SharedLoggerPtr;
public:
  
  LoggerManager()
  {
  }
  
  ~LoggerManager()
  {
  }
  
  void	createLogger(std::string const &name, std::string const &filename = "")
  {
    if (filename != "")
      _loggers[name] = SharedLoggerPtr(new Logger<ThreadingModel>());
    else
      _loggers[name] = SharedLoggerPtr(new Logger<ThreadingModel>(filename));
  }
  
  SharedLoggerPtr	getLogger(std::string const &name)
  {
    if (_loggers.find(name) == _loggers.end())
      throw LoggerException("Cannot found logger with name : " + name);
    return _loggers[name];
  }
  
private:
  LoggerManager(LoggerManager const &other);
  
  LoggerManager		&operator=(LoggerManager const &other);
  
  std::map<std::string, SharedLoggerPtr>			_loggers;	
};

#endif