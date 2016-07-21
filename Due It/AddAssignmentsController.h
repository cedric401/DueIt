#pragma once
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

#include "AssignmentDBManipulator.h"

#include <string>
using std::string;

#include <Time.h>

#include <sstream>
using std::stringstream;

class AddAssignmentsController
{
public:
	AddAssignmentsController( int, string, string, int, int, int, int, int );
	~AddAssignmentsController();
	void setMaterial( string );
	string getMaterial();
	void setName( string );
	string getName();
	void setDueDate( int, int, int, int, int );
	string getDueDate();
private:
	void initialize( string, string, int, int, int, int, int );
	string dateTimeString( string, int, int, int, int, int, int, bool );
	string timeString( int, int );
	string material;
	string name;
	string dueDate;
};

