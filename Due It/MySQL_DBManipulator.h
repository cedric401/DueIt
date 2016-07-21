#pragma once
#include "DBManipulator.h"
class MySQL_DBManipulator :
	public DBManipulator
{
public:
	MySQL_DBManipulator();
	~MySQL_DBManipulator();
	void addAssignment(AssignmentTask anAssignment);
	void deleteAssignment(AssignmentTask anAssignment);
	void readAssignment(AssignmentTask anAssignment);
	void updateAssignment(AssignmentTask anAssignment);
	void addCompany(Company aCompany);
	void deleteCompany(Company aCompany);
	void readCompany(Company aCompany);
	void updateCompany(Company aCompany);
	void addCourse(Course aCourse);
	void deleteCourse(Course aCourse);
	void readCourse(Course aCourse);
	void updateCourse(Course aCourse);
	void addCourseMeeting(CourseMeeting aMeeting);
	void deleteCourseMeeting(CourseMeeting aMeeting);
	void readCourseMeeting(CourseMeeting aMeeting);
	void updateCourseMeeting(CourseMeeting aMeeting);
	void addJob(Job aJob);
	void deleteJob(Job aJob);
	void readJob(Job aJob);
	void updateJob(Job aJob);
	void addPayment(Payment aPayment);
	void deletePayment(Payment aPayment);
	void readPayment(Payment aPayment);
	void updatePayment(Payment aPayment);
	std::vector<Task> retrieveTasksInRange(int startTime = 0, int startDay = 1, int startMonth = 1, int startYear = 2000,
		int endTime = 86399, int endDay = 31, int endMonth = 12, int endYear = 2100);

};

