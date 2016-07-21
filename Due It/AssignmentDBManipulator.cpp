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
	string test;

	delete connection;
	delete statement;

	cout << endl << "Connection and statement has been deleted." << endl;
	cin >> test;
}

void AssignmentDBManipulator::createCourse(string cName, string cSubject, string cNumber, string cSection, string cSchedule)
{
	string test;

	preparedStatement = connection->prepareStatement(
		"INSERT INTO courses(courseName, courseSubject, courseNumber, courseSection, courseSchedule) VALUES (?, ?, ?, ?, ?)");
	preparedStatement->setString(1, cName);
	preparedStatement->setString(2, cSubject);
	preparedStatement->setString(3, cNumber);
	preparedStatement->setString(4, cSection);
	preparedStatement->setString(5, cSchedule);
	preparedStatement->execute();

	delete preparedStatement;

	cout << cName << ' ' << cNumber << cSection << " has been added to the courses table." << endl;
	cin >> test;
}

void AssignmentDBManipulator::createAssignment(int cId, string aMaterial, string aName, string aDueDate)
{
	string test;

	preparedStatement = connection->prepareStatement(
		"INSERT INTO assignments(courseId, assignmentMaterial, assignmentName, assignmentDuedate) VALUES (?, ?, ?, ?)");
	preparedStatement->setInt(1, cId);
	preparedStatement->setString(2, aMaterial);
	preparedStatement->setString(3, aName);
	preparedStatement->setString(4, aDueDate);
	preparedStatement->execute();

	delete preparedStatement;

	cout << aMaterial << ' ' << aName << " has been added to the assignments table." << endl;
	cin >> test;
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

/******************************************************************************
TODO: create a method that uses resultSets to determine the courseId of the
course the assignment is assigned to. replace the cID with the string
course name after creating the method. The method should compare the new
assignments course name with the courses of the database and then retrieve
the id from that tuple.
******************************************************************************/
void AssignmentDBManipulator::readAssignment(int row)
{
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


