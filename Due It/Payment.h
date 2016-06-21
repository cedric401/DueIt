#pragma once
#include "Task.h"
#include "Company.h"
namespace DueItModel
{
	class Payment :
		public Task
	{
	public:
		Payment(int startingTime, int paymentDay, int mnth, int yr, Company aCompany, double paymentAmount, bool paidStatus, std::string anAccountType);
		Payment(int dbRowID);
		~Payment();
		std::string toString();
		void setAmount(double newAmount);
		double getAmount() const;
		void setIsPaid(bool paidStatus);
		bool getIsPaid() const;
		void setCompany(Company aCompany);
		Company getCompany() const;
		void setAccountType(const std::string& newType);
		std::string getAccountType() const;
		bool operator==(const Payment& rhs);

	private:
		double amount; // amount < 0 if money is owed to company, amount > 0 if company is paying the user
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

