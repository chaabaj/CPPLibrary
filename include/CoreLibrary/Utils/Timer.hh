#ifndef TIMER_HH
# define TIMER_HH
#include "CoreLibrary/DllExport.h"

class EXPORT_DLL Timer
{
public:
  static void	wait(unsigned int microsecond);
};

#endif