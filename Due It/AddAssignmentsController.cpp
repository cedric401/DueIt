#include "AddAssignmentsController.h"


AddAssignmentsController::AddAssignmentsController(string selectedMaterial, int selectedYear, 
									int selectedMonth, int selectedDay, string selectedDueTime)
{
	setMaterial(selectedMaterial);
	setDueDate(selectedYear, selectedMonth, selectedDay);
	setDueTime(selectedDueTime);
}


AddAssignmentsController::~AddAssignmentsController()
{
}

void AddAssignmentsController::setMaterial(string testMaterial)
{
	// Holds the different type of assignments that can be assigned.
	string courseMaterials[] = { "Homework", "Quiz", "Test", "Paper", "Exam" };
	
	// Verifies the parameter is a course material.
	for (int index = 0; index < sizeof(courseMaterials); index++)
	{
		if (testMaterial == courseMaterials[index])
		{
			material = testMaterial;
		}
		else
		{
			if (index == (sizeof(courseMaterials) - 1))
			{
				material = "NO-MATERIAL";
			}
		}
	}// End of for-loop.
}

string AddAssignmentsController::getMaterial()
{
	return material;
}

void AddAssignmentsController::setDueDate(int testYear, int testMonth, int testDay)
{
	enum months {January, February, March, April, May, June, 
		July, August, September, October, November, December};
	time_t theTime = time(NULL);					// Hold Time info.
	struct tm *aTime = localtime(&theTime);			// Stores the current time & date.

	int currentYear = aTime->tm_year + 1900;		// Counts years after 1900.
	int currentMonth = aTime->tm_mon + 1;			// Months range from 0-11.
	int currentDay = aTime->tm_mday;				// Store current date.

	string fail = "NO-DUEDATE";

	// Check the assigned Month and Year is not a previous Month and Year.
	if ((testYear >= currentYear) && (testMonth >= currentMonth))
	{
		// Check the current day is not a previous day.
		// If the assigned day is in the future, store the due date of the assignment.
		switch (testMonth)
		{
		case January:
			if ((testDay <= 31) && (testDay > 0))
			{
				dueDate = ("January " + testDay + ',' + ' ' + testYear);
			}
			else
			{
				dueDate = fail;
			}
			break;

		case February:
			if (((currentYear % 4) == 0))
			{
				if ((testDay <= 29) && (testDay > 0))
				{
					dueDate = ("February " + testDay + ',' + ' ' + testYear);
				}
				else
				{
					dueDate = fail;
				}
			}
			else
			{
				if ((testDay <= 28) && (testDay > 0))
				{
					dueDate = ("February " + testDay + ',' + ' ' + testYear);
				}
				else
				{
					dueDate = fail;
				}
			}
			break;

		case March:
			if ((testDay <= 31) && (testDay > 0))
			{
				dueDate = ("March " + testDay + ',' + ' ' + testYear);
			}
			else
			{
				dueDate = fail;
			}
			break;

		case April:
			if ((testDay <= 30) && (testDay > 0))
			{
				dueDate = ("April " + testDay + ',' + ' ' + testYear);
			}
			else
			{
				dueDate = fail;
			}
			break;

		case May:
			if ((testDay <= 31) && (testDay > 0))
			{
				dueDate = ("May " + testDay + ',' + ' ' + testYear);
			}
			else
			{
				dueDate = fail;
			}
			break;

		case June:
			if ((testDay <= 30) && (testDay > 0))
			{
				dueDate = ("June " + testDay + ',' + ' ' + testYear);
			}
			else
			{
				dueDate = fail;
			}
			break;

		case July:
			if ((testDay <= 31) && (testDay > 0))
			{
				dueDate = ("July " + testDay + ',' + ' ' + testYear);
			}
			else
			{
				dueDate = fail;
			}
			break;

		case August:
			if ((testDay <= 31) && (testDay > 0))
			{
				dueDate = ("August " + testDay + ',' + ' ' + testYear);
			}
			else
			{
				dueDate = fail;
			}
			break;

		case September:
			if ((testDay <= 30) && (testDay > 0))
			{
				dueDate = ("September " + testDay + ',' + ' ' + testYear);
			}
			else
			{
				dueDate = fail;
			}
			break;

		case October:
			if ((testDay <= 31) && (testDay > 0))
			{
				dueDate = ("October " + testDay + ',' + ' ' + testYear);
			}
			else
			{
				dueDate = fail;
			}
			break;

		case November:
			if ((testDay <= 30) && (testDay > 0))
			{
				dueDate = ("November " + testDay + ',' + ' ' + testYear);
			}
			else
			{
				dueDate = fail;
			}
			break;

		case December:
			if ((testDay <= 31) && (testDay > 0))
			{
				dueDate = ("December " + testDay + ',' + ' ' + testYear);
			}
			else
			{
				dueDate = fail;
			}
			break;

		default:
			dueDate = fail;
			break;
		}// end-of switch.
	}
	else
	{
		dueDate = fail;
	}
}

string AddAssignmentsController::getDueDate()
{
	return dueDate;
}

void AddAssignmentsController::setDueTime(string selectedDueTime)
{
}

string AddAssignmentsController::getDueTime()
{
	return dueTime;
}
