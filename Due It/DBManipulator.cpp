#include "DBManipulator.h"
#include "MySQL_BillsDBManipulator.h"

DBManipulator::DBManipulator()
{
	billsDBmanip = new MySQL_BillsDBManipulator();
	assignmentDBmanip = new AssignmentDBManipulator();
}


DBManipulator::~DBManipulator()
{
}

std::vector<Task*> DBManipulator::retrieveTasksInRange(int startTime, int startDay, int startMonth, int startYear, int endTime, int endDay, int endMonth, int endYear)
{
	std::vector<Task*> tasks = billsDBmanip->retrieveBillsInRange(startTime, startDay, startMonth, startYear, endTime, endDay, endMonth, endYear);
	//std::vector<Task*> assignments = assignmentDBmanip->retrieveAssignmentsInRange(startTime, startDay, startMonth, startYear, endTime, endDay, endMonth, endYear);
	//tasks.insert(tasks.end(), assignments.begin(), assignments.end());
	return tasks;
}

void DBManipulator::addEntry(const AssignmentTask* anAssignment)
{
}

void DBManipulator::addEntry(const CourseMeeting* aCourseMeeting)
{
}

void DBManipulator::addEntry(const Job* aJob)
{
	billsDBmanip->addJob(*aJob);
}

void DBManipulator::addEntry(const Payment* aPayment)
{
	billsDBmanip->addPayment(*aPayment);
}

void DBManipulator::deleteEntry(const AssignmentTask* anAssignment)
{
}

void DBManipulator::deleteEntry(const CourseMeeting* aCourseMeeting)
{
}

void DBManipulator::deleteEntry(const Job* aJob)
{
	billsDBmanip->deleteJob(*aJob);
}

void DBManipulator::deleteEntry(const Payment* aPayment)
{
	billsDBmanip->deletePayment(*aPayment);
}

void DBManipulator::updateEntry(const AssignmentTask* anAssignment)
{
}

void DBManipulator::updateEntry(const CourseMeeting* aCourseMeeting)
{
}

void DBManipulator::updateEntry(const Job* aJob)
{
	billsDBmanip->updateJob(*aJob);
}

void DBManipulator::updateEntry(const Payment* aPayment)
{
	billsDBmanip->updatePayment(*aPayment);
}
