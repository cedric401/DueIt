#include "Task.h"
#include <sstream>

namespace DueItModel
{
	Task::Task()
	{
	}

	Task::~Task()
	{
	}

	std::string Task::toString()
	{
		std::stringstream formattedTime;
		formattedTime << "Task time: " << (startTime / 3600) << ":" << ((startTime % 3600) / 60) << ":" << (startTime % 60) <<
			" on " << month << "/" << day << "/" << year << "\n";
		return formattedTime.str();
	}

	void Task::setTime(int newTime)
	{
		startTime = newTime;
	}

	int Task::getTime() const
	{
		return startTime;
	}

	void Task::setDay(int newDay)
	{
		day = newDay;
	}

	int Task::getDay() const
	{
		return day;
	}

	void Task::setMonth(int newMonth)
	{
		month = newMonth;
	}

	int Task::getMonth() const
	{
		return month;
	}

	void Task::setYear(int newYear)
	{
		year = newYear;
	}

	int Task::getYear() const
	{
		return year;
	}

	void Task::createEntry()
	{
	}

	void Task::deleteEntry()
	{
	}

	void Task::updateEntry()
	{
	}

	void Task::readEntry(int row)
	{
	}
};