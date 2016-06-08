#include "Assignment.h"
#include <sstream>


namespace DueItModel
{
	Assignment::Assignment()
	{
	}


	Assignment::~Assignment()
	{
	}

	std::string Assignment::toString()
	{
		return std::string();
	}
	void Assignment::setTime(int newTime)
	{
	}
	void Assignment::setDay(int newDay)
	{
	}
	void Assignment::setMonth(int newMonth)
	{
	}
	void Assignment::setYear(int newYear)
	{
	}
	void Assignment::setCourse(Course newCourse)
	{
	}
	Course Assignment::getCourse()
	{
		return Course();
	}
	void Assignment::setEstimatedTimeToComplete(int newTime)
	{
	}
	int Assignment::getEstimatedTimeToComplete()
	{
		return 0;
	}
	void Assignment::setDetails(std::string newDetails)
	{
	}
	std::string Assignment::getDetails()
	{
		return std::string();
	}
	void Assignment::createEntry()
	{
	}
	void Assignment::deleteEntry()
	{
	}
	void Assignment::updateEntry()
	{
	}
	void Assignment::readEntry(int row)
	{
	}
};
