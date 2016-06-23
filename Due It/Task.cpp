#include "Task.h"
#include <sstream>

namespace DueItModel
{
	Task::Task(int start, int d, int m, int y, bool repeating, int daysInterval, int monthsInterval)
	{
		startTime = start;
		day = d;
		month = m;
		year = y;
		isRepeating = repeating;
		daysToRepeat = daysInterval;
		monthsToRepeat = monthsInterval;
	}

	Task::~Task()
	{
	}

	std::string Task::toString()
	{
		std::stringstream formattedTime;
		formattedTime << "Task time: " << (startTime / 3600) << ":" << ((startTime % 3600) / 60) << ":" << (startTime % 60) <<
			" on " << month << "/" << day << "/" << year;
		if (isRepeating)
		{
			formattedTime << " and repeats every " << daysToRepeat << " days, " << monthsToRepeat << " months";
		}
		formattedTime << "\n";
		return formattedTime.str();
	}

	bool Task::hasPassed(int currentSec, int currentDay, int currentMonth, int currentYear)
	{
		if (currentYear > year)
		{
			return true;
		}
		else if (currentYear == year)
		{
			if (currentMonth > month)
			{
				return true;
			}
			else if (currentMonth == month)
			{
				if (currentDay > day)
				{
					return true;
				}
				else if (currentDay == day)
				{
					if (currentSec > startTime)
					{
						return true;
					}
				}
			}
		}
		return false;
	}

	void Task::repeat()
	{
		if (!isRepeating)
		{
			return;
		}
		int daysInCurrentMonth;
		do {
			if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
			{
				daysInCurrentMonth = 31;
			}
			else if (month == 4 || month == 6 || month == 9 || month == 11)
			{
				daysInCurrentMonth = 30;
			}
			else if (year % 4 == 0)
			{
				daysInCurrentMonth = 29;
			}
			else
			{
				daysInCurrentMonth = 28;
			}
			if (day + daysToRepeat > daysInCurrentMonth)
			{
				if (month == 12)
				{
					month = 1;
					year++;
					day = day + daysToRepeat - 31;
					daysToRepeat -= 31;
				}
				else
				{
					month++;
					day = day + daysToRepeat - daysInCurrentMonth;
					daysToRepeat -= daysInCurrentMonth;
				}
			}
			else
			{
				day += daysToRepeat;
			}
		} while (daysToRepeat >= daysInCurrentMonth);

		while (monthsToRepeat > 0)
		{
			month++;
			monthsToRepeat--;
			if (month == 13)
			{
				year++;
				month = 1;
			}
		}
	}

	bool Task::operator==(const Task & rhs)
	{
		if (startTime == rhs.getTime() && day == rhs.getDay() && month == rhs.getMonth() && year == rhs.getYear() && isRepeating == rhs.getIsRepeating()
			&& daysToRepeat == rhs.getDaysToRepeat() && monthsToRepeat == rhs.getMonthsToRepeat())
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

	void Task::setIsRepeating(bool repeats)
	{
		isRepeating = repeats;
	}

	bool Task::getIsRepeating() const
	{
		return isRepeating;
	}

	void Task::setDaysToRepeat(int newDayInterval)
	{
		daysToRepeat = newDayInterval;
	}

	int Task::getDaysToRepeat() const
	{
		return daysToRepeat;
	}

	void Task::setMonthsToRepeat(int newMonthInterval)
	{
		monthsToRepeat = newMonthInterval;
	}

	int Task::getMonthsToRepeat() const
	{
		return monthsToRepeat;
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