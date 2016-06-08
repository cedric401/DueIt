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
	int Course::getCourseNumber()
	{
		return 0;
	}
	void Course::setCourseName(std::string newName)
	{
	}
	std::string Course::getCourseName()
	{
		return std::string();
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
