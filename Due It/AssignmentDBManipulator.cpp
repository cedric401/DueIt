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
void AssignmentDBManipulator::deleteCourse(string cName)
{
	string test;

	try {
		deleteAllAssignment(cName);

		preparedStatement = connection->prepareStatement("DELETE FROM courses WHERE courses.courseName = ?");
		preparedStatement->setString(1, cName);
		preparedStatement->execute();

		delete preparedStatement;

		cout << cName << " has been deleted from the courses table." << endl;
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
void AssignmentDBManipulator::deleteAllAssignment(string cName)
{
	string test;

	try {
		preparedStatement = connection->prepareStatement(
			"DELETE FROM assignments WHERE assignments.courseId = ?");
		preparedStatement->setInt(1, readCourse(cName));
		preparedStatement->execute();

		delete preparedStatement;

		cout << cName << " assignments have been deleted from the assignments table." << endl;
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
void AssignmentDBManipulator::deleteAssignment(string cName, string aName)
{
	string test;

	try {
		preparedStatement = connection->prepareStatement(
			"DELETE FROM assignments WHERE assignments.courseId = ? AND assignments.assignmentId = ?");
		preparedStatement->setInt(1, readCourse(cName));
		preparedStatement->setInt(2, readAssignment(cName, aName));
		preparedStatement->execute();

		delete preparedStatement;

		cout << cName << "'s "<< aName << " assignment has been deleted from the table." << endl;
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
void AssignmentDBManipulator::updateCourseName(string course, string name)
{
	string test;

	try {
		preparedStatement = connection->prepareStatement("UPDATE courses SET courseName = ? WHERE courseId = ?");
		preparedStatement->setString(1, name);
		preparedStatement->setInt(2, readCourse(course));
		preparedStatement->execute();

		delete preparedStatement;

		cout << course << "'s name has been changed to " << name << " successfully." << endl;
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
void AssignmentDBManipulator::updateCourseSubject(string course, string subject)
{
	string test;

	try {
		preparedStatement = connection->prepareStatement("UPDATE courses SET courseSubject = ? WHERE courseId = ?");
		preparedStatement->setString(1, subject);
		preparedStatement->setInt(2, readCourse(course));
		preparedStatement->execute();

		delete preparedStatement;

		cout << course << "'s subject has been changed to " << subject << " successfully." << endl;
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
void AssignmentDBManipulator::updateCourseNumber(string course, string number)
{
	string test;

	try {
		preparedStatement = connection->prepareStatement("UPDATE courses SET courseNumber = ? WHERE courseId = ?");
		preparedStatement->setString(1, number);
		preparedStatement->setInt(2, readCourse(course));
		preparedStatement->execute();

		delete preparedStatement;

		cout << course << "'s number has been changed to " << number << " successfully." << endl;
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
void AssignmentDBManipulator::updateCourseSection(string course, string section)
{
	string test;

	try {
		preparedStatement = connection->prepareStatement("UPDATE courses SET courseSection = ? WHERE courseId = ?");
		preparedStatement->setString(1, section);
		preparedStatement->setInt(2, readCourse(course));
		preparedStatement->execute();

		delete preparedStatement;

		cout << course << "'s section has been changed to " << section << " successfully." << endl;
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
void AssignmentDBManipulator::updateCourseSchedule(string course, string schedule)
{
	string test;

	try {
		preparedStatement = connection->prepareStatement("UPDATE courses SET courseSchedule = ? WHERE courseId = ?");
		preparedStatement->setString(1, schedule);
		preparedStatement->setInt(2, readCourse(course));
		preparedStatement->execute();

		delete preparedStatement;

		cout << course << "'s schedule has been changed to " << schedule << " successfully." << endl;
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
void AssignmentDBManipulator::updateAssignmentCourseId(string course, string assignment, string newCourse)
{
	string test;

	try {
		preparedStatement = connection->prepareStatement(
			"UPDATE assignments SET courseId = ? WHERE courseId = ? AND assignmentName = ?");
		preparedStatement->setInt(1, readCourse(newCourse));
		preparedStatement->setInt(2, readCourse(course));
		preparedStatement->setInt(3, readAssignment(course, assignment));
		preparedStatement->execute();

		delete preparedStatement;

		cout << assignment << "'s course has been changed to " << newCourse << " successfully." << endl;
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
void AssignmentDBManipulator::updateAssignmentMaterial(string course, string assignment, string material)
{
	string test;

	try {
		preparedStatement = connection->prepareStatement(
			"UPDATE assignments SET assignmentMaterial = ? WHERE courseId = ? AND assignmentName = ?");
		preparedStatement->setString(1, material);
		preparedStatement->setInt(2, readCourse(course));
		preparedStatement->setInt(3, readAssignment(course, assignment));
		preparedStatement->execute();

		delete preparedStatement;

		cout << assignment << "'s material has been changed to " << material << " successfully." << endl;
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
void AssignmentDBManipulator::updateAssignmentName(string course, string assignment, string name)
{
	string test;

	try {
		preparedStatement = connection->prepareStatement(
			"UPDATE assignments SET assignmentName = ? WHERE courseId = ? AND assignmentName = ?");
		preparedStatement->setString(1, name);
		preparedStatement->setInt(2, readCourse(course));
		preparedStatement->setInt(3, readAssignment(course, assignment));
		preparedStatement->execute();

		delete preparedStatement;

		cout << assignment << "'s name has been changed to " << name << " successfully." << endl;
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
void AssignmentDBManipulator::updateAssignmentDueDate(string course, string assignment, string duedate)
{
	string test;

	try {
		preparedStatement = connection->prepareStatement(
			"UPDATE assignments SET assignmentDuedate = ? WHERE courseId = ? AND assignmentName = ?");
		preparedStatement->setString(1, duedate);
		preparedStatement->setInt(2, readCourse(course));
		preparedStatement->setInt(3, readAssignment(course, assignment));
		preparedStatement->execute();

		delete preparedStatement;

		cout << assignment << "'s duedate has been changed to " << duedate << " successfully." << endl;
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
		//std::auto_ptr<sql::ResultSet> results(statement->executeQuery("SELECT courses.courseId, courses.courseName FROM courses"));
		sql::ResultSet *results = statement->executeQuery("SELECT courses.courseId, courses.courseName FROM courses");

		while (results->next())
		{
			if (course == results->getString("courseName"))
			{
				iD = results->getInt("courseId");
			}
		}

		delete results;
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
int AssignmentDBManipulator::readAssignment(string course, string assignment)
{
	int aId = 0;
	int cId = readCourse(course);

	try {
		//std::auto_ptr<sql::ResultSet> results(statement->executeQuery(
			//"SELECT assignments.assignmentId, assignments.courseId, assignments.assignmentName FROM assignments"));
		sql::ResultSet *results = statement->executeQuery("SELECT assignments.assignmentId, assignments.courseId, assignments.assignmentName FROM assignments");

		while (results->next())
		{
			if ((cId == results->getInt("courseId")) && (assignment == results->getString("assignmentName")))
			{
				aId = results->getInt("assignmentId");
			}
		}

		delete results;
		return aId;
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

