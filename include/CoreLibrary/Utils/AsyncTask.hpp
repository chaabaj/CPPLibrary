#ifndef ASYNC_TASK_HPP
# define ASYNC_TASK_HPP

# include "CoreLibrary/Thread/AThread.hpp"

template<class Task>
class ASyncTask : public tekLib::AThread
{
public:
	ASyncTask()
	{

	}

	ASyncTask(Task task) : _task(task)
	{
	}
	~ASyncTask()
	{

	}

	void	setTask(Task const &task)
	{
		_task = task;
	}

private:

	void	run()
	{
		_task();
	}
	Task	_task;
};

#endif
