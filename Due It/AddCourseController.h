#pragma once

#include <string>
using std::string;

#include <sstream>
using std::stringstream;

class AddCourseController
{
public:
	AddCourseController( string, string, string, string, string, int, int, int, int );
	~AddCourseController();
	void setCourseName( string );
	string getCourseName();
	void setCourseSubject( string );
	string getCourseSubject();
	void setCourseNumber( string );
	string getCourseNumber();
	void setCourseSection( string );
	string getCourseSection();
	void setCourseSchedule( string, int, int, int, int );
	string getCourseSchedule();
private:
	void initialize( string, string, string, string, string, int, int, int, int );
	string timeFormat( int, int );
	string courseName;
	string courseSubject;
	string courseNumber;
	string courseSection;
	string courseSchedule;
};

