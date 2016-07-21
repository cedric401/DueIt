#include <iostream>
#include <sstream>
#include <ctime>
#include "Console_Controller.h"
#include "Schedule.h"
using namespace DueItModel;

int main()
{
	Schedule* model = new Schedule();
	Console_Controller controller = Console_Controller(model);
	return 0;
}
