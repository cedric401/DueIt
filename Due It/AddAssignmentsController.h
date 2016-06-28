#pragma once
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

#include <string>
using std::string;

#include <Time.h>

class AddAssignmentsController
{
public:
	AddAssignmentsController( string, int, int, int, string );
	~AddAssignmentsController();
	void setMaterial( string );
	string getMaterial();
	void setDueDate( int, int, int );
	string getDueDate();
	void setDueTime( string );
	string getDueTime();
private:
	string material;
	string dueDate;
	string dueTime;
};

