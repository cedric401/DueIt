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

class DBManipulator
{
public:
	DBManipulator();
	~DBManipulator();
	virtual void addAssignment(AssignmentTask anAssignment);
	virtual void deleteAssignment(AssignmentTask anAssignment);
	virtual void readAssignment(AssignmentTask anAssignment);
	virtual void updateAssignment(AssignmentTask anAssignment);
	virtual void addCompany(Company aCompany);
	virtual void deleteCompany(Company aCompany);
	virtual void readCompany(Company aCompany);
	virtual void updateCompany(Company aCompany);
	virtual void addCourse(Course aCourse);
	virtual void deleteCourse(Course aCourse);
	virtual void readCourse(Course aCourse);
	virtual void updateCourse(Course aCourse);
	virtual void addCourseMeeting(CourseMeeting aMeeting);
	virtual void deleteCourseMeeting(CourseMeeting aMeeting);
	virtual void readCourseMeeting(CourseMeeting aMeeting);
	virtual void updateCourseMeeting(CourseMeeting aMeeting);
	virtual void addJob(Job aJob);
	virtual void deleteJob(Job aJob);
	virtual void readJob(Job aJob);
	virtual void updateJob(Job aJob);
	virtual void addPayment(Payment aPayment);
	virtual void deletePayment(Payment aPayment);
	virtual void readPayment(Payment aPayment);
	virtual void updatePayment(Payment aPayment);
	virtual std::vector<Task> retrieveTasksInRange(int startTime = 0, int startDay = 1, int startMonth = 1, int startYear = 2000,
													int endTime = 86399, int endDay = 31, int endMonth = 12, int endYear = 2100);

};

