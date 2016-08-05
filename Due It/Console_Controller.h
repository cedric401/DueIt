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
};

