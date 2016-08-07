#pragma once
#include <vector>
#include "Task.h"
#include "Job.h"
#include "Payment.h"
#include "CourseMeeting.h"
#include "AssignmentTask.h"
#include "DBManipulator.h"

namespace DueItModel
{
	class Schedule
	{
	public:
		std::string test;
		Schedule();
		~Schedule();
		void updateTime();
		void updateSchedule();
		void addTask(Task * newTask);
		void updateTask(Task * aTask);
		void deleteTask(Task * aTask);
		void deleteAllTasksForCourse(int courseNumber);
		void deleteAllTasksForJob(std::string companyName);
		void deleteAllTimePeriod(int strtT, int strtD, int strtM, int strtY, int endT, int endD, int endM, int endY);
		void changeScheduleTimePeriod(int strtT, int strtD, int strtM, int strtY, int endT, int endD, int endM, int endY);
		void setTypeTasksShown(int type);
		std::vector<Task *> findStudyTime();
		std::string toString();
		Task * getTask(int index);
		void setCurrentTime(struct tm *newTime);
		struct tm * getCurrentTime();
		int getScheduleSize();

	private:
		struct tm *currentTime;
		DBManipulator scheduleDB;
		std::vector<Task *> currentSchedule;
		void sortTasks();
	};
};

