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
	void CourseMeeting::setEndTime(int newTime)
	{
	}
	int CourseMeeting::getEndTime() const
	{
		return 0;
	}
	void CourseMeeting::setCourse(Course newCourse)
	{
	}
	Course CourseMeeting::getCourse() const
	{
		return Course();
	}
	bool CourseMeeting::operator==(const CourseMeeting & rhs)
	{
		return false;
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
