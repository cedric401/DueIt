#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#include "Schedule.h"
#include <sstream>
#include <ctime>
using namespace std;

namespace DueItModel
{
	Schedule::Schedule()
	{
		currentSchedule = vector<Task *>();
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
	void Schedule::addTask(Task * newTask)
	{
		currentSchedule.insert(currentSchedule.end(), newTask);
	}
	void Schedule::deleteTask(Task * aTask)
	{
		for (std::vector<Task *>::iterator iter = currentSchedule.begin(); iter != currentSchedule.end(); ++iter)
		{
			if (*iter == aTask)
			{
				currentSchedule.erase(iter);
				delete aTask;
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
		vector<Task *> newSchedule = vector<Task *>();
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
			taskType = typeid(AssignmentTask).name();
			break;
		}

		for (Task * aTask : currentSchedule)
		{
			if (taskType != typeid(aTask).name())
			{
				newSchedule.insert(newSchedule.end(), aTask);
			}
			else
			{
				delete aTask;
			}
		}

		currentSchedule = newSchedule;
	}
	vector<Task *> Schedule::findStudyTime()
	{
		//TODO
		return vector<Task *>();
	}
	string Schedule::toString()
	{
		sortTasks();
		string tasksString = "Current Schedule: \n";
		for (Task * aTask : currentSchedule)
		{
			tasksString += aTask->toString();
		}

		return tasksString;
	}
	Task * Schedule::getTask(int index)
	{
		return currentSchedule.at(index);
	}
	void Schedule::setCurrentTime(tm *newTime)
	{
		delete currentTime;
		currentTime = newTime;
	}
	tm * Schedule::getCurrentTime()
	{
		return currentTime;
	}
	void Schedule::sortTasks()
	{
		//Radix sort w/ count sort for days, months, then years
		//TODO: Include sorting for seconds time.

		int n = currentSchedule.size();
		//Sort by day:
		vector<Task*> sorted(n);
		int count[31] = { 0 };

		for (int i = 0; i < n; i++)
		{
			count[currentSchedule[i]->getDay() - 1]++;
		}
		for (int i = 1; i < 31; i++)
		{
			count[i] += count[i - 1];
		}
		for (int i = n - 1; i >= 0; i--)
		{
			sorted[count[currentSchedule[i]->getDay() - 1] - 1] = currentSchedule[i];
			count[currentSchedule[i]->getDay() - 1]--;
		}
		currentSchedule = sorted;

		//Sort by month:
		sorted = vector<Task*>(n);
		int countM[12] = { 0 };

		for (int i = 0; i < n; i++)
		{
			countM[currentSchedule[i]->getMonth() - 1]++;
		}
		for (int i = 1; i < 12; i++)
		{
			countM[i] += countM[i - 1];
		}
		for (int i = n - 1; i >= 0; i--)
		{
			sorted[countM[currentSchedule[i]->getMonth() - 1] - 1] = currentSchedule[i];
			countM[currentSchedule[i]->getMonth() - 1]--;
		}
		currentSchedule = sorted;

		//Sort by year:
		sorted = vector<Task*>(n);
		int countY[100] = { 0 }; //Will include the range from the year 2000 to 2100

		for (int i = 0; i < n; i++)
		{
			countY[currentSchedule[i]->getYear() - 2000]++;
		}
		for (int i = 1; i < 100; i++)
		{
			countY[i] += countY[i - 1];
		}
		for (int i = n - 1; i >= 0; i--)
		{
			sorted[countY[currentSchedule[i]->getYear() - 2000] - 1] = currentSchedule[i];
			countY[currentSchedule[i]->getYear() - 2000]--;
		}
		currentSchedule = sorted;
	}
};
