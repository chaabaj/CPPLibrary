/*
* File : ScopedLock.cpp
* Author : didier_f
*
* Created on August 9,2013,11:40PM
*/

#include"CoreLibrary/Mutex/ScopedLock.h"

tekLib::ScopedLock::ScopedLock(Mutex &mutex) : _mutex(mutex)
{
    _mutex.lock();
}
