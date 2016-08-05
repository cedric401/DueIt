#include "Course.h"

namespace DueItModel
{
	Course::Course(string cName, string cSubject, string cNumber,
		string cSection, string cSchedule)
	{
		initialize(cName, cSubject, cNumber, cSection, cSchedule);
	}

	Course::~Course()
	{
	}

	void Course::setCourseName(string name)
	{
		courseName = name;
	}

	string Course::getCourseName()
	{
		return courseName;
	}

	void Course::setCourseSubject(string subject)
	{
		courseSubject = subject;
	}

	string Course::getCourseSubject()
	{
		return courseSubject;
	}

	void Course::setCourseNumber(string name)
	{
		courseNumber = name;
	}

	string Course::getCourseNumber()
	{
		return courseNumber;
	}

	void Course::setCourseSection(string section)
	{
		courseSection = section;
	}

	string Course::getCourseSection()
	{
		return courseSection;
	}

	/******************************************************************************
	setCourseSchedule() uses timeFormat() to create a string representation of
	the time integers.
	@fHR, class meets from hour.
	@fMIN, class meets from minutes.
	@tHR, class meets to hour.
	@tMIN, class meets to minutes.
	******************************************************************************/
	void Course::setCourseSchedule(string cSchedule)
	{
		courseSchedule = cSchedule;
	}

	string Course::getCourseSchedule()
	{
		return courseSchedule;
	}

	string Course::toString()
	{
		return courseNumber + " " + courseName;
	}

	bool Course::operator==(const Course & rhs)
	{
		return false;
	}

	// Initialize the fields.
	void Course::initialize(string name, string sub, string numb, string sect, string sched)
	{
		setCourseName(name);
		setCourseSubject(sub);
		setCourseNumber(numb);
		setCourseSection(sect);
		setCourseSchedule(sched);
	}
};
