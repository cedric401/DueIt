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
		if (!readCourse(cName))
		{
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
		else
		{
			cout << cName << ' ' << cNumber << cSection << " has not been added to the courses table. Course already exists." << endl;
			cin >> test;
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
	catch (std::runtime_error &e)
	{
		cout << "# ERR: runtime_error in " << __FILE__;
		cout << "(" << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what() << endl;
		cout << "not ok 1 - examples/resultset_types.cpp" << endl;
	}
}

/*****************************************************************************/
/*****************************************************************************/
void AssignmentDBManipulator::createAssignment(string aCourse, string aMaterial, string aName, string aDueDate)
{
	string test;
	int iD;

	if (aName.size() > 40)
	{
		aName = aName.substr(0, 40);
	}

	if (aDueDate.size() > 20)
	{
		aDueDate = aDueDate.substr(0, 20);
	}

	iD = readCourse(aCourse);

	try {
		if (iD)
		{
			preparedStatement = connection->prepareStatement(
				"INSERT INTO assignments(courseId, assignmentMaterial, assignmentName, assignmentDuedate) VALUES (?, ?, ?, ?)");
			preparedStatement->setInt(1, iD);
			preparedStatement->setString(2, aMaterial);
			preparedStatement->setString(3, aName);
			preparedStatement->setString(4, aDueDate);
			preparedStatement->execute();

			delete preparedStatement;

			cout << aMaterial << ' ' << aName << " has been added to the assignments table." << endl;
			cin >> test;
		}
		else
		{
			cout << aMaterial << ' ' << aName << " has not been added to the assignments table. id = 0" << endl;
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
	catch (std::runtime_error &e)
	{
		cout << "# ERR: runtime_error in " << __FILE__;
		cout << "(" << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what() << endl;
		cout << "not ok 1 - examples/resultset_types.cpp" << endl;
	}
}

/*****************************************************************************/
/*****************************************************************************/
void AssignmentDBManipulator::deleteCourse(int cId)
{
	try {
		/*
			TODO: 
			*	delete assignments tied to the course to be deleted.
			*	delete the course.
		*/
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
	catch (std::runtime_error &e)
	{
		cout << "# ERR: runtime_error in " << __FILE__;
		cout << "(" << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what() << endl;
		cout << "not ok 1 - examples/resultset_types.cpp" << endl;
	}
}

/*****************************************************************************/
/*****************************************************************************/
void AssignmentDBManipulator::deleteAssignment(int aId)
{
	try {
		/*
			TODO:
			*	delete assignment.
		*/
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
	catch (std::runtime_error &e)
	{
		cout << "# ERR: runtime_error in " << __FILE__;
		cout << "(" << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what() << endl;
		cout << "not ok 1 - examples/resultset_types.cpp" << endl;
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
	catch (std::runtime_error &e)
	{
		cout << "# ERR: runtime_error in " << __FILE__;
		cout << "(" << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what() << endl;
		cout << "not ok 1 - examples/resultset_types.cpp" << endl;
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
	catch (std::runtime_error &e)
	{
		cout << "# ERR: runtime_error in " << __FILE__;
		cout << "(" << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what() << endl;
		cout << "not ok 1 - examples/resultset_types.cpp" << endl;
	}
}

/*****************************************************************************/
/*****************************************************************************/
int AssignmentDBManipulator::readCourse(string course)
{
	int iD = 0;

	try {
		std::auto_ptr<sql::ResultSet> results(statement->executeQuery("SELECT courses.courseId, courses.courseName FROM courses"));

		while (results->next())
		{
			if (course == results->getString("courseName"))
			{
				iD = results->getInt("courseId");
			}
		}

		return iD;
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
	catch (std::runtime_error &e)
	{
		cout << "# ERR: runtime_error in " << __FILE__;
		cout << "(" << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what() << endl;
		cout << "not ok 1 - examples/resultset_types.cpp" << endl;
	}
}

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
	catch (std::runtime_error &e)
	{
		cout << "# ERR: runtime_error in " << __FILE__;
		cout << "(" << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what() << endl;
		cout << "not ok 1 - examples/resultset_types.cpp" << endl;
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
		connection->setSchema("school");
		//statement->execute("USE school");
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
	catch (std::runtime_error &e)
	{
		cout << "# ERR: runtime_error in " << __FILE__;
		cout << "(" << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what() << endl;
		cout << "not ok 1 - examples/resultset_types.cpp" << endl;
	}
}

/*****************************************************************************/
/*****************************************************************************/
void AssignmentDBManipulator::testConnection()
{
	string test;

	try
	{

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
	catch (sql::SQLException &e)
	{
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
	catch (std::runtime_error &e)
	{
		cout << "# ERR: runtime_error in " << __FILE__;
		cout << "(" << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what() << endl;
		cout << "not ok 1 - examples/resultset_types.cpp" << endl;
	}
}

