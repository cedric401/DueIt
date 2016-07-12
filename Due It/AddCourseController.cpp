#include "AddCourseController.h"

AddCourseController::AddCourseController(string cName, string cSubject, string cNumber,
				string cSection, string days, int fromHour, int fromMinute, int toHour, int toMinute)
{
	initialize(cName, cSubject, cNumber, cSection, days, fromHour, fromMinute, toHour, toMinute);
}

AddCourseController::~AddCourseController()
{
}

void AddCourseController::setCourseName(string name)
{
	courseName = name;
}

string AddCourseController::getCourseName()
{
	return courseName;
}

void AddCourseController::setCourseSubject(string subject)
{
	courseSubject = subject;
}

string AddCourseController::getCourseSubject()
{
	return courseSubject;
}

void AddCourseController::setCourseNumber(string name)
{
	courseNumber = name;
}

string AddCourseController::getCourseNumber()
{
	return courseNumber;
}

void AddCourseController::setCourseSection(string section)
{
	courseSection = section;
}

string AddCourseController::getCourseSection()
{
	return courseSection;
}

/******************************************************************************
	setCourseSchedule() uses timeFormat() to create a string representation of 
	the time integers.
	@fHR, class meets from hour.
	@fMIN, class meets from minutes.
	@tHR, class meets to hour.
	@tMIN, class meets to minutes.
******************************************************************************/
void AddCourseController::setCourseSchedule(string day, int fHR, int fMIN, int tHR, int tMIN)
{
	stringstream scheduleString;
	int sizeOfDay = day.length();

	for (int index = 0; index < sizeOfDay; index++)
	{
		if ((day.at(index) == 'U') || (day.at(index) == 'M') || 
			(day.at(index) == 'T') || (day.at(index) == 'W') || 
			(day.at(index) == 'R') || (day.at(index) == 'F') || (day.at(index) == 'S') )
		{
			if (index == (sizeOfDay - 1))
			{
				scheduleString << day << ' ' << timeFormat(fHR, fMIN) << " - " << timeFormat(tHR, tMIN);
				courseSchedule = scheduleString.str();
			}
		}
		else
		{
			courseSchedule = "INCORRECT MEET";
			return;
		}
	}
}

string AddCourseController::getCourseSchedule()
{
	return courseSchedule;
}

// Initialize the fields.
void AddCourseController::initialize(string name, string sub, string numb, string sect, 
										string day, int fHR, int fMIN, int tHR, int tMIN)
{
	setCourseName(name);
	setCourseSubject(sub);
	setCourseNumber(numb);
	setCourseSection(sect);
	setCourseSchedule(day, fHR, fMIN, tHR, tMIN);
}

/******************************************************************************
	timeFormat() creates a time string.
	@hours, the hour of the string.
	@minutes, the minutes of the string.
	@return, the time string
******************************************************************************/
string AddCourseController::timeFormat( int hours, int minutes )
{
	stringstream format;
	
	// converts 0 to 12 AM.
	if (hours == 0)
	{
		if (minutes == 0)
		{
			format << "12:" << "00" << " A.M.";
		}
		else
		{
			format << "12:" << minutes << " A.M.";
		}
	}
	// 1-11 AM.
	else if (hours < 12)
	{
		if (minutes == 0)
		{
			format << hours << ':' << "00" << " A.M.";
		}
		else
		{
			format << hours << ':' << minutes << " A.M.";
		}
	}
	// 12 PM.
	else if (hours == 12)
	{
		if (minutes == 0)
		{
			format << hours << ':' << "00" << " P.M.";
		}
		else
		{
			format << hours << ':' << minutes << " P.M.";
		}
	}
	// Converts the time after 12PM.
	else
	{
		hours = hours - 12;

		if (minutes == 0)
		{
			format << hours << ':' << "00" << " P.M.";
		}
		else
		{
			format << hours << ':' << minutes << " P.M.";
		}
	}

	return format.str();
}
