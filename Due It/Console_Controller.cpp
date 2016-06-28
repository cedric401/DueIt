#include "Console_Controller.h"
#include <iostream>
#include <sstream>
#include <ctime>
using namespace std;

Console_Controller::Console_Controller(Schedule model)
{
	tasks = model;
	char continueResponse = '~';
	while (continueResponse != 'q')
	{
		printTime();
		cout << "Enter a command (l for a list of commands): ";
		cin >> continueResponse;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		switch (continueResponse)
		{
		case 'q': //Quit
			break;
		case 'a': //Add a task
			createTask();
			break;
		case 'p': //Print Schedule
			tasks.updateSchedule();
			cout << tasks.toString();
			break;
		case 'l': //List commands
			cout << "'q' - Quit program   'a' - Add task(s) to schedule   'p' - Print schedule\n";
			break;
		}
	}
}

Console_Controller::~Console_Controller()
{
}

void Console_Controller::printTime()
{
	struct tm *currentTime;
	tasks.updateTime();
	currentTime = tasks.getCurrentTime();
	string weekday;
	switch (currentTime->tm_wday)
	{
	case 0:
		weekday = "Sun";
		break;
	case 1:
		weekday = "Mon";
		break;
	case 2:
		weekday = "Tue";
		break;
	case 3:
		weekday = "Wed";
		break;
	case 4:
		weekday = "Thu";
		break;
	case 5:
		weekday = "Fri";
		break;
	case 6:
		weekday = "Sat";
		break;
	}
	stringstream ss;
	ss << "[" << currentTime->tm_hour << ":" << currentTime->tm_min << ":" << currentTime->tm_sec << " "
		<< weekday << " " << currentTime->tm_mon + 1 << "/" << currentTime->tm_mday << "/" << currentTime->tm_year + 1900 << "] ";
	cout << ss.rdbuf();
}

void Console_Controller::createTask()
{
	char response = 'r';
	while (true)
	{
		cout << "Select task type (j=job, p=payment, a=assignment, c=class), r to return: ";
		cin >> response;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		switch (response)
		{
		case 'r':
			return;
		case 'j':
			createJob();
			cout << "Task added. \n";
			break;
		case 'p':
			createPayment();
			cout << "Task added. \n";
			break;
		case 'a':
			createAssignment();
			cout << "Task added. \n";
			break;
		case 'c':
			createCourseMeeting();
			cout << "Task added. \n";
			break;
		default:
			cout << "Invalid input. \n";
			break;
		}
	}
}

void Console_Controller::createJob()
{
	int startSeconds, endSeconds, day, month, year, hours, repeatInDays, repeatInMonths;
	bool repeat;
	float rate;
	cout << "Enter starting time in seconds (0 to 86,399): ";
	cin >> startSeconds;
	cout << "Enter ending time in seconds (0 to 86,399): ";
	cin >> endSeconds;
	cout << "Enter day (1 to 31): ";
	cin >> day;
	cout << "Enter month (1 to 12): ";
	cin >> month;
	cout << "Enter year: ";
	cin >> year;
	cout << "Enter number of paid hours: ";
	cin >> hours;
	cout << "Enter hourly pay rate: ";
	cin >> rate;
	cout << "Does this Job repeat regularly? (y/n): ";
	char repeatResp;
	cin >> repeatResp;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if (repeatResp != 'y')
	{
		repeat = false;
		repeatInDays = 0;
		repeatInMonths = 0;
	}
	else
	{
		repeat = true;
		cout << "Enter number of days until it repeats: ";
		cin >> repeatInDays;
		cout << "Enter number of months until it repeats: ";
		cin >> repeatInMonths;
	}
	
	Job *newJob;
	newJob = new Job(startSeconds, endSeconds, day, month, year, repeat, repeatInDays, repeatInMonths, Company(), hours, rate);
	tasks.addTask(newJob);
}

void Console_Controller::createAssignment()
{
	//TODO
}

void Console_Controller::createCourseMeeting()
{
	//TODO
}

void Console_Controller::createPayment()
{
	int startSeconds, day, month, year, repeatInDays, repeatInMonths;
	bool repeat;
	double amount;
	string accountType;
	cout << "Enter starting time in seconds (0 to 86,399): ";
	cin >> startSeconds;
	cout << "Enter day (1 to 31): ";
	cin >> day;
	cout << "Enter month (1 to 12): ";
	cin >> month;
	cout << "Enter year: ";
	cin >> year;
	cout << "Enter payment amount: ";
	cin >> amount;
	cout << "Enter account type: ";
	cin >> accountType;
	cout << "Does this Payment repeat regularly? (y/n): ";
	char repeatResp;
	cin >> repeatResp;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if (repeatResp != 'y')
	{
		repeat = false;
		repeatInDays = 0;
		repeatInMonths = 0;
	}
	else
	{
		repeat = true;
		cout << "Enter number of days until it repeats: ";
		cin >> repeatInDays;
		cout << "Enter number of months until it repeats: ";
		cin >> repeatInMonths;
	}
	Payment *newPayment;
	newPayment = new Payment(startSeconds, day, month, year, repeat, repeatInDays, repeatInMonths, Company(), amount, false, accountType);
	tasks.addTask(newPayment);
}
