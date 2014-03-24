#ifndef MUTEX_H_
# define MUTEX_H_

/**
* \file Mutex.h
* \brief Mutex Class
* \author didier_f
* \version 0.1
* \date 09 ao�t 2013
*
* Mutex Class for encapsulation of Mutex in Windows and Linux.
*
*/

#include "CoreLibrary/Mutex/IMutexPlateform.h"
#include "CoreLibrary/SmartPointer/SmartPointer.hpp"
#include "CoreLibrary/Policies/SmartPointer/Checking/AssertCheck.hpp"
#include "CoreLibrary/Policies/SmartPointer/Ownership/RefCounted.hpp"
#include "CoreLibrary/Policies/SmartPointer/Storage/DefaultStorage.hpp"
#include "CoreLibrary/DllExport.h"

#include <cstdio>

/*!
* \addtogroup tekLib
* @{
*/
namespace tekLib
{

	/*! \class Mutex
	* \brief Class Mutex Encapsulation
	*
	*/
	class EXPORT_DLL Mutex
	{
	public:
		/**
		* \fn Mutex(void);
		* \brief Constructeur of Mutex Class
		*
		* \param Nothing
		* \return A Object of Mutex Class
		*/
		Mutex(void);

		/*!
		* \brief Destructeur of Mutex Class
		*
		*/
		~Mutex(void);

		/*!
		* \brief Lock a Mutex
		*
		* Method for locking a mutex
		*
		* \param Nothing
		* \return Nothing
		*/
		void lock();

		/*!
		* \brief Unlock a Mutex
		*
		* Method for unlocking a mutex
		*
		* \param Nothing
		* \return Nothing
		*/
		void unlock();

		/*!
		* \brief Trylock a Mutex
		*
		* Method for trylocking a mutex
		*
		* \param time : Timeout for trylock
		* \return true if trylock success or false
		*/
		bool 	trylock(unsigned int time = 0);

	private:
	  Mutex(const Mutex&)
	  {
	    
	  }
	  const Mutex & operator=(const Mutex& other)
	  {
	    return *this;
	  }
	  ::SmartPointer<IMutexPlateform, DefaultStorage, RefCounted, AssertCheck>	_sharedMutexInterface;
	  
	};
}

/*! @} End of Doxygen Groups*/

#endif /* !MUTEX_H_ */