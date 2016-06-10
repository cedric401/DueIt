#pragma once
#include <vector>
#include "Task.h"
namespace DueItModel
{
	class Schedule
	{
	public:
		Schedule();
		~Schedule();
		void updateTime();
		void addTask(Task newTask);
		void deleteTask(Task aTask);
		void deleteAllTasksForCourse(int courseNumber);
		void deleteAllTasksForJob(std::string companyName);
		void deleteAllTimePeriod(int strtT, int strtD, int strtM, int strtY, int endT, int endD, int endM, int endY);
		void changeScheduleTimePeriod(int strtT, int strtD, int strtM, int strtY, int endT, int endD, int endM, int endY);
		void setTypeTasksShown(int type);
		std::vector<Task> findStudyTime();
		std::string toString();
		Task getTask(int index);

	private:
		std::vector<Task> currentSchedule;
		int currentTime; //0 <= startTime <= 86,399 (86,400 seconds in a day)
		int currentDay; //1 <= day <= 31
		int currentMonth; //1 <= month <= 12
		int currentYear;
		void sortTasks();
	};
};

