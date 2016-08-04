#pragma once
#include "BillsDBManipulator.h"
#include "AssignmentDBManipulator.h"

class DBManipulator
{
public:
	DBManipulator();
	~DBManipulator();
	BillsDBManipulator* billsDBmanip;
	AssignmentDBManipulator* assignmentDBmanip;
	std::vector<Task*> retrieveTasksInRange(int startTime = 0, int startDay = 1, int startMonth = 1, int startYear = 2000,
		int endTime = 86399, int endDay = 31, int endMonth = 12, int endYear = 2100);
	void addEntry(const AssignmentTask* anAssignment);
	void addEntry(const CourseMeeting* aCourseMeeting);
	void addEntry(const Job* aJob);
	void addEntry(const Payment* aPayment);
	void deleteEntry(const AssignmentTask* anAssignment);
	void deleteEntry(const CourseMeeting* aCourseMeeting);
	void deleteEntry(const Job* aJob);
	void deleteEntry(const Payment* aPayment);
	void updateEntry(const AssignmentTask* anAssignment);
	void updateEntry(const CourseMeeting* aCourseMeeting);
	void updateEntry(const Job* aJob);
	void updateEntry(const Payment* aPayment);
};

