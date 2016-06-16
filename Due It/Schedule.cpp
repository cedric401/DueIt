#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#include "Schedule.h"
#include <sstream>
#include <ctime>
using namespace std;

namespace DueItModel
{
	Schedule::Schedule()
	{
		currentSchedule = vector<Task>();
		time_t now;
		time(&now);
		currentTime = localtime(&now);
	}

	Schedule::~Schedule()
	{
	}
	void Schedule::updateTime()
	{
		time_t now;
		time(&now);
		currentTime = localtime(&now);
	}
	void Schedule::addTask(Task newTask)
	{
		currentSchedule.insert(currentSchedule.end(), newTask);
	}
	void Schedule::deleteTask(Task aTask)
	{
		for (std::vector<Task>::iterator iter = currentSchedule.begin(); iter != currentSchedule.end(); ++iter)
		{
			if (*iter == aTask)
			{
				currentSchedule.erase(iter);
				break;
			}
		}
	}
	void Schedule::deleteAllTasksForCourse(int courseNumber)
	{
		//TODO
	}
	void Schedule::deleteAllTasksForJob(string companyName)
	{
		//TODO
	}
	void Schedule::deleteAllTimePeriod(int strtT, int strtD, int strtM, int strtY, int endT, int endD, int endM, int endY)
	{
		//TODO
	}
	void Schedule::changeScheduleTimePeriod(int strtT, int strtD, int strtM, int strtY, int endT, int endD, int endM, int endY)
	{
		//TODO
	}
	void Schedule::setTypeTasksShown(int type)
	{
		vector<Task> newSchedule = vector<Task>();
		string taskType;
		switch (type)
		{
		case 0:
			taskType = typeid(Task).name();
			break;
		case 1:
			taskType = typeid(Job).name();
			break;
		case 2:
			taskType = typeid(Payment).name();
			break;
		case 3:
			taskType = typeid(CourseMeeting).name();
			break;
		case 4:
			taskType = typeid(Assignment).name();
			break;
		}

		for (Task aTask : currentSchedule)
		{
			if (taskType != typeid(aTask).name())
			{
				newSchedule.insert(newSchedule.end(), aTask);
			}
		}

		currentSchedule = newSchedule;
	}
	vector<Task> Schedule::findStudyTime()
	{
		//TODO
		return vector<Task>();
	}
	string Schedule::toString()
	{
		string tasksString = "Current Schedule: \n";

		for (Task aTask : currentSchedule)
		{
			tasksString += aTask.toString();
		}

		return tasksString;
	}
	Task Schedule::getTask(int index)
	{
		return currentSchedule.at(index);
	}
	void Schedule::setCurrentTime(tm *newTime)
	{
		currentTime = newTime;
	}
	tm * Schedule::getCurrentTime()
	{
		return currentTime;
	}
	void Schedule::sortTasks()
	{
		//TODO
	}
};
