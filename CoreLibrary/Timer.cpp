#include "CoreLibrary/Utils/Timer.hh"
#ifdef WIN32
# include <Windows.h>
#else
# include <unistd.h>
#endif

void	Timer::wait(unsigned int microsecond)
{
#ifdef WIN32
  Sleep(microsecond);
#else
  usleep(microsecond * 1000);
#endif
}