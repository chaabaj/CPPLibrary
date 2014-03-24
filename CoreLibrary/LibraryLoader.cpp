# include <algorithm>
# include "CoreLibrary/Utils/LibraryLoader.hpp"
# include "CoreLibrary/String/StringConverter.hpp"

LibraryLoader::LibraryLoader()
{
}

LibraryLoader::~LibraryLoader()
{
  std::map<std::string, DynamicLibrary>::iterator	it;
  
  for (it = _libraries.begin(); it != _libraries.end(); ++it)
    this->unload(it->second);
}

void	LibraryLoader::unload(DynamicLibrary lib)
{
  #ifdef WIN32
    FreeLibrary(lib);
  #elif __gnu_linux__
    dlclose(lib);
  #endif
}

void	LibraryLoader::load(std::string const &name)
{
  DynamicLibrary	library;
  
#ifdef WIN32
  library = LoadLibraryA(name.c_str());
#elif __gnu_linux__
  library = dlopen(name.c_str(), RTLD_LAZY);
#endif
  if (!library)
    throw std::runtime_error("Cannot load library : " + name);
  _libraries[name] = library;
}