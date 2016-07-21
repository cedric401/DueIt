#include <stdlib.h>
#include <iostream>
#include "MySQL_DBManipulator.h"
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>


#define HOST "localhost:3306"
#define USER "root"
#define PASSWORD "mysql"
#define DB "blank"

using namespace std;

MySQL_DBManipulator::MySQL_DBManipulator()
{
	sql::Driver *driver;
	sql::Connection *con;
	sql::Statement *stmt;
	sql::ResultSet *res;
	sql::PreparedStatement *prep;

	driver = get_driver_instance();
	con = driver->connect(HOST, USER, PASSWORD);

	stmt = con->createStatement();
	stmt->execute("USE " DB);
	try
	{
		stmt->execute("INSERT INTO Company(companyName, companyAddress) VALUES ('cbf', '325 side street')");
	}
	catch (sql::SQLException &e) 
	{
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line "
			<< __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() <<
			" )" << endl;
	}

	res = stmt->executeQuery("SELECT companyName, companyAddress FROM Company ORDER BY companyAddress ASC");
	while (res->next())
	{
		cout << "Company: " << res->getString("companyName").c_str();
		cout << ", Address: " << res->getString("companyAddress").c_str() << "\n";
	}

	prep = con->prepareStatement("INSERT INTO Company(companyName, companyAddress) VALUES (?, ?)");
	try
	{
		prep->setString(1, "mcdonalds");
		prep->setString(2, "123 main street");
		prep->execute();
	}
	catch (sql::SQLException e)
	{
		cout << "ERROR: ";
		cout << e.getErrorCode() << "\n";
	}

	delete prep;
	delete res;
	delete stmt;
	delete con;
}

MySQL_DBManipulator::~MySQL_DBManipulator()
{
}

void MySQL_DBManipulator::addAssignment(AssignmentTask anAssignment)
{
}

void MySQL_DBManipulator::deleteAssignment(AssignmentTask anAssignment)
{
}

void MySQL_DBManipulator::readAssignment(AssignmentTask anAssignment)
{
}

void MySQL_DBManipulator::updateAssignment(AssignmentTask anAssignment)
{
}

void MySQL_DBManipulator::addCompany(Company aCompany)
{
}

void MySQL_DBManipulator::deleteCompany(Company aCompany)
{
}

void MySQL_DBManipulator::readCompany(Company aCompany)
{
}

void MySQL_DBManipulator::updateCompany(Company aCompany)
{
}

void MySQL_DBManipulator::addCourse(Course aCourse)
{
}

void MySQL_DBManipulator::deleteCourse(Course aCourse)
{
}

void MySQL_DBManipulator::readCourse(Course aCourse)
{
}

void MySQL_DBManipulator::updateCourse(Course aCourse)
{
}

void MySQL_DBManipulator::addCourseMeeting(CourseMeeting aMeeting)
{
}

void MySQL_DBManipulator::deleteCourseMeeting(CourseMeeting aMeeting)
{
}

void MySQL_DBManipulator::readCourseMeeting(CourseMeeting aMeeting)
{
}

void MySQL_DBManipulator::updateCourseMeeting(CourseMeeting aMeeting)
{
}

void MySQL_DBManipulator::addJob(Job aJob)
{
}

void MySQL_DBManipulator::deleteJob(Job aJob)
{
}

void MySQL_DBManipulator::readJob(Job aJob)
{
}

void MySQL_DBManipulator::updateJob(Job aJob)
{
}

void MySQL_DBManipulator::addPayment(Payment aPayment)
{
}

void MySQL_DBManipulator::deletePayment(Payment aPayment)
{
}

void MySQL_DBManipulator::readPayment(Payment aPayment)
{
}

void MySQL_DBManipulator::updatePayment(Payment aPayment)
{
}

std::vector<Task> MySQL_DBManipulator::retrieveTasksInRange(int startTime, int startDay, int startMonth, int startYear, int endTime, int endDay, int endMonth, int endYear)
{
	return std::vector<Task>();
}
