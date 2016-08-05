#pragma once
#include "Course.h"
#include "AssignmentDBManipulator.h"
#include <string>
using std::string;
#include <sstream>
using std::stringstream;

class AddCourseController
{
public:
	AddCourseController( string, string, string, string, string, int, int, int, int );
	~AddCourseController();
	void setCourseMeet( string, int, int, int, int );
	string getCourseMeet();
private:
	void initialize( string, int, int, int, int );
	string timeFormat( int, int );
	AssignmentDBManipulator adbm = AssignmentDBManipulator();
	string courseMeet;
};

