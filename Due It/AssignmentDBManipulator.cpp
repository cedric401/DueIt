#include "AssignmentDBManipulator.h"



AssignmentDBManipulator::AssignmentDBManipulator()
{
	initialize();
}


AssignmentDBManipulator::~AssignmentDBManipulator()
{
}

/*****************************************************************************/
/*****************************************************************************/
void AssignmentDBManipulator::terminateConnection()
{
	string test;

	delete connection;
	delete statement;

	cout << endl << "Connection and statement has been deleted." << endl;
	cin >> test;
}

/*****************************************************************************/
/*****************************************************************************/
void AssignmentDBManipulator::createCourse(string cName, string cSubject, string cNumber, string cSection, string cSchedule)
{
	string test;

	if (cName.size() > 100)
	{
		cName = cName.substr(0, 100);
	}

	if (cSubject.size() > 40)
	{
		cSubject = cSubject.substr(0, 40);
	}

	if (cNumber.size() > 20)
	{
		cNumber = cNumber.substr(0, 20);
	}

	if (cSection.size() > 10)
	{
		cSection = cSection.substr(0, 10);
	}

	try {
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
	catch (sql::SQLException &e) {
		/*
		MySQL Connector/C++ throws three different exceptions:

		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)
		*/
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		/* what() (derived from std::runtime_error) fetches error message */
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}
}

/*****************************************************************************/
/*****************************************************************************/
void AssignmentDBManipulator::createAssignment(int cId, string aMaterial, string aName, string aDueDate)
{
	string test;

	if (aName.size() > 40)
	{
		aName = aName.substr(0, 40);
	}

	if (aDueDate.size() > 20)
	{
		aDueDate = aDueDate.substr(0, 20);
	}

	try {
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
	catch (sql::SQLException &e) {
		/*
		MySQL Connector/C++ throws three different exceptions:

		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)
		*/
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		/* what() (derived from std::runtime_error) fetches error message */
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}
}

/*****************************************************************************/
/*****************************************************************************/
void AssignmentDBManipulator::deleteCourse()
{
	try {

	}
	catch (sql::SQLException &e) {
		/*
		MySQL Connector/C++ throws three different exceptions:

		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)
		*/
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		/* what() (derived from std::runtime_error) fetches error message */
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}
}

/*****************************************************************************/
/*****************************************************************************/
void AssignmentDBManipulator::deleteAssignment()
{
	try {

	}
	catch (sql::SQLException &e) {
		/*
		MySQL Connector/C++ throws three different exceptions:

		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)
		*/
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		/* what() (derived from std::runtime_error) fetches error message */
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}
}

/*****************************************************************************/
/*****************************************************************************/
void AssignmentDBManipulator::updateCourse()
{
	try {

	}
	catch (sql::SQLException &e) {
		/*
		MySQL Connector/C++ throws three different exceptions:

		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)
		*/
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		/* what() (derived from std::runtime_error) fetches error message */
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}
}

/*****************************************************************************/
/*****************************************************************************/
void AssignmentDBManipulator::updateAssignment()
{
	try {

	}
	catch (sql::SQLException &e) {
		/*
		MySQL Connector/C++ throws three different exceptions:

		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)
		*/
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		/* what() (derived from std::runtime_error) fetches error message */
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}
}

/*****************************************************************************/
/*****************************************************************************/
void AssignmentDBManipulator::readCourse(int row)
{
	try {

	}
	catch (sql::SQLException &e) {
		/*
		MySQL Connector/C++ throws three different exceptions:

		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)
		*/
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		/* what() (derived from std::runtime_error) fetches error message */
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}
}

/******************************************************************************
TODO: create a method that uses resultSets to determine the courseId of the
course the assignment is assigned to. replace the cID with the string
course name after creating the method. The method should compare the new
assignments course name with the courses of the database and then retrieve
the id from that tuple.
******************************************************************************/

/*****************************************************************************/
/*****************************************************************************/
void AssignmentDBManipulator::readAssignment(int row)
{
	try {

	}
	catch (sql::SQLException &e) {
		/*
		MySQL Connector/C++ throws three different exceptions:

		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)
		*/
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		/* what() (derived from std::runtime_error) fetches error message */
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}
}

/*****************************************************************************/
/*****************************************************************************/
void AssignmentDBManipulator::initialize()
{
	

	try {
		driver = sql::mysql::get_mysql_driver_instance();
		connection = driver->connect("tcp://127.0.0.1:3306", "root", "mysql");
		testConnection();
		statement = connection->createStatement();


		statement->execute("USE school");
	}
	catch (sql::SQLException &e) {
		/*
		MySQL Connector/C++ throws three different exceptions:

		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)
		*/
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		/* what() (derived from std::runtime_error) fetches error message */
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}
}

/*****************************************************************************/
/*****************************************************************************/
void AssignmentDBManipulator::testConnection()
{
	string test;

	try {

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
	catch (sql::SQLException &e) {
		/*
		MySQL Connector/C++ throws three different exceptions:

		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)
		*/
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		/* what() (derived from std::runtime_error) fetches error message */
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}
}


