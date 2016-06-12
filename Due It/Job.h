#pragma once
#include "Task.h"
#include "Company.h"
namespace DueItModel
{
	class Job :
		public Task
	{
	public:
		Job(int dbRowID);
		Job(int startingTime, int endingTime, int workDay, int mnth, int yr, Company jobEmployer, int hrs, float hrlyRate);
		~Job();
		float calcPay();
		std::string toString();
		void setEmployer(Company newEmployer);
		Company getEmployer() const;
		void setEnd(int newEnd);
		int getEnd() const;
		void setHours(int newHours);
		int getHours() const;
		void setRate(float newRate);
		float getRate() const;

	private:
		Company employer;
		int endTime; //0 <= endTime <= 86,399 (86,400 seconds in a day)
		int hours;
		float rate;
		int rowID; //To identify the corresponding location in the database where the Job information is stored
		void createEntry();
		void deleteEntry();
		void updateEntry();
		void readEntry(int row);
	};
};

