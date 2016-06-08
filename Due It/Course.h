#pragma once
#include <string>
namespace DueItModel
{
	class Course
	{
	public:
		Course(int courseIDNumber);
		Course(int courseIDNumber = -1, std::string nameOfCourse = "Default Course Name");
		~Course();
		std::string toString();
		void setCourseNumber(int newNumber);
		int getCourseNumber();
		void setCourseName(std::string newName);
		std::string getCourseName();

	private:
		int courseNumber;
		std::string courseName;
		void createEntry();
		void deleteEntry();
		void updateEntry();
		void readEntry(int courseID);
	};
};

