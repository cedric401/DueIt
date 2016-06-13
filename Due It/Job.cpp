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
		: Task(startingTime, workDay, mnth, yr)
	{
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
			switch (month)
			{
			case 1: 
				if (endDay > 31)
				{
					endMonth = 2;
					endDay = 1;
				}
				break;
			case 2:
				if ((endDay > 28 && year % 4 != 0) || endDay > 29)
				{
					endMonth = 3;
					endDay = 1;
				}
				break;
			case 3:
				if (endDay > 31)
				{
					endMonth = 4;
					endDay = 1;
				}
				break;
			case 4:
				if (endDay > 30)
				{
					endMonth = 5;
					endDay = 1;
				}
				break;
			case 5:
				if (endDay > 31)
				{
					endMonth = 6;
					endDay = 1;
				}
				break;
			case 6:
				if (endDay > 30)
				{
					endMonth = 7;
					endDay = 1;
				}
				break;
			case 7:
				if (endDay > 31)
				{
					endMonth = 8;
					endDay = 1;
				}
				break;
			case 8:
				if (endDay > 31)
				{
					endMonth = 9;
					endDay = 1;
				}
				break;
			case 9:
				if (endDay > 30)
				{
					endMonth = 10;
					endDay = 1;
				}
				break;
			case 10:
				if (endDay > 31)
				{
					endMonth = 11;
					endDay = 1;
				}
				break;
			case 11:
				if (endDay > 30)
				{
					endMonth = 12;
					endDay = 1;
				}
				break;
			case 12:
				if (endDay > 31)
				{
					endYear++;
					endMonth = 1;
					endDay = 1;
				}
				break;
			}
		}
		std::stringstream formattedTime;
		formattedTime << "Shift beginning time: " << (startTime / 3600) << ":" << ((startTime % 3600) / 60) << ":" << (startTime % 60) <<
			" on " << month << "/" << day << "/" << year << " and ends at " << (endTime / 3600) << ":" << ((endTime % 3600) / 60) << ":" 
			<< (endTime % 60) << " on " << endMonth << "/" << endDay << "/" << endYear << "\n";
		return formattedTime.str();
	}

	void Job::setEmployer(Company newEmployer)
	{
		employer = newEmployer;
	}

	Company Job::getEmployer() const
	{
		return employer;
	}

	void Job::setEnd(int newEnd)
	{
		if (endTime > startTime)
		{
			endTime = newEnd;
		}
	}

	int Job::getEnd() const
	{
		return endTime;
	}

	void Job::setHours(int newHours)
	{
		if (newHours > 0)
		{
			hours = newHours;
		}
	}

	int Job::getHours() const
	{
		return hours;
	}

	void Job::setRate(float newRate)
	{
		if (newRate >= 0)
		{
			rate = newRate;
		}
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
