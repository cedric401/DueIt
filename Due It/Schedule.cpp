#include "Schedule.h"

namespace DueItModel
{
	Schedule::Schedule()
	{
	}

	Schedule::~Schedule()
	{
	}
	void Schedule::updateTime()
	{
	}
	void Schedule::addTask(Task newTask)
	{
	}
	void Schedule::deleteTask(Task aTask)
	{
	}
	void Schedule::deleteAllTasksForCourse(int courseNumber)
	{
	}
	void Schedule::deleteAllTasksForJob(std::string companyName)
	{
	}
	void Schedule::deleteAllTimePeriod(int strtT, int strtD, int strtM, int strtY, int endT, int endD, int endM, int endY)
	{
	}
	void Schedule::changeScheduleTimePeriod(int strtT, int strtD, int strtM, int strtY, int endT, int endD, int endM, int endY)
	{
	}
	void Schedule::setTypeTasksShown(int type)
	{
	}
	std::vector<Task> Schedule::findStudyTime()
	{
		return std::vector<Task>();
	}
	std::string Schedule::toString()
	{
		return std::string();
	}
	Task Schedule::getTask(int index)
	{
		return Task();
	}
	void Schedule::sortTasks()
	{
	}
};
