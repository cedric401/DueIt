#pragma once
#include <string>
namespace DueItModel
{
	class Task
	{
	protected:
		int startTime; //0 <= startTime <= 86,399 (86,400 seconds in a day)
		int day; //1 <= day <= 31
		int month; //1 <= month <= 12
		int year;

	public:
		Task(int start = 0, int d = 1, int m = 1, int y = 1);
		virtual ~Task();
		virtual std::string toString();
		void setTime(int newTime);
		int getTime() const;
		void setDay(int newDay);
		int getDay() const;
		void setMonth(int newMonth);
		int getMonth() const;
		void setYear(int newYear);
		int getYear() const;

	private:
		virtual void createEntry();
		virtual void deleteEntry();
		virtual void updateEntry();
		virtual void readEntry(int row);
	};
};

