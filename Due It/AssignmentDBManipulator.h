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
	void createCourse ( string, string, string, string, string );
	void createAssignment( string, string, string, string );
	void deleteCourse( string );
	void deleteAllAssignment( string );
	void deleteAssignment( string, string );
	void updateCourse();
	void updateAssignment();
	int readCourse( string );
	int readAssignment( string, string );
private:
	void initialize();
	void testConnection();
	sql::mysql::MySQL_Driver* driver;
	sql::Connection* connection;
	sql::Statement* statement;
	sql::PreparedStatement  *preparedStatement;
};

