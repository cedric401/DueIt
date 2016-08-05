#pragma once
#include "Task.h"
#include "Course.h"
namespace DueItModel
{
	class AssignmentTask :
		public Task
	{
	public:
		AssignmentTask();
		~AssignmentTask();
		std::string toString();
		void setCourse(Course newCourse);
		Course getCourse();
		void setEstimatedTimeToComplete(int newTime);
		int getEstimatedTimeToComplete() const;
		void setDetails(const std::string& newDetails);
		std::string getDetails() const;
		bool operator==(const AssignmentTask& rhs);

	private:
		Course course;
		int estTimeToComplete;
		std::string assignmentDetails;
		int rowID;
	};
};

