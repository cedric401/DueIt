#include <iostream>
using std::cin;
using std::cout;

#include <sstream>
#include <ctime>
#include "Console_Controller.h"
#include "Schedule.h"
#include "AddAssignmentsController.h"
#include "AddCourseController.h"
#include "AssignmentDBManipulator.h"

using namespace DueItModel;

int main()
{
	AssignmentDBManipulator adbm = AssignmentDBManipulator();
	//adbm.deleteAssignment("Functional Programming", "Test 1");
	//adbm.deleteAllAssignment("Functional Programming");
	//adbm.deleteCourse("Functional Programming");

	adbm.terminateConnection();
	return 0;
}
