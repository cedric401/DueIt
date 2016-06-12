#include "Payment.h"
#include <sstream>

namespace DueItModel
{
	Payment::Payment(int dbRowID)
	{
		readEntry(dbRowID);
		rowID = dbRowID;
	}


	Payment::Payment(int startingTime, int paymentDay, int mnth, int yr, Company aCompany, double paymentAmount, bool paidStatus, std::string anAccountType) 
		: Task(startingTime, paymentDay, mnth, yr)
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
		std::stringstream formattedTime;
		formattedTime << accountType << "payment of " << amount << " due at time: " << (startTime / 3600) << ":" << ((startTime % 3600) / 60) << ":" 
			<< (startTime % 60) << " on " << month << "/" << day << "/" << year << " to " << company.getCompanyName() << " and " << paymentStatus <<  ".\n";
		return formattedTime.str();
	}

	void Payment::setAmount(double newAmount)
	{
		amount = newAmount;
	}

	double Payment::getAmount()
	{
		return 0.0;
	}

	void Payment::setIsPaid(bool paidStatus)
	{
		isPaid = paidStatus;
	}

	bool Payment::getIsPaid()
	{
		return isPaid;
	}

	void Payment::setCompany(Company aCompany)
	{
		company = aCompany;
	}

	Company Payment::getCompany()
	{
		return company;
	}

	void Payment::setAccountType(std::string newType)
	{
		accountType = newType;
	}

	std::string Payment::getAccountType()
	{
		return accountType;
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