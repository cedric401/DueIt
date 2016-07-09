#include "Payment.h"
#include <sstream>

namespace DueItModel
{
	Payment::Payment(int dbRowID)
	{
		readEntry(dbRowID);
		rowID = dbRowID;
	}


	Payment::Payment(int startingTime, int paymentDay, int mnth, int yr, bool repeating, int daysInterval, int monthsInterval, Company aCompany, double paymentAmount, bool paidStatus, std::string anAccountType) 
		: Task(startingTime, paymentDay, mnth, yr, repeating, daysInterval, monthsInterval)
	{
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
		std::string paymentStatus = "is not paid";
		if(isPaid)
		{
			paymentStatus = "is paid";
		}
		std::string repeatingStatus = "does not repeat";
		if (isRepeating)
		{
			std::stringstream repeatingSS;
			repeatingSS << "repeats every " << daysToRepeat << " days and " << monthsToRepeat << " months";
			repeatingStatus = repeatingSS.str();
			
		}
		std::stringstream formattedTime;
		formattedTime << accountType << " payment of " << amount << " due at time: " << (startTime / 3600) << ":" << ((startTime % 3600) / 60) << ":" 
			<< (startTime % 60) << " on " << month << "/" << day << "/" << year << " to " << company.getCompanyName() << " and " << paymentStatus 
			<< ". Payment " << repeatingStatus << ".\n";
		return formattedTime.str();
	}

	void Payment::repeat()
	{
		Task::repeat();
		isPaid = false;
	}

	void Payment::setAmount(double newAmount)
	{
		amount = newAmount;
	}

	double Payment::getAmount() const
	{
		return amount;
	}

	void Payment::setIsPaid(bool paidStatus)
	{
		isPaid = paidStatus;
	}

	bool Payment::getIsPaid() const
	{
		return isPaid;
	}

	void Payment::setCompany(Company aCompany)
	{
		company = aCompany;
	}

	Company Payment::getCompany() const
	{
		return company;
	}

	void Payment::setAccountType(const std::string& newType)
	{
		accountType = newType;
	}

	std::string Payment::getAccountType() const
	{
		return accountType;
	}

	bool Payment::operator==(const Payment & rhs)
	{
		if (startTime == rhs.getTime() && day == rhs.getDay() && month == rhs.getMonth() && year == rhs.getYear() && isRepeating == rhs.getIsRepeating()
			&& daysToRepeat == rhs.getDaysToRepeat() && monthsToRepeat == rhs.getMonthsToRepeat() && amount == rhs.getAmount() &&
			isPaid == rhs.getIsPaid() && accountType == rhs.getAccountType() && company == rhs.getCompany())
		{
			return true;
		}
		return false;
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