#pragma once
#include "Task.h"
#include "Company.h"
namespace DueItModel
{
	class Payment :
		public Task
	{
	public:
		Payment(int startingTime, int workDay, int mnth, int yr, Company aCompany, double paymentAmount, bool paidStatus, std::string anAccountType);
		Payment(int dbRowID);
		~Payment();
		std::string toString();
		void setTime(int newTime);
		void setDay(int newDay);
		void setMonth(int newMonth);
		void setYear(int newYear);
		void setAmount(double newAmount);
		double getAmount();
		void setIsPaid(bool paidStatus);
		bool getIsPaid();
		void setCompany(Company aCompany);
		Company getCompany();
		void setAccountType(std::string newType);
		std::string getAccountType();

	private:
		double amount;
		bool isPaid;
		Company company;
		std::string accountType;
		int rowID;
		void createEntry();
		void deleteEntry();
		void updateEntry();
		void readEntry(int row);
	};
};

