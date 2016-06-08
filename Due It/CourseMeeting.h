#pragma once
#include "Task.h"
#include "Course.h"
namespace DueItModel
{
	class CourseMeeting :
		public Task
	{
	public:
		CourseMeeting(int dbRowID);
		CourseMeeting(int startingTime, int workDay, int mnth, int yr, int endingTime, Course aCourse);
		~CourseMeeting();
		std::string toString();
		void setTime(int newTime);
		void setDay(int newDay);
		void setMonth(int newMonth);
		void setYear(int newYear);
		void setEndTime(int newTime);
		int getEndTime();
		void setCourse(Course newCourse);
		Course getCourse();

	private:
		int endTime;
		Course course;
		int rowID;
		void createEntry();
		void deleteEntry();
		void updateEntry();
		void readEntry(int courseID);
	};
};

