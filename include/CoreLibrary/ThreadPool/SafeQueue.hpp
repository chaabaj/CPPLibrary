#pragma once

#include <queue>
#include <utility>

#include "CoreLibrary/Mutex/Mutex.h"
#include "CoreLibrary/Mutex/ScopedLock.h"
#include "CoreLibrary/CondVar/CondVar.hpp"

namespace tekLib
{

template <class T>
class SafeQueue
{
public:
	SafeQueue() : _mutex(), _condVar(&_mutex)
	{
	}
	~SafeQueue()
	{
	}

	void	pop(T && value)
	{
		ScopedLock(&_mutex);

		_queue.push(value);
		if (!_queue.empty)
			_condVar.signal();
	}

	bool	push(T & value, bool lock = true)
	{
		bool	ret = false;
		ScopedLock(&_mutex);

		if (lock)
		{
			while (_queue.empty())
				_condVar.wait();
		}
		if (!_queue.empty())
		{
			value = _queue.front();
			_queue.pop();
			ret = true;
		}
		return (ret);
	}
private:
	std::queue<T>	_queue;
	tekLib::Mutex	_mutex;
	tekLib::CondVar	_condVar;
};
}