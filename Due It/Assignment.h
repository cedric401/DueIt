#pragma once
#include "Task.h"
#include "Course.h"
namespace DueItModel
{
	class Assignment :
		public Task
	{
	public:
		Assignment();
		~Assignment();
		std::string toString();
		void setTime(int newTime);
		void setDay(int newDay);
		void setMonth(int newMonth);
		void setYear(int newYear);
		void setCourse(Course newCourse);
		Course getCourse();
		void setEstimatedTimeToComplete(int newTime);
		int getEstimatedTimeToComplete();
		void setDetails(std::string newDetails);
		std::string getDetails();

	private:
		Course course;
		int estTimeToComplete;
		std::string assignmentDetails;
		int rowID;
		void createEntry();
		void deleteEntry();
		void updateEntry();
		void readEntry(int row);
	};
};

