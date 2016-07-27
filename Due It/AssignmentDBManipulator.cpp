#include "AssignmentDBManipulator.h"



AssignmentDBManipulator::AssignmentDBManipulator()
{
	initialize();
}

AssignmentDBManipulator::~AssignmentDBManipulator()
{
}

/******************************************************************************
	Disconnects from the database.
******************************************************************************/
void AssignmentDBManipulator::terminateConnection()
{
	string test;

	delete connection;
	delete statement;

	cout << endl << "Connection and statement has been deleted." << endl;
	cin >> test;
}

/*****************************************************************************
	Creates a new course with the information given.
	@cName, course name.
	@cSubject, course subject.
	@cNumber, course number.
	@cSection, course section.
	@cSchedule, course schedule.
******************************************************************************/
void AssignmentDBManipulator::createCourse(string cName, string cSubject, 
							string cNumber, string cSection, string cSchedule)
{
	int cID = readCourse(cName);

	/*
		Matches the values with the typing of the database columns.
	*/
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

	/*
		Creates the course if the course doesn't exist.
	*/
	if (!cID)
	{
		try 
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
			cin;
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
	else
	{
		cout << "Course was not created, course already exists." << endl;
		cin;
	}
}

/*****************************************************************************
	Creates a new assignment assigned to a course.
	@aCourse, course of the assignment.
	@aMaterial, test, paper, quiz, etc..
	@aName, name of the assignment.
	@aDueDate, date the assignment is due.
******************************************************************************/
void AssignmentDBManipulator::createAssignment(string aCourse, string aMaterial, 
												string aName, string aDueDate)
{
	int courseId;
	int assignmentId;

	/*
		Matches the values with the database typing.
	*/
	if (aName.size() > 40)
	{
		aName = aName.substr(0, 40);
	}

	if (aDueDate.size() > 20)
	{
		aDueDate = aDueDate.substr(0, 20);
	}

	courseId = readCourse(aCourse);
	assignmentId = readAssignment(aCourse, aName);

	/*
		Assignment is created when the course exists and the assignment doesn't.
	*/
	if ((courseId) && (!assignmentId))
	{
		try 
		{
			preparedStatement = connection->prepareStatement(
				"INSERT INTO assignments(courseId, assignmentMaterial, assignmentName, assignmentDuedate) VALUES (?, ?, ?, ?)");
			preparedStatement->setInt(1, courseId);
			preparedStatement->setString(2, aMaterial);
			preparedStatement->setString(3, aName);
			preparedStatement->setString(4, aDueDate);
			preparedStatement->execute();

			delete preparedStatement;

			cout << aMaterial << ' ' << aName << " has been added to the assignments table." << endl;
			cin;
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
	else
	{
		cout << "Assignment hasn't been created. Either course doesn't exist or assignment already exists." << endl;
		cin;
	}
}

/*****************************************************************************
	Deletes a course from the database after deleting assignments that are 
	associated to the course.
	@cName, course to be deleted.
******************************************************************************/
void AssignmentDBManipulator::deleteCourse(string cName)
{
	int cID = readCourse(cName);

	if (cID)
	{
		try 
		{
			deleteAllAssignment(cName);

			preparedStatement = connection->prepareStatement("DELETE FROM courses WHERE courses.courseName = ?");
			preparedStatement->setString(1, cName);
			preparedStatement->execute();

			delete preparedStatement;

			cout << cName << " has been deleted from the courses table." << endl;
			cin;
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
	else
	{
		cout << "Assignment was not deleted." << endl;
		cin;
	}
}

/*****************************************************************************
	Deletes all assignments for a given course.
	@cName, course the will have 0 assignments.
******************************************************************************/
void AssignmentDBManipulator::deleteAllAssignment(string cName)
{
	int cID = readCourse(cName);

	if (cID)
	{
		try 
		{
			preparedStatement = connection->prepareStatement(
				"DELETE FROM assignments WHERE assignments.courseId = ?");
			preparedStatement->setInt(1, cID);
			preparedStatement->execute();

			delete preparedStatement;

			cout << cName << " assignments have been deleted from the assignments table." << endl;
			cin;
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
	else
	{
		cout << "Assignments have not been deleted because the course doesn't exist." << endl;
		cin;
	}
}

/*****************************************************************************
	Deletes an individual assignment.
	@cName, name of the course the assignment belongs to.
	@aName, name of the assignment to be deleted.
******************************************************************************/
void AssignmentDBManipulator::deleteAssignment(string cName, string aName)
{
	int cID = readCourse(cName);
	int aID = readAssignment(cName, aName);
	
	if ((cID) && (aID))
	{
		try 
		{
			preparedStatement = connection->prepareStatement(
				"DELETE FROM assignments WHERE assignments.courseId = ? AND assignments.assignmentId = ?");
			preparedStatement->setInt(1, cID);
			preparedStatement->setInt(2, aID);
			preparedStatement->execute();

			delete preparedStatement;

			cout << cName << "'s " << aName << " assignment has been deleted from the table." << endl;
			cin;
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
	else
	{
		cout << "The assignment has not been deleted, either course or assignment doesn't exist." << endl;
		cin;
	}
}

/*****************************************************************************
	Change the name of a course.
	@course, name of the course to be changed.
	@name, the new name of the course.
******************************************************************************/
void AssignmentDBManipulator::updateCourseName(string course, string name)
{
	int cID = readCourse(course);

	if (cID)
	{
		try 
		{
			preparedStatement = connection->prepareStatement("UPDATE courses SET courseName = ? WHERE courseId = ?");
			preparedStatement->setString(1, name);
			preparedStatement->setInt(2, cID);
			preparedStatement->execute();

			delete preparedStatement;

			cout << course << "'s name has been changed to " << name << " successfully." << endl;
			cin;
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
	else
	{
		cout << "Course name not updated because course doesn't exist." << endl;
		cin;
	}
}

/*****************************************************************************
	Change the subject of a course.
	@course, name of the course to be changed.
	@subject, the new subject of the course.
******************************************************************************/
void AssignmentDBManipulator::updateCourseSubject(string course, string subject)
{
	int cID = readCourse(course);

	if (cID)
	{
		try 
		{
			preparedStatement = connection->prepareStatement("UPDATE courses SET courseSubject = ? WHERE courseId = ?");
			preparedStatement->setString(1, subject);
			preparedStatement->setInt(2, cID);
			preparedStatement->execute();

			delete preparedStatement;

			cout << course << "'s subject has been changed to " << subject << " successfully." << endl;
			cin;
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
	else
	{
		cout << "Course subject not updated because course doesn't exist." << endl;
		cin;
	}
}

/*****************************************************************************
	Change the number of a course.
	@course, name of the course to be changed.
	@number, the new number of the course.
******************************************************************************/
void AssignmentDBManipulator::updateCourseNumber(string course, string number)
{
	int cID = readCourse(course);

	if (cID)
	{
		try 
		{
			preparedStatement = connection->prepareStatement("UPDATE courses SET courseNumber = ? WHERE courseId = ?");
			preparedStatement->setString(1, number);
			preparedStatement->setInt(2, cID);
			preparedStatement->execute();

			delete preparedStatement;

			cout << course << "'s number has been changed to " << number << " successfully." << endl;
			cin;
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
	else
	{
		cout << "Course number not updated, course doesn't exist." << endl;
		cin;
	}
}

/*****************************************************************************
	Change the section of a course.
	@course, name of the course to be changed.
	@section, the new section of the course.
******************************************************************************/
void AssignmentDBManipulator::updateCourseSection(string course, string section)
{
	int cID = readCourse(course);

	if (cID)
	{
		try
		{
			preparedStatement = connection->prepareStatement("UPDATE courses SET courseSection = ? WHERE courseId = ?");
			preparedStatement->setString(1, section);
			preparedStatement->setInt(2, cID);
			preparedStatement->execute();

			delete preparedStatement;

			cout << course << "'s section has been changed to " << section << " successfully." << endl;
			cin;
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
	else
	{
		cout << "Course section not updated, course doesn't exist." << endl;
		cin;
	}
}

/*****************************************************************************
	Change the schedule of a course.
	@course, name of the course to be changed.
	@schedule, the new schedule of the course.
******************************************************************************/
void AssignmentDBManipulator::updateCourseSchedule(string course, string schedule)
{
	int cID = readCourse(course);

	if (cID)
	{
		try 
		{
			preparedStatement = connection->prepareStatement("UPDATE courses SET courseSchedule = ? WHERE courseId = ?");
			preparedStatement->setString(1, schedule);
			preparedStatement->setInt(2, cID);
			preparedStatement->execute();

			delete preparedStatement;

			cout << course << "'s schedule has been changed to " << schedule << " successfully." << endl;
			cin;
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
	else
	{
		cout << "Course schedule not updated, course doesn't exist." << endl;
		cin;
	}
}

/*****************************************************************************
	Change the course id of an assignment.
	@course, the name of the course of the assignment.
	@assignment, the name of the assignment.
	@newCourse, the name of the course the assignment will be moved to.
******************************************************************************/
void AssignmentDBManipulator::updateAssignmentCourseId(string course, 
											string assignment, string newCourse)
{
	int cID = readCourse(course);
	int newCID = readCourse(newCourse);
	int aID = readAssignment(course, assignment);

	if ((cID) && (newCID) && (aID))
	{
		try 
		{
			preparedStatement = connection->prepareStatement(
				"UPDATE assignments SET courseId = ? WHERE courseId = ? AND assignmentId = ?");
			preparedStatement->setInt(1, newCID);
			preparedStatement->setInt(2, cID);
			preparedStatement->setInt(3, aID);
			preparedStatement->execute();

			delete preparedStatement;

			cout << assignment << "'s course has been changed to " << newCourse << " successfully." << endl;
			cin;
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
	else
	{
		cout << "Course ID not changed, either course, new course, or assignment doesn't exist." << endl;
		cin;
	}
}

/*****************************************************************************
	Change the type of the assignment.
	@course, the name of the course.
	@assignment, the name of the assignment.
	@material, the new type of assignment.
******************************************************************************/
void AssignmentDBManipulator::updateAssignmentMaterial(string course, 
											string assignment, string material)
{
	int cID = readCourse(course);
	int aID = readAssignment(course, assignment);

	if ((cID) && (aID))
	{
		try 
		{
			preparedStatement = connection->prepareStatement(
				"UPDATE assignments SET assignmentMaterial = ? WHERE courseId = ? AND assignmentId = ?");
			preparedStatement->setString(1, material);
			preparedStatement->setInt(2, cID);
			preparedStatement->setInt(3, aID);
			preparedStatement->execute();

			delete preparedStatement;

			cout << assignment << "'s material has been changed to " << material << " successfully." << endl;
			cin;
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
	else
	{
		cout << "Assignment material hasn't been updated, course or assignment doesn't exist." << endl;
		cin;
	}
}

/*****************************************************************************
	Change the name of the assignment.
	@course, the name of the course.
	@assignment, the name of the assignment.
	@name, the new name of the assignment.
******************************************************************************/
void AssignmentDBManipulator::updateAssignmentName(string course, 
												string assignment, string name)
{
	int cID = readCourse(course);
	int aID = readAssignment(course, assignment);

	if ((cID) && (aID))
	{
		try
		{
			preparedStatement = connection->prepareStatement(
				"UPDATE assignments SET assignmentName = ? WHERE courseId = ? AND assignmentId = ?");
			preparedStatement->setString(1, name);
			preparedStatement->setInt(2, cID);
			preparedStatement->setInt(3, aID);
			preparedStatement->execute();

			delete preparedStatement;

			cout << assignment << "'s name has been changed to " << name << " successfully." << endl;
			cin;
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
	else
	{
		cout << "Assignment name not changed, course or assignment doesn't exist." << endl;
		cin;
	}
}

/*****************************************************************************
	Change the due-date of the assignment.
	@course, the name of the course.
	@assignment, the name of the assignment.
	@duedate, the new assigned date.
******************************************************************************/
void AssignmentDBManipulator::updateAssignmentDueDate(string course, 
											string assignment, string duedate)
{
	int cID = readCourse(course);
	int aID = readAssignment(course, assignment);

	if ((cID) && (aID))
	{
		try
		{
			preparedStatement = connection->prepareStatement(
				"UPDATE assignments SET assignmentDuedate = ? WHERE courseId = ? AND assignmentId = ?");
			preparedStatement->setString(1, duedate);
			preparedStatement->setInt(2, cID);
			preparedStatement->setInt(3, aID);
			preparedStatement->execute();

			delete preparedStatement;

			cout << assignment << "'s duedate has been changed to " << duedate << " successfully." << endl;
			cin;
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
	else
	{
		cout << "Assignment duedate not changed, course or assignment doesn't exist." << endl;
		cin;
	}
}

/******************************************************************************
	Determines the id number of the course.
	@course, the name of the course.
	@return, the id number of the course.
******************************************************************************/
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

/*****************************************************************************
	Determine the id number of the assignment.
	@course, the name of the course of the assignment.
	@assignment, the name of the assignment.
	@return, the id number of the assignment.
******************************************************************************/
int AssignmentDBManipulator::readAssignment(string course, string assignment)
{
	int aID = 0;
	int cID = readCourse(course);

	if (cID)
	{
		try 
		{
			//std::auto_ptr<sql::ResultSet> results(statement->executeQuery(
			//"SELECT assignments.assignmentId, assignments.courseId, assignments.assignmentName FROM assignments"));
			sql::ResultSet *results = statement->executeQuery("SELECT assignments.assignmentId, assignments.courseId, assignments.assignmentName FROM assignments");

			while (results->next())
			{
				if ((cID == results->getInt("courseId")) && (assignment == results->getString("assignmentName")))
				{
					aID = results->getInt("assignmentId");
				}
			}

			delete results;
			return aID;
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
	else
	{
		cout << "Assignment ID couldn't be determined, course doesn't exist." << endl;
		cin;

		return aID;
	}
}

/*****************************************************************************
	Initializes the class fields.
******************************************************************************/
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

/*****************************************************************************
	Tests the connection with the database.
******************************************************************************/
void AssignmentDBManipulator::testConnection()
{
	try
	{
		if (connection->isValid())
		{
			cout << "Connection was successfull!!" << endl;
			cin;
		}
		else
		{
			cout << "Connection was not successfull. :(" << endl << "Reconnecting...";
			cin;

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

