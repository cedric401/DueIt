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
		int year; //2000 <= year <= 2100
		bool isRepeating;
		int daysToRepeat; //0 if task repeats in an interval of months rather than days.
		int monthsToRepeat; //0 if task repeats in an interval of days rather than months.
		int rowID;

	public:
		Task(int start = 0, int d = 1, int m = 1, int y = 1, bool repeating = false, int daysInterval = 0, int monthsInterval = 0);
		Task(int start, int d, int m, int y, bool repeating, int daysInterval, int monthsInterval, int id);
		virtual ~Task();
		virtual std::string toString();
		virtual bool hasPassed(int currentSec, int currentDay, int currentMonth, int currentYear);
		virtual void repeat();
		virtual bool operator==(const Task& rhs);
		void setTime(int newTime);
		int getTime() const;
		void setDay(int newDay);
		int getDay() const;
		void setMonth(int newMonth);
		int getMonth() const;
		void setYear(int newYear);
		int getYear() const;
		void setIsRepeating(bool repeats);
		bool getIsRepeating() const;
		void setDaysToRepeat(int newDayInterval);
		int getDaysToRepeat() const;
		void setMonthsToRepeat(int newMonthInterval);
		int getMonthsToRepeat() const;
		int getRowID() const;
		virtual void createEntry();
		virtual void deleteEntry();
		virtual void updateEntry();
		virtual void readEntry(int row);
	};
};

