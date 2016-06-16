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
	
	void Assignment::setCourse(Course newCourse)
	{
	}
	Course Assignment::getCourse() const
	{
		return Course();
	}
	void Assignment::setEstimatedTimeToComplete(int newTime)
	{
	}
	int Assignment::getEstimatedTimeToComplete() const
	{
		return 0;
	}
	void Assignment::setDetails(const std::string& newDetails)
	{
	}
	std::string Assignment::getDetails() const
	{
		return std::string();
	}
	bool Assignment::operator==(const Assignment & rhs)
	{
		return false;
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
