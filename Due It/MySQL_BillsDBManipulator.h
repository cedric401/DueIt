#pragma once
#include "BillsDBManipulator.h"
class MySQL_BillsDBManipulator :
	public BillsDBManipulator
{
public:
	MySQL_BillsDBManipulator();
	~MySQL_BillsDBManipulator();
	void addCompany(Company aCompany);
	void deleteCompany(Company aCompany);
	Company readCompany(std::string aName);
	void updateCompany(Company aCompany, std::string aName);
	void addJob(Job aJob);
	void deleteJob(Job aJob);
	Job* readJob(int rowID);
	void updateJob(Job aJob);
	void addPayment(Payment aPayment);
	void deletePayment(Payment aPayment);
	Payment* readPayment(int rowID);
	void updatePayment(Payment aPayment);
	std::vector<Task*> retrieveBillsInRange(int startTime = 0, int startDay = 1, int startMonth = 1, int startYear = 2000,
		int endTime = 86399, int endDay = 31, int endMonth = 12, int endYear = 2100);
private:
	void printSQLError(const std::string& func, int line, const std::string& error, int errorCode);
};

