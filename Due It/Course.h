#pragma once
#include <string>
using std::string;
#include <sstream>
using std::stringstream;

namespace DueItModel
{
	class Course
	{
	public:
		Course(string, string, string, string, string);
		~Course();
		void setCourseName(string);
		string getCourseName();
		void setCourseSubject(string);
		string getCourseSubject();
		void setCourseNumber(string);
		string getCourseNumber();
		void setCourseSection(string);
		string getCourseSection();
		void setCourseSchedule(string);
		string getCourseSchedule();
		string toString();
		bool operator==(const Course& rhs);
	private:
		void initialize(string, string, string, string, string);
		string courseName;
		string courseSubject;
		string courseNumber;
		string courseSection;
		string courseSchedule;
	};
};

