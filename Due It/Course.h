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
		int getCourseNumber() const;
		void setCourseName(const std::string& newName);
		std::string getCourseName() const;
		bool operator==(const Course& rhs);
		void createEntry();
		void deleteEntry();
		void updateEntry();
		void readEntry(int courseID);

	private:
		int courseNumber;
		std::string courseName;
	};
};

