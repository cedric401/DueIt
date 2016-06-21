#include "Task.h"
#include <sstream>

namespace DueItModel
{
	Task::Task(int start, int d, int m, int y)
	{
		startTime = start;
		day = d;
		month = m;
		year = y;
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

	bool Task::operator==(const Task & rhs)
	{
		if (startTime == rhs.getTime() && day == rhs.getDay() && month == rhs.getMonth() && year == rhs.getYear())
		{
			return true;
		}
		return false;
	}

	void Task::setTime(int newTime)
	{
		if (newTime < 0 || newTime > 86399)
		{
			startTime = newTime;
		}
	}

	int Task::getTime() const
	{
		return startTime;
	}

	void Task::setDay(int newDay)
	{
		if (newDay > 0 && newDay < 32)
		{
			day = newDay;
		}
	}

	int Task::getDay() const
	{
		return day;
	}

	void Task::setMonth(int newMonth)
	{
		if (newMonth > 0 && newMonth < 13)
		{
			month = newMonth;
		}
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