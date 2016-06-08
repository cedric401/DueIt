#include "Job.h"
#include "Company.h"
#include <sstream>

namespace DueItModel
{
	Job::Job(int dbRowID)
	{
		rowID = dbRowID;
		readEntry(dbRowID);
	}

	Job::Job(int startingTime, int endingTime, int workDay, int mnth, int yr, Company jobEmployer, int hrs, float hrlyRate)
	{
		startTime = startingTime;
		endTime = endingTime;
		day = workDay;
		month = mnth;
		year = yr;
		employer = jobEmployer;
		hours = hrs;
		rate = hrlyRate;
		rowID = -1;

	}

	Job::~Job()
	{
	}

	float Job::calcPay()
	{
		return hours * rate;
	}

	std::string Job::toString()
	{
		int endDay = day, endMonth = month, endYear = year;
		if (endTime < startTime)
		{
			endDay++;
			//if (endDay > daysinthemonth)
			//TODO finish writing code to handle when a shift runs to the next day/month/year
		}
		std::stringstream formattedTime;
		formattedTime << "Shift beginning time: " << (startTime / 3600) << ":" << ((startTime % 3600) / 60) << ":" << (startTime % 60) <<
			" on " << month << "/" << day << "/" << year << " and ends at " << (endTime / 3600) << ":" << ((endTime % 3600) / 60) << ":" << (endTime % 60);
		return formattedTime.str();
	}

	void Job::setTime(int newTime)
	{
		startTime = newTime;
	}

	void Job::setDay(int newDay)
	{
		day = newDay;
	}

	void Job::setMonth(int newMonth)
	{
		month = newMonth;
	}

	void Job::setYear(int newYear)
	{
		year = newYear;
	}

	void Job::setEmployer(Company newEmployer)
	{
	}

	Company Job::getEmployer() const
	{
		return employer;
	}

	void Job::setEnd(int newEnd)
	{
	}

	int Job::getEnd() const
	{
		return endTime;
	}

	void Job::setHours(int newHours)
	{
	}

	int Job::getHours() const
	{
		return hours;
	}

	void Job::setRate(float newRate)
	{
	}

	float Job::getRate() const
	{
		return rate;
	}

	void Job::createEntry()
	{
	}

	void Job::deleteEntry()
	{
	}

	void Job::updateEntry()
	{
	}

	void Job::readEntry(int row)
	{
	}
};
