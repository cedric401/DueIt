#include "AssignmentTask.h"
#include <sstream>

namespace DueItModel
{
	AssignmentTask::AssignmentTask()
	{
	}


	AssignmentTask::~AssignmentTask()
	{
	}

	std::string AssignmentTask::toString()
	{
		return std::string();
	}
	
	void AssignmentTask::setCourse(Course newCourse)
	{
	}
	Course AssignmentTask::getCourse()
	{
		return Course();
	}
	void AssignmentTask::setEstimatedTimeToComplete(int newTime)
	{
	}
	int AssignmentTask::getEstimatedTimeToComplete() const
	{
		return 0;
	}
	void AssignmentTask::setDetails(const std::string& newDetails)
	{
	}
	std::string AssignmentTask::getDetails() const
	{
		return std::string();
	}
	bool AssignmentTask::operator==(const AssignmentTask& rhs)
	{
		return false;
	}
}
