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
