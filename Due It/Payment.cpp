#include "Payment.h"
#include <sstream>

namespace DueItModel
{
	Payment::Payment(int dbRowID)
	{
		readEntry(dbRowID);
		rowID = dbRowID;
	}


	Payment::Payment(int startingTime, int workDay, int mnth, int yr, Company aCompany, double paymentAmount, bool paidStatus, std::string anAccountType)
	{
		startTime = startingTime;
		day = workDay;
		month = mnth;
		year = yr;
		company = aCompany;
		amount = paymentAmount;
		isPaid = paidStatus;
		accountType = anAccountType;
	}

	Payment::~Payment()
	{
	}

	std::string Payment::toString()
	{
		std::stringstream formattedTime;
		formattedTime << "Payment due at time: " << (startTime / 3600) << ":" << ((startTime % 3600) / 60) << ":" << (startTime % 60) <<
			" on " << month << "/" << day << "/" << year << "\n";
		return formattedTime.str();
	}

	void Payment::setTime(int newTime)
	{
		startTime = newTime;
	}

	void Payment::setDay(int newDay)
	{
		day = newDay;
	}

	void Payment::setMonth(int newMonth)
	{
		month = newMonth;
	}

	void Payment::setYear(int newYear)
	{
		year = newYear;
	}

	void Payment::setAmount(double newAmount)
	{
	}

	double Payment::getAmount()
	{
		return 0.0;
	}

	void Payment::setIsPaid(bool paidStatus)
	{
	}

	bool Payment::getIsPaid()
	{
		return false;
	}

	void Payment::setCompany(Company aCompany)
	{
	}

	Company Payment::getCompany()
	{
		return company;
	}

	void Payment::setAccountType(std::string newType)
	{
	}

	std::string Payment::getAccountType()
	{
		return std::string();
	}

	void Payment::createEntry()
	{
	}

	void Payment::deleteEntry()
	{
	}

	void Payment::updateEntry()
	{
	}

	void Payment::readEntry(int row)
	{
	}


};