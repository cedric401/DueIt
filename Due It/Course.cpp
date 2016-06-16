#include "Course.h"
#include <string>



namespace DueItModel
{
	Course::Course(int courseIDNumber)
	{
		readEntry(courseIDNumber);
		courseNumber = courseIDNumber;
	}
	Course::Course(int courseIDNumber, std::string nameOfCourse)
	{
		courseNumber = courseIDNumber;
		courseName = nameOfCourse;
	}

	Course::~Course()
	{
	}
	std::string Course::toString()
	{
		return courseNumber + " " + courseName;
	}
	void Course::setCourseNumber(int newNumber)
	{
	}
	int Course::getCourseNumber() const
	{
		return 0;
	}
	void Course::setCourseName(const std::string& newName)
	{
	}
	std::string Course::getCourseName() const
	{
		return std::string();
	}
	bool Course::operator==(const Course & rhs)
	{
		return false;
	}
	void Course::createEntry()
	{
	}
	void Course::deleteEntry()
	{
	}
	void Course::updateEntry()
	{
	}
	void Course::readEntry(int courseID)
	{
	}
};
