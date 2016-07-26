#include "BillsDBManipulator.h"



BillsDBManipulator::BillsDBManipulator()
{
}


BillsDBManipulator::~BillsDBManipulator()
{
}

void BillsDBManipulator::addCompany(Company aCompany)
{
}

void BillsDBManipulator::deleteCompany(Company aCompany)
{
}

Company BillsDBManipulator::readCompany(string aName)
{
}

void BillsDBManipulator::updateCompany(Company aCompany, string aName)
{
}

void BillsDBManipulator::addJob(Job aJob)
{
}

void BillsDBManipulator::deleteJob(Job aJob)
{
}

Job BillsDBManipulator::readJob(int rowID)
{
}

void BillsDBManipulator::updateJob(Job aJob)
{
}

void BillsDBManipulator::addPayment(Payment aPayment)
{
}

void BillsDBManipulator::deletePayment(Payment aPayment)
{
}

Payment BillsDBManipulator::readPayment(int rowID)
{
}

void BillsDBManipulator::updatePayment(Payment aPayment)
{
}

std::vector<Task> BillsDBManipulator::retrieveTasksInRange(int startTime, int startDay, int startMonth, int startYear, int endTime, int endDay, int endMonth, int endYear)
{
	return std::vector<Task>();
}
