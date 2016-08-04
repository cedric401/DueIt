#pragma once
#include "Task.h"
#include "Company.h"
namespace DueItModel
{
	class Payment :
		public Task
	{
	public:
		Payment(int startingTime, int paymentDay, int mnth, int yr, bool repeating, int daysInterval, int monthsInterval, Company aCompany, double paymentAmount, bool paidStatus, std::string anAccountType);
		Payment(int startingTime, int paymentDay, int mnth, int yr, bool repeating, int daysInterval, int monthsInterval, Company aCompany, double paymentAmount, bool paidStatus, std::string anAccountType, int id);
		~Payment();
		std::string toString();
		void repeat();
		void setAmount(double newAmount);
		double getAmount() const;
		void setIsPaid(bool paidStatus);
		bool getIsPaid() const;
		void setCompany(Company aCompany);
		Company getCompany() const;
		void setAccountType(const std::string& newType);
		std::string getAccountType() const;
		int getRowID();
		bool operator==(const Payment& rhs);
		void createEntry();
		void deleteEntry();
		void updateEntry();
		void readEntry(int row);

	private:
		double amount; // amount < 0 if money is owed to company, amount > 0 if company is paying the user
		bool isPaid;
		Company company;
		std::string accountType;
	};
};

