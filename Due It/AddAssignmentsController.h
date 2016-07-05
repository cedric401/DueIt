#pragma once
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

#include <string>
using std::string;

#include <Time.h>

#include <sstream>
using std::stringstream;

class AddAssignmentsController
{
public:
	AddAssignmentsController( string, int, int, int, int, int );
	~AddAssignmentsController();
	void setMaterial( string );
	string getMaterial();
	void setDueDate( int, int, int, int, int );
	string getDueDate();
private:
	string dateTimeString( string, int, int, int, int, int, int, bool );
	string timeString( int, int);

	string material;
	string dueDate;
};

