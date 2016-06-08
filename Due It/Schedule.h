#pragma once
#include <vector>
#include "Task.h"
namespace DueItModel
{
	class Schedule
	{
	public:
		Schedule();
		~Schedule();

	private:
		std::vector<Task> currentSchedule;
	};
};

