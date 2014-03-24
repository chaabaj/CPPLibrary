/**
 * \file ScopedLock.h
 * \brief ScopedLock Class
 * \author didier_f
 * \version 0.1
 * \date 09 aout 2013
 *
 * ScopedLock for lock/unlock Mutex automaticaly
 *
 */

#ifndef SCOPEDLOCK_H
#define SCOPEDLOCK_H

#include "CoreLibrary/DllExport.h"

#include "CoreLibrary/Mutex/Mutex.h"


/*!
 * \addtogroup tekLib
 * @{
 */
namespace tekLib
{
  
  /*! \class ScopedLock
   * \brief Def Class ScopedLock
   *
   */
	class EXPORT_DLL ScopedLock
  {
  public:
    /**
     * \fn ScopedLock(tekLib::Mutex &);
     * \brief Constructeur of ScopedLock Class
     *
     * \param Mutex &: A valid Mutex is required
     * \return A Object of ScopedLock Class
     */
    ScopedLock(tekLib::Mutex &);
    
    /*!
     * \brief Destructeur of Mutex Class
     *
     */
	~ScopedLock() { _mutex.unlock(); }
    
  private:
    const ScopedLock & operator=(ScopedLock) {return *this;}
    
    tekLib::Mutex &_mutex;
    
  };
}
/*! @} End of Doxygen Groups*/

#endif /* !SCOPEDLOCK_H */

