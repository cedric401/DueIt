#include "AddAssignmentsController.h"

AddAssignmentsController::AddAssignmentsController(string selectedMaterial, int selectedYear, 
					int selectedMonth, int selectedDay, int selectedHour, int selectedMinute)
{
	setMaterial(selectedMaterial);
	setDueDate(selectedYear, selectedMonth, selectedDay, selectedHour, selectedMinute);
}


AddAssignmentsController::~AddAssignmentsController()
{
}

/******************************************************************************
	setMaterial() varifies that the assignment is a valid assignment type.
	@testMaterial
******************************************************************************/
void AddAssignmentsController::setMaterial(string testMaterial)
{
	// Holds the different type of assignments that can be assigned.
	string courseMaterials[] = { "Homework", "Quiz", "Test", "Paper", "Exam" };
	
	// Verifies the parameter is a course material.
	for (int index = 0; index < sizeof(courseMaterials); index++)
	{
		if (testMaterial == courseMaterials[index])
		{
			material = testMaterial;
			break;
		}
		else
		{
			if (index == (sizeof(courseMaterials) - 1))
			{
				material = "NO-MATERIAL";
			}
		}
	}// End of for-loop.
}

string AddAssignmentsController::getMaterial()
{
	return material;
}

/******************************************************************************
	setDueDate() verifies that the assignment is due in the future and stores
	the duedate if it is in the future.
	@requestedYear, year of the due-date to be verified.
	@requestedMonth, month of the due-date to be verified.
	@requestedDay, day of the due-date to be verified.
	@requestedHour, hour of the due-date to be verified.
	@requestedMinute, minute of the due-date to be verified.
	@return a string of the due-date.
******************************************************************************/
void AddAssignmentsController::setDueDate(int requestedYear, int requestedMonth, 
						int requestedDay, int requestedHour, int requestedMinute)
{
	enum months {January = 1, February, March, April, May, June, 
		July, August, September, October, November, December};
	time_t theTime = time(NULL);					// Hold Time info.
	struct tm *aTime = localtime(&theTime);			// Stores the current time & date.

	int currentYear = aTime->tm_year + 1900;		// Counts years after 1900.
	int currentMonth = aTime->tm_mon + 1;			// Months range from 0-11.
	int currentDay = aTime->tm_mday;				// Store current date.

	int currentHour = aTime->tm_hour;		
	int currentMinute = aTime->tm_min;
	//int currentSecond = aTime->tm_sec +;

	string fail = "NO-DUEDATE";

	// switch fields, can't be declared in the cases.
	int leapYear = (currentYear % 4);				
	bool today = false;

	/////////////////////////////////////////////////////////////////////////////////////////////////////////
	if ((requestedYear == currentYear) && (requestedMonth == currentMonth))
	{
		switch (requestedMonth)
		{
		case January: ///////////////////////JANUARY//////////////////////////////////
			if (requestedDay <= 31)
			{
				if (requestedDay > currentDay)
				{
					dueDate = dateTimeString("January", requestedDay, requestedYear,
						requestedHour, requestedMinute, currentHour, currentMinute, today);
				}
				else if (requestedDay == currentDay)
				{
					today = true;

					dueDate = dateTimeString("January", requestedDay, requestedYear,
						requestedHour, requestedMinute, currentHour, currentMinute, today);
				}
				else
				{
					dueDate = fail;
				}
			}
			else
			{
				dueDate = fail;
			}
			break;

		case February: ////////////////////////FEBRUARY////////////////////////////////

			if (leapYear == 0)
			{
				if (requestedDay <= 29)
				{
					if (requestedDay > currentDay)
					{
						dueDate = dateTimeString("February", requestedDay, requestedYear,
							requestedHour, requestedMinute, currentHour, currentMinute, today);
					}
					else if (requestedDay == currentDay)
					{
						today = true;

						dueDate = dateTimeString("February", requestedDay, requestedYear,
							requestedHour, requestedMinute, currentHour, currentMinute, today);
					}
					else
					{
						dueDate = fail;
					}
				}// end-of 29 if.
				else
				{
					dueDate = fail;
				}
			}// end-of leapyear if.
			else
			{
				if (requestedDay <= 28)
				{
					if (requestedDay > currentDay)
					{
						dueDate = dateTimeString("February", requestedDay, requestedYear,
							requestedHour, requestedMinute, currentHour, currentMinute, today);
					}
					else if (requestedDay == currentDay)
					{
						today = true;

						dueDate = dateTimeString("February", requestedDay, requestedYear,
							requestedHour, requestedMinute, currentHour, currentMinute, today);
					}
					else
					{
						dueDate = fail;
					}
				}
				else
				{
					dueDate = fail;
				}
			}
			break;

		case March: /////////////////////////////MARCH//////////////////////////////

			if (requestedDay <= 31)
			{
				if (requestedDay > currentDay)
				{
					dueDate = dateTimeString("March", requestedDay, requestedYear,
						requestedHour, requestedMinute, currentHour, currentMinute, today);
				}
				else if (requestedDay == currentDay)
				{
					today = true;

					dueDate = dateTimeString("March", requestedDay, requestedYear,
						requestedHour, requestedMinute, currentHour, currentMinute, today);
				}
				else
				{
					dueDate = fail;
				}
			}
			else
			{
				dueDate = fail;
			}
			break;

		case April: /////////////////////////////APRIL//////////////////////////////
			if (requestedDay <= 30)
			{
				if (requestedDay > currentDay)
				{
					dueDate = dateTimeString("April", requestedDay, requestedYear,
						requestedHour, requestedMinute, currentHour, currentMinute, today);
				}
				else if (requestedDay == currentDay)
				{
					today = true;

					dueDate = dateTimeString("April", requestedDay, requestedYear,
						requestedHour, requestedMinute, currentHour, currentMinute, today);
				}
				else
				{
					dueDate = fail;
				}
			}
			else
			{
				dueDate = fail;
			}
			break;

		case May: ///////////////////////////////MAY//////////////////////////////

			if (requestedDay <= 31)
			{
				if (requestedDay > currentDay)
				{
					dueDate = dateTimeString("May", requestedDay, requestedYear,
						requestedHour, requestedMinute, currentHour, currentMinute, today);
				}
				else if (requestedDay == currentDay)
				{
					today = true;

					dueDate = dateTimeString("May", requestedDay, requestedYear,
						requestedHour, requestedMinute, currentHour, currentMinute, today);
				}
				else
				{
					dueDate = fail;
				}
			}
			else
			{
				dueDate = fail;
			}
			break;

		case June: ///////////////////////////JUNE/////////////////////////////////

			if (requestedDay <= 30)
			{
				if (requestedDay > currentDay)
				{
					dueDate = dateTimeString("June", requestedDay, requestedYear,
						requestedHour, requestedMinute, currentHour, currentMinute, today);
				}
				else if (requestedDay == currentDay)
				{
					today = true;

					dueDate = dateTimeString("June", requestedDay, requestedYear,
						requestedHour, requestedMinute, currentHour, currentMinute, today);
				}
				else
				{
					dueDate = fail;
				}
			}
			else
			{
				dueDate = fail;
			}
			break;

		case July: ////////////////////////////JULY////////////////////////////////

			if (requestedDay <= 31)
			{
				if (requestedDay > currentDay)
				{
					dueDate = dateTimeString("July", requestedDay, requestedYear,
						requestedHour, requestedMinute, currentHour, currentMinute, today);
				}
				else if (requestedDay == currentDay)
				{
					today = true;

					dueDate = dateTimeString("July", requestedDay, requestedYear,
						requestedHour, requestedMinute, currentHour, currentMinute, today);
				}
				else
				{
					dueDate = fail;
				}
			}
			else
			{
				dueDate = fail;
			}
			break;

		case August: //////////////////////////AUGUST////////////////////////////////

			if (requestedDay <= 31)
			{
				if (requestedDay > currentDay)
				{
					dueDate = dateTimeString("August", requestedDay, requestedYear,
						requestedHour, requestedMinute, currentHour, currentMinute, today);
				}
				else if (requestedDay == currentDay)
				{
					today = true;

					dueDate = dateTimeString("August", requestedDay, requestedYear,
						requestedHour, requestedMinute, currentHour, currentMinute, today);
				}
				else
				{
					dueDate = fail;
				}
			}
			else
			{
				dueDate = fail;
			}
			break;

		case September: //////////////////////////SEPTEMBER/////////////////////////////

			if (requestedDay <= 30)
			{
				if (requestedDay > currentDay)
				{
					dueDate = dateTimeString("September", requestedDay, requestedYear,
						requestedHour, requestedMinute, currentHour, currentMinute, today);
				}
				else if (requestedDay == currentDay)
				{
					today = true;

					dueDate = dateTimeString("September", requestedDay, requestedYear,
						requestedHour, requestedMinute, currentHour, currentMinute, today);
				}
				else
				{
					dueDate = fail;
				}
			}
			else
			{
				dueDate = fail;
			}
			break;

		case October: ///////////////////////////OCTOBER//////////////////////////////

			if (requestedDay <= 31)
			{
				if (requestedDay > currentDay)
				{
					dueDate = dateTimeString("October", requestedDay, requestedYear,
						requestedHour, requestedMinute, currentHour, currentMinute, today);
				}
				else if (requestedDay == currentDay)
				{
					today = true;

					dueDate = dateTimeString("October", requestedDay, requestedYear,
						requestedHour, requestedMinute, currentHour, currentMinute, today);
				}
				else
				{
					dueDate = fail;
				}
			}
			else
			{
				dueDate = fail;
			}
			break;

		case November: /////////////////////////NOVEMBER///////////////////////////////

			if (requestedDay <= 30)
			{
				if (requestedDay > currentDay)
				{
					dueDate = dateTimeString("November", requestedDay, requestedYear,
						requestedHour, requestedMinute, currentHour, currentMinute, today);
				}
				else if (requestedDay == currentDay)
				{
					today = true;

					dueDate = dateTimeString("November", requestedDay, requestedYear,
						requestedHour, requestedMinute, currentHour, currentMinute, today);
				}
				else
				{
					dueDate = fail;
				}
			}
			else
			{
				dueDate = fail;
			}
			break;

		case December: ///////////////////////////DECEMBER/////////////////////////////

			if (requestedDay <= 31)
			{
				if (requestedDay > currentDay)
				{
					dueDate = dateTimeString("December", requestedDay, requestedYear,
						requestedHour, requestedMinute, currentHour, currentMinute, today);
				}
				else if (requestedDay == currentDay)
				{
					today = true;

					dueDate = dateTimeString("December", requestedDay, requestedYear,
						requestedHour, requestedMinute, currentHour, currentMinute, today);
				}
				else
				{
					dueDate = fail;
				}
			}
			else
			{
				dueDate = fail;
			}
			break;

		default:
			dueDate = fail;
			break;
		}// end-of switch.
	}// end-of if ((requestedYear == currentYear) && (requestedMonth == currentMonth))
	else if (((requestedYear == currentYear) && (requestedMonth > currentMonth)) || (requestedYear > currentYear))
	{
		switch (requestedMonth)
		{
		case January: ///////////////////////JANUARY//////////////////////////////////
			if ((requestedDay <= 31) && (requestedDay >= 1))
			{
					dueDate = dateTimeString("January", requestedDay, requestedYear,
						requestedHour, requestedMinute, currentHour, currentMinute, today);
			}
			else
			{
				dueDate = fail;
			}
			break;

		case February: ////////////////////////FEBRUARY////////////////////////////////

			if (leapYear == 0)
			{
				if ((requestedDay <= 29) && (requestedDay >= 1))
				{
						dueDate = dateTimeString("February", requestedDay, requestedYear,
							requestedHour, requestedMinute, currentHour, currentMinute, today);
				}// end-of 29 if.
				else
				{
					dueDate = fail;
				}
			}// end-of leapyear if.
			else
			{
				if ((requestedDay <= 28) && (requestedDay >= 1))
				{
						dueDate = dateTimeString("February", requestedDay, requestedYear,
							requestedHour, requestedMinute, currentHour, currentMinute, today);
				}
				else
				{
					dueDate = fail;
				}
			}
			break;

		case March: /////////////////////////////MARCH//////////////////////////////

			if ((requestedDay <= 31) && (requestedDay >= 1))
			{
					dueDate = dateTimeString("March", requestedDay, requestedYear,
						requestedHour, requestedMinute, currentHour, currentMinute, today);
			}
			else
			{
				dueDate = fail;
			}
			break;

		case April: /////////////////////////////APRIL//////////////////////////////
			if ((requestedDay <= 30) && (requestedDay >= 1))
			{
					dueDate = dateTimeString("April", requestedDay, requestedYear,
						requestedHour, requestedMinute, currentHour, currentMinute, today);
			}
			else
			{
				dueDate = fail;
			}
			break;

		case May: ///////////////////////////////MAY//////////////////////////////

			if ((requestedDay <= 31) && (requestedDay >= 1))
			{
					dueDate = dateTimeString("May", requestedDay, requestedYear,
						requestedHour, requestedMinute, currentHour, currentMinute, today);
			}
			else
			{
				dueDate = fail;
			}
			break;

		case June: ///////////////////////////JUNE/////////////////////////////////

			if ((requestedDay <= 30) && (requestedDay >= 1))
			{
					dueDate = dateTimeString("June", requestedDay, requestedYear,
						requestedHour, requestedMinute, currentHour, currentMinute, today);
			}
			else
			{
				dueDate = fail;
			}
			break;

		case July: ////////////////////////////JULY////////////////////////////////

			if ((requestedDay <= 31) && (requestedDay >= 1))
			{
					dueDate = dateTimeString("July", requestedDay, requestedYear,
						requestedHour, requestedMinute, currentHour, currentMinute, today);
			}
			else
			{
				dueDate = fail;
			}
			break;

		case August: //////////////////////////AUGUST////////////////////////////////

			if ((requestedDay <= 31) && (requestedDay >= 1))
			{
					dueDate = dateTimeString("August", requestedDay, requestedYear,
						requestedHour, requestedMinute, currentHour, currentMinute, today);
			}
			else
			{
				dueDate = fail;
			}
			break;

		case September: //////////////////////////SEPTEMBER/////////////////////////////

			if ((requestedDay <= 30) && (requestedDay >= 1))
			{
					dueDate = dateTimeString("September", requestedDay, requestedYear,
						requestedHour, requestedMinute, currentHour, currentMinute, today);
			}
			else
			{
				dueDate = fail;
			}
			break;

		case October: ///////////////////////////OCTOBER//////////////////////////////

			if ((requestedDay <= 31) && (requestedDay >= 1))
			{
					dueDate = dateTimeString("October", requestedDay, requestedYear,
						requestedHour, requestedMinute, currentHour, currentMinute, today);
			}
			else
			{
				dueDate = fail;
			}
			break;

		case November: /////////////////////////NOVEMBER///////////////////////////////

			if ((requestedDay <= 30) && (requestedDay >= 1))
			{
					dueDate = dateTimeString("November", requestedDay, requestedYear,
						requestedHour, requestedMinute, currentHour, currentMinute, today);
			}
			else
			{
				dueDate = fail;
			}
			break;

		case December: ///////////////////////////DECEMBER/////////////////////////////

			if ((requestedDay <= 31) && (requestedDay >= 1))
			{
					dueDate = dateTimeString("December", requestedDay, requestedYear,
						requestedHour, requestedMinute, currentHour, currentMinute, today);
			}
			else
			{
				dueDate = fail;
			}
			break;

		default:
			dueDate = fail;
			break;
		}// end-of switch.
	}// end-of if (((requestedYear == currentYear) && (requestedMonth > currentMonth)) || (requestedYear > currentYear))
	else
	{
		dueDate = fail;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////



	// Check that the assigned Month and Year is not a previous Month and Year.
	if ((requestedYear >= currentYear) && (requestedMonth >= currentMonth))
	{
			// Check that the current day is not a previous day.
			// When the assigned day is in the future, store the due date of the assignment.
			switch (requestedMonth)
			{
			case January: ///////////////////////JANUARY//////////////////////////////////
				if (requestedDay <= 31)
				{
					if (requestedDay > currentDay)
					{
						dueDate = dateTimeString("January", requestedDay, requestedYear,
							requestedHour, requestedMinute, currentHour, currentMinute, today);
					}
					else if (requestedDay == currentDay)
					{
						today = true;

						dueDate = dateTimeString("January", requestedDay, requestedYear,
							requestedHour, requestedMinute, currentHour, currentMinute, today);
					}
					else
					{
						dueDate = fail;
					}
				}
				else
				{
					dueDate = fail;
				}
				break;

			case February: ////////////////////////FEBRUARY////////////////////////////////

				if (leapYear == 0)
				{
					if (requestedDay <= 29)
					{
						if (requestedDay > currentDay)
						{
							dueDate = dateTimeString("February", requestedDay, requestedYear,
								requestedHour, requestedMinute, currentHour, currentMinute, today);
						}
						else if (requestedDay == currentDay)
						{
							today = true;

							dueDate = dateTimeString("February", requestedDay, requestedYear,
								requestedHour, requestedMinute, currentHour, currentMinute, today);
						}
						else
						{
							dueDate = fail;
						}
					}// end-of 29 if.
					else
					{
						dueDate = fail;
					}
				}// end-of leapyear if.
				else
				{
					if (requestedDay <= 28)
					{
						if (requestedDay > currentDay)
						{
							dueDate = dateTimeString("February", requestedDay, requestedYear,
								requestedHour, requestedMinute, currentHour, currentMinute, today);
						}
						else if (requestedDay == currentDay)
						{
							today = true;

							dueDate = dateTimeString("February", requestedDay, requestedYear,
								requestedHour, requestedMinute, currentHour, currentMinute, today);
						}
						else
						{
							dueDate = fail;
						}
					}
					else
					{
						dueDate = fail;
					}
				}
				break;

			case March: /////////////////////////////MARCH//////////////////////////////

				if (requestedDay <= 31)
				{
					if (requestedDay > currentDay)
					{
						dueDate = dateTimeString("March", requestedDay, requestedYear,
							requestedHour, requestedMinute, currentHour, currentMinute, today);
					}
					else if (requestedDay == currentDay)
					{
						today = true;

						dueDate = dateTimeString("March", requestedDay, requestedYear,
							requestedHour, requestedMinute, currentHour, currentMinute, today);
					}
					else
					{
						dueDate = fail;
					}
				}
				else
				{
					dueDate = fail;
				}
				break;

			case April: /////////////////////////////APRIL//////////////////////////////
				if (requestedDay <= 30)
				{
					if (requestedDay > currentDay)
					{
						dueDate = dateTimeString("April", requestedDay, requestedYear,
							requestedHour, requestedMinute, currentHour, currentMinute, today);
					}
					else if (requestedDay == currentDay)
					{
						today = true;

						dueDate = dateTimeString("April", requestedDay, requestedYear,
							requestedHour, requestedMinute, currentHour, currentMinute, today);
					}
					else
					{
						dueDate = fail;
					}
				}
				else
				{
					dueDate = fail;
				}
				break;

			case May: ///////////////////////////////MAY//////////////////////////////

				if (requestedDay <= 31)
				{
					if (requestedDay > currentDay)
					{
						dueDate = dateTimeString("May", requestedDay, requestedYear,
							requestedHour, requestedMinute, currentHour, currentMinute, today);
					}
					else if (requestedDay == currentDay)
					{
						today = true;

						dueDate = dateTimeString("May", requestedDay, requestedYear,
							requestedHour, requestedMinute, currentHour, currentMinute, today);
					}
					else
					{
						dueDate = fail;
					}
				}
				else
				{
					dueDate = fail;
				}
				break;

			case June: ///////////////////////////JUNE/////////////////////////////////

				if (requestedDay <= 30)
				{
					if (requestedDay > currentDay)
					{
						dueDate = dateTimeString("June", requestedDay, requestedYear,
							requestedHour, requestedMinute, currentHour, currentMinute, today);
					}
					else if (requestedDay == currentDay)
					{
						today = true;

						dueDate = dateTimeString("June", requestedDay, requestedYear,
							requestedHour, requestedMinute, currentHour, currentMinute, today);
					}
					else
					{
						dueDate = fail;
					}
				}
				else
				{
					dueDate = fail;
				}
				break;

			case July: ////////////////////////////JULY////////////////////////////////

				if (requestedDay <= 31)
				{
					if (requestedDay > currentDay)
					{
						dueDate = dateTimeString("July", requestedDay, requestedYear,
							requestedHour, requestedMinute, currentHour, currentMinute, today);
					}
					else if (requestedDay == currentDay)
					{
						today = true;

						dueDate = dateTimeString("July", requestedDay, requestedYear,
							requestedHour, requestedMinute, currentHour, currentMinute, today);
					}
					else
					{
						dueDate = fail;
					}
				}
				else
				{
					dueDate = fail;
				}
				break;

			case August: //////////////////////////AUGUST////////////////////////////////

				if (requestedDay <= 31)
				{
					if (requestedDay > currentDay)
					{
						dueDate = dateTimeString("August", requestedDay, requestedYear,
							requestedHour, requestedMinute, currentHour, currentMinute, today);
					}
					else if (requestedDay == currentDay)
					{
						today = true;

						dueDate = dateTimeString("August", requestedDay, requestedYear,
							requestedHour, requestedMinute, currentHour, currentMinute, today);
					}
					else
					{
						dueDate = fail;
					}
				}
				else
				{
					dueDate = fail;
				}
				break;

			case September: //////////////////////////SEPTEMBER/////////////////////////////

				if (requestedDay <= 30)
				{
					if (requestedDay > currentDay)
					{
						dueDate = dateTimeString("September", requestedDay, requestedYear,
							requestedHour, requestedMinute, currentHour, currentMinute, today);
					}
					else if (requestedDay == currentDay)
					{
						today = true;

						dueDate = dateTimeString("September", requestedDay, requestedYear,
							requestedHour, requestedMinute, currentHour, currentMinute, today);
					}
					else
					{
						dueDate = fail;
					}
				}
				else
				{
					dueDate = fail;
				}
				break;

			case October: ///////////////////////////OCTOBER//////////////////////////////

				if (requestedDay <= 31)
				{
					if (requestedDay > currentDay)
					{
						dueDate = dateTimeString("October", requestedDay, requestedYear,
							requestedHour, requestedMinute, currentHour, currentMinute, today);
					}
					else if (requestedDay == currentDay)
					{
						today = true;

						dueDate = dateTimeString("October", requestedDay, requestedYear,
							requestedHour, requestedMinute, currentHour, currentMinute, today);
					}
					else
					{
						dueDate = fail;
					}
				}
				else
				{
					dueDate = fail;
				}
				break;

			case November: /////////////////////////NOVEMBER///////////////////////////////

				if (requestedDay <= 30)
				{
					if (requestedDay > currentDay)
					{
						dueDate = dateTimeString("November", requestedDay, requestedYear,
							requestedHour, requestedMinute, currentHour, currentMinute, today);
					}
					else if (requestedDay == currentDay)
					{
						today = true;

						dueDate = dateTimeString("November", requestedDay, requestedYear,
							requestedHour, requestedMinute, currentHour, currentMinute, today);
					}
					else
					{
						dueDate = fail;
					}
				}
				else
				{
					dueDate = fail;
				}
				break;

			case December: ///////////////////////////DECEMBER/////////////////////////////

				if (requestedDay <= 31)
				{
					if (requestedDay > currentDay)
					{
						dueDate = dateTimeString("December", requestedDay, requestedYear,
							requestedHour, requestedMinute, currentHour, currentMinute, today);
					}
					else if (requestedDay == currentDay)
					{
						today = true;

						dueDate = dateTimeString("December", requestedDay, requestedYear,
							requestedHour, requestedMinute, currentHour, currentMinute, today);
					}
					else
					{
						dueDate = fail;
					}
				}
				else
				{
					dueDate = fail;
				}
				break;

			default:
				dueDate = fail;
				break;
			}// end-of switch.
	}
	else
	{
		dueDate = fail;
	}
}

string AddAssignmentsController::getDueDate()
{
	return dueDate;
}

/******************************************************************************
	dateTimeString() is a helper function for setDueDate() 
	that creates a string representation of the due date.
	The time requested is verified first.
	@month, month of the due-date.
	@day, day of the due-date.
	@year, year of the due-date.
	@rHour, hour requested for the time of due-date.
	@rMinute, minute requested for the time of due-date.
	@cHour, current hour of the day.
	@cMinute, current minute of the day.
	@today, true when due-date is the current date.
	@return the date and time as a string.
******************************************************************************/
string AddAssignmentsController::dateTimeString(string month, int day, int year, int rHour,
								int rMinute, int cHour, int cMinute, bool today)
{
	string dateFail = "NO Date Time String";	// Failed date and time string.
	stringstream dateString;					// Holds the string representing the due date.

	// Time will be compared only if the due date is made for today.
	if ( today )
	{
		// When the hour is later in the day, the minutes do not need to be compared.
		if ((rHour > cHour) && (rHour < 24))
		{
			dateString << (month + ' ') << day << ", " << (year + ' ') <<
				timeString(rHour, rMinute);
		}
		// When the hour is equal to the current hour, the minutes will need to be in the future.
		else if (rHour == cHour)
		{
			if ((rMinute > cMinute) && (rMinute < 60))
			{
				dateString << (month + ' ') << day << ", " << (year + ' ') <<
					timeString(rHour, rMinute);
			}
			else
			{
				dateString << dateFail;
			}
		}// end-of if(tHour == cHour)
		else
		{
			dateString << dateFail;
		}
	}// end-of if (today)
	else
	{
		dateString << (month + ' ') << day << ", " << (year + ' ') <<
			timeString(rHour, rMinute);
	}

	return dateString.str();
}

/******************************************************************************
	timeString() is a helper function for dateTimeString()
	that creates a string representation of the time the assignment is due. 
	The string converts the 24-hr time into 12-hr time.
	@hours, hours of the duedate.
	@minutes, minutes of the duedate.
	@return the time string.
******************************************************************************/
string AddAssignmentsController::timeString(int hours, int minutes)
{
	stringstream timeStamp;	// Holds the time string to be used in the date string.

	if (hours == 0)
	{
		timeStamp << "12:" << minutes << " A.M.";
	}
	else if (hours < 12)
	{
		timeStamp << hours << ':' << minutes << " A.M.";
	}
	else if (hours == 12)
	{
		timeStamp << hours << ':' << minutes << " P.M.";
	}
	else
	{
		hours = hours - 12;

		timeStamp << hours << ':' << minutes << " P.M.";
	}

	return timeStamp.str();
}