#ifndef DLLEXPORT_H
# define DLLEXPORT_H_

# ifdef WIN32
#  define WINDOWS_TRISOMIE	__stdcall
#  define EXPORT_DLL __declspec(dllexport)
# else
#  define WINDOWS_TRISOMIE
#  define EXPORT_DLL
# endif

#endif