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

	adbm.terminateConnection();
	return 0;
}
