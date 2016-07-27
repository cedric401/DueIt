#pragma once
#include <vector>
#include "AssignmentTask.h"
#include "Company.h"
#include "Course.h"
#include "CourseMeeting.h"
#include "Job.h"
#include "Payment.h"
#include "Task.h"

using namespace DueItModel;

class BillsDBManipulator
{
public:
	BillsDBManipulator();
	~BillsDBManipulator();
	virtual void addCompany(Company aCompany);
	virtual void deleteCompany(Company aCompany);
	virtual Company readCompany(std::string aName) = 0;
	virtual void updateCompany(Company aCompany, std::string aName);
	virtual void addJob(Job aJob);
	virtual void deleteJob(Job aJob);
	virtual Job* readJob(int rowID) = 0;
	virtual void updateJob(Job aJob);
	virtual void addPayment(Payment aPayment);
	virtual void deletePayment(Payment aPayment);
	virtual Payment* readPayment(int rowID) = 0;
	virtual void updatePayment(Payment aPayment);
	virtual std::vector<Task> retrieveTasksInRange(int startTime = 0, int startDay = 1, int startMonth = 1, int startYear = 2000,
													int endTime = 86399, int endDay = 31, int endMonth = 12, int endYear = 2100) = 0;

};

