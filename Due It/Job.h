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
		Job(int startingTime, int endingTime, int workDay, int mnth, int yr, bool repeating, int daysInterval, int monthsInterval, Company jobEmployer, int hrs, float hrlyRate);
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
		bool operator==(const Job& rhs);
		void createEntry();
		void deleteEntry();
		void updateEntry();
		void readEntry(int row);

	private:
		Company employer;
		int endTime; //0 <= endTime <= 86,399 (86,400 seconds in a day)
		int hours; //0 <= hours
		float rate; //0 <= rate
		int rowID; //To identify the corresponding location in the database where the Job information is stored
	};
};

