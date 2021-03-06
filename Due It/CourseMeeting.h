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
		void setEndTime(int newTime);
		int getEndTime() const;
		void setCourse(Course newCourse);
		Course getCourse() const;
		bool operator==(const CourseMeeting& rhs);
		void createEntry();
		void deleteEntry();
		void updateEntry();
		void readEntry(int courseID);

	private:
		int endTime;
		Course course;
		int rowID;
	};
};

