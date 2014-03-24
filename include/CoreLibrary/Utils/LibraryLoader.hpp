#ifndef LIBRARY_LOADER_HPP_
# define LIBRARY_LOADER_HPP_

# ifdef WIN32
#  include <windows.h>
# elif __gnu_linux__
#  include <dlfcn.h>
# endif


# include <map>
# include <string>
# include <stdexcept>
#include "CoreLibrary/DllExport.h"

class EXPORT_DLL LibraryLoader
{ 
public:
  LibraryLoader();
  ~LibraryLoader();
  
  # ifdef WIN32
  typedef HMODULE	DynamicLibrary;
  # elif __gnu_linux__
  typedef void*		DynamicLibrary;
  # endif
  
  template<typename Function>
  Function	loadFunction(std::string const &libraryName, std::string const &name)
  {
    if (_libraries.find(libraryName) == _libraries.end())
      throw std::runtime_error("Library not loaded");
# ifdef WIN32
    Function	fun = reinterpret_cast<Function>(GetProcAddress(_libraries[libraryName], name.c_str()));
# elif __gnu_linux__
    Function	fun = reinterpret_cast<Function>(dlsym(_libraries[libraryName], name.c_str()));
    return fun;
# endif
  }
  
  void	load(std::string const &name);
  
private:
  LibraryLoader(LibraryLoader const &other);
  
  void	unload(DynamicLibrary library);

  
  LibraryLoader	&operator=(LibraryLoader const &other);
  
  std::map<std::string, DynamicLibrary>	_libraries;

};

#endif