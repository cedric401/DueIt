#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#include "Schedule.h"
#include <sstream>
#include <ctime>
#include <algorithm>

using namespace std;

namespace DueItModel
{
	Schedule::Schedule()
	{
		scheduleDB = DBManipulator();
		updateTime();
		currentSchedule = scheduleDB.retrieveTasksInRange();
		updateSchedule();
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
	void Schedule::updateSchedule()
	{
		updateTime();
		for (std::vector<Task *>::iterator iter = currentSchedule.begin(); iter != currentSchedule.end();)
		{
			if ((*iter)->hasPassed((currentTime->tm_hour * 3600) + (currentTime->tm_min * 60) + currentTime->tm_sec, 
				currentTime->tm_mday, currentTime->tm_mon + 1, currentTime->tm_year + 1900))
			{
				if ((*iter)->getIsRepeating())
				{
					while ((*iter)->hasPassed((currentTime->tm_hour * 3600) + (currentTime->tm_min * 60) + currentTime->tm_sec,
						currentTime->tm_mday, currentTime->tm_mon + 1, currentTime->tm_year + 1900))
					{
						(*iter)->repeat();
					}
					updateTask((*iter));
				}
				else
				{
					deleteTask(*iter);
					iter = currentSchedule.erase(iter);
				}
			}
			else
			{
				iter++;
			}
		}
	}
	void Schedule::addTask(Task * newTask)
	{
		currentSchedule.insert(currentSchedule.end(), newTask);
		if (Payment *p = dynamic_cast<Payment *>(newTask))
		{
			scheduleDB.addEntry(dynamic_cast<Payment *>(newTask));
		}
		else if (Job *j = dynamic_cast<Job *>(newTask))
		{
			scheduleDB.addEntry(dynamic_cast<Job *>(newTask));
		}
		else if (AssignmentTask *a = dynamic_cast<AssignmentTask *>(newTask))
		{
			scheduleDB.addEntry(dynamic_cast<AssignmentTask *>(newTask));
		}
		else if (CourseMeeting *c = dynamic_cast<CourseMeeting *> (newTask))
		{
			scheduleDB.addEntry(dynamic_cast<CourseMeeting *>(newTask));
		}
	}
	void Schedule::updateTask(Task * aTask)
	{
		if (Payment *p = dynamic_cast<Payment *>(aTask))
		{
			scheduleDB.updateEntry(dynamic_cast<Payment *>(aTask));
		}
		else if (Job *j = dynamic_cast<Job *>(aTask))
		{
			scheduleDB.updateEntry(dynamic_cast<Job *>(aTask));
		}
		else if (AssignmentTask *a = dynamic_cast<AssignmentTask *>(aTask))
		{
			scheduleDB.updateEntry(dynamic_cast<AssignmentTask *>(aTask));
		}
		else if (CourseMeeting *c = dynamic_cast<CourseMeeting *> (aTask))
		{
			scheduleDB.updateEntry(dynamic_cast<CourseMeeting *>(aTask));
		}
	}
	void Schedule::deleteTask(Task * aTask)
	{
		if (Payment *p = dynamic_cast<Payment *>(aTask))
		{
			scheduleDB.deleteEntry(dynamic_cast<Payment *>(aTask));
		}
		else if (Job *j = dynamic_cast<Job *>(aTask))
		{
			scheduleDB.deleteEntry(dynamic_cast<Job *>(aTask));
		}
		else if (AssignmentTask *a = dynamic_cast<AssignmentTask *>(aTask))
		{
			scheduleDB.deleteEntry(dynamic_cast<AssignmentTask *>(aTask));
		}
		else if (CourseMeeting *c = dynamic_cast<CourseMeeting *> (aTask))
		{
			scheduleDB.deleteEntry(dynamic_cast<CourseMeeting *>(aTask));
		}

		for (std::vector<Task *>::iterator iter = currentSchedule.begin(); iter != currentSchedule.end();)
		{
			if (*iter == aTask)
			{
				delete aTask;
				iter = currentSchedule.erase(iter);
				break;
			}
			else
			{
				iter++;
			}
		}
	}
	void Schedule::deleteAllTasksForCourse(int courseNumber)
	{
		for (std::vector<Task *>::iterator iter = currentSchedule.begin(); iter != currentSchedule.end();)
		{
			if (typeid(*iter).name() == typeid(AssignmentTask).name() || typeid(*iter).name() == typeid(CourseMeeting).name())
			{
				if (static_cast<AssignmentTask*>(*iter)->getCourse().getCourseNumber() == courseNumber)
				{
					deleteTask(*iter);
					iter = currentSchedule.erase(iter);
				}
				else
				{
					iter++;
				}
			}
		}
	}
	void Schedule::deleteAllTasksForJob(string companyName)
	{
		for (std::vector<Task *>::iterator iter = currentSchedule.begin(); iter != currentSchedule.end();)
		{
			if (typeid(*iter).name() == typeid(Job).name())
			{
				if (static_cast<Job*>(*iter)->getEmployer().getCompanyName() == companyName)
				{
					deleteTask(*iter);
					iter = currentSchedule.erase(iter);
				}
				else
				{
					iter++;
				}
			}
		}
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
		int i = 1;
		for (Task * aTask : currentSchedule)
		{
			tasksString += i;
			tasksString += ". ";
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
		//Radix sort w/ std::sort for seconds, count sort for days, months, then years (count sort for seconds would require a large counting array for even small n)
		//Sort by seconds:
		std::sort(currentSchedule.begin(), currentSchedule.end(), [](Task * lhs, Task * rhs) -> bool {return lhs->getTime() < rhs->getTime(); });
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
