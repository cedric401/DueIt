#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <ctime>
#include "Console_Controller.h"

void printTime()
{
	struct tm *currentTime;
	time_t now;
	time(&now);
	currentTime = localtime(&now);
	std::string weekday;
	switch (currentTime->tm_wday)
	{
	case 0:
		weekday = "Sunday";
		break;
	case 1:
		weekday = "Monday";
		break;
	case 2:
		weekday = "Tuesday";
		break;
	case 3:
		weekday = "Wednesday";
		break;
	case 4:
		weekday = "Thursday";
		break;
	case 5:
		weekday = "Friday";
		break;
	case 6:
		weekday = "Saturday";
		break;
	}
	std::stringstream ss;
	ss << "Current time: " << currentTime->tm_hour << ":" << currentTime->tm_min << ":" << currentTime->tm_sec << " "
		<< weekday << " " << currentTime->tm_mon + 1 << "/" << currentTime->tm_mday << "/" << currentTime->tm_year + 1900 << "\n";
	std::cout << ss.rdbuf();
}

int main()
{
	std::string continueResponse;
	while (continueResponse != "N" && continueResponse != "n")
	{
		printTime();
		std::cout << "Type N to quit: ";
		std::cin >> continueResponse;
	}
	//Console_Controller console =
	return 0;
}
