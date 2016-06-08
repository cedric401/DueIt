#include "CourseMeeting.h"
#include <sstream>


namespace DueItModel
{
	CourseMeeting::CourseMeeting(int dbRowID)
	{
		rowID = dbRowID;
		readEntry(dbRowID);
	}

	CourseMeeting::CourseMeeting(int startingTime, int workDay, int mnth, int yr, int endingTime, Course aCourse)
	{
		startTime = startingTime;
		day = workDay;
		month = mnth;
		year = yr;
		endTime = endingTime;
		course = aCourse;
		rowID = -1;
	}

	CourseMeeting::~CourseMeeting()
	{
	}
	std::string CourseMeeting::toString()
	{
		return std::string();
	}
	void CourseMeeting::setTime(int newTime)
	{
	}
	void CourseMeeting::setDay(int newDay)
	{
	}
	void CourseMeeting::setMonth(int newMonth)
	{
	}
	void CourseMeeting::setYear(int newYear)
	{
	}
	void CourseMeeting::setEndTime(int newTime)
	{
	}
	int CourseMeeting::getEndTime()
	{
		return 0;
	}
	void CourseMeeting::setCourse(Course newCourse)
	{
	}
	Course CourseMeeting::getCourse()
	{
		return Course();
	}
	void CourseMeeting::createEntry()
	{
	}
	void CourseMeeting::deleteEntry()
	{
	}
	void CourseMeeting::updateEntry()
	{
	}
	void CourseMeeting::readEntry(int courseID)
	{
	}
};
