#pragma once
#include "Schedule.h"
using namespace DueItModel;
class Console_Controller
{
public:
	Console_Controller(Schedule* model);
	~Console_Controller();
private:
	Schedule* tasks;
	void printTime();
	void createPayment();
	void createTask();
	void createJob();
	void createAssignment();
	void createCourseMeeting();
	Company createCompany();
	void deleteTask();
	void updateTask();
	void updatePayment(Payment* aPayment);
	void updateJob(Job* aJob);
	void updateAssignment(AssignmentTask* anAssignment);
	void updateCourseMeeting(CourseMeeting* aMeeting);
	int getInt();
};

