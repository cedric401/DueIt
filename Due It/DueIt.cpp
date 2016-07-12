#include <iostream>
using std::cin;
using std::cout;

#include <sstream>
#include <ctime>
#include "Console_Controller.h"
#include "Schedule.h"
#include "AddAssignmentsController.h"
#include "AddCourseController.h"
using namespace DueItModel;

int main()
{
	string message;

	AddCourseController test1("Calculus I", "Math", "240", "01", "MTWR", 2, 0, 3, 40);
	cout << test1.getCourseSchedule();
	cin >> message;

	return 0;
}
