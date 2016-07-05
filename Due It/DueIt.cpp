#include <iostream>
using std::cin;
using std::cout;

#include <sstream>
#include <ctime>
#include "Console_Controller.h"
#include "Schedule.h"
#include "AddAssignmentsController.h"
using namespace DueItModel;

int main()
{
	//Schedule model = Schedule();
	//Console_Controller controller = Console_Controller(model);
	int test;

	AddAssignmentsController aac("Homework", 2016, 9, 10, 8, 30);
	cout << aac.getDueDate();
	cin >> test;

	return 0;
}
