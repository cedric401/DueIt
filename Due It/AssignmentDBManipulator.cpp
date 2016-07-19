#include "AssignmentDBManipulator.h"



AssignmentDBManipulator::AssignmentDBManipulator()
{
	initialize();
}


AssignmentDBManipulator::~AssignmentDBManipulator()
{
}

void AssignmentDBManipulator::terminateConnection()
{
	delete connection;
	delete statement;
}

void AssignmentDBManipulator::initialize()
{
	driver = sql::mysql::get_mysql_driver_instance();
	connection = driver->connect("tcp://127.0.0.1:3306", "root", "mysql");
	testConnection();

	statement = connection->createStatement();
	statement->execute("USE school");
}

void AssignmentDBManipulator::testConnection()
{
	string test;

	if (connection->isValid())
	{
		cout << "Connection was successfull!!" << endl;
		cin >> test;
	}
	else
	{
		cout << "Connection was not successfull. :(" << endl << "Reconnecting.";
		cin >> test;

		connection->reconnect();
		testConnection();
	}
}

void AssignmentDBManipulator::createCourse()
{

}

void AssignmentDBManipulator::createAssignment()
{
}

void AssignmentDBManipulator::deleteCourse()
{
}

void AssignmentDBManipulator::deleteAssignment()
{
}

void AssignmentDBManipulator::updateCourse()
{
}

void AssignmentDBManipulator::updateAssignment()
{
}

void AssignmentDBManipulator::readCourse(int row)
{
}

void AssignmentDBManipulator::readAssignment(int row)
{
}
