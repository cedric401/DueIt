#pragma once
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <stdexcept>

#include <mysql_connection.h>
#include <mysql_driver.h>
#include <mysql_error.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

using namespace std;

class AssignmentDBManipulator
{
public:
	AssignmentDBManipulator();
	~AssignmentDBManipulator();
	void terminateConnection();
private:
	void initialize();
	void testConnection();
	void createCourse();
	void createAssignment();
	void deleteCourse();
	void deleteAssignment();
	void updateCourse();
	void updateAssignment();
	void readCourse(int row);
	void readAssignment(int row);

	sql::mysql::MySQL_Driver* driver;
	sql::Connection* connection;
	sql::Statement* statement;
};

