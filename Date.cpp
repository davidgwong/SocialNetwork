// File:     Date.cpp
//
// Author:   John Henderson
// SID:      28132108
// UserID:   j1s7
// Lab:      L1A
// Modified: 2013 October 29
//
// This file defines the Date class for the Date class

#include "Date.hpp"
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

int const numMonths = 12;
string const monthsNames[numMonths] = {"January","February","March","April","May","June","July","August","September","October","November","December"}; //This array stores all of the names of the months

// ***** CONSTRUCTORS & DESTRUCTORS ***** //

/********************
 * Description  :   Default constructor to make a new Date object.
 *
 * Input        :   None
 *
 * Output       :   New Date object
 ********************/
Date::Date( void )
// POST: A Date with year (int), month (int/string) and
//       day (int) is created
{
	this->year_ = 0;
	this->month_ = 1;
	this->day_ = 1; 
}

/********************
* Description  :   Parametrized constructor to make a new Date object.
*
* Input        :   int year. int month, int day
*
* Output       :   New Date object
********************/
Date::Date( int year, int month, int day)
// POST: A Date with year (int), month (int/string) and
//       day (int) is created based on input parameters (month is int)
{
	CheckforNeg(year, month, day);
	CheckforRealDate(year, month, day);
	this->year_ = year;
	this->month_ = month;
	this->day_ = day;
}

/********************
* Description  :   Parametrized constructor to make a new Date object. Takes month as input string
*
* Input        :   int year, string month, int day
*
* Output       :   New Date object
********************/
Date::Date( int year, string month, int day)
// POST: A Date with year (int), month (int/string) and
//       day (int) is created based on input parameters (month is string)
{
	CheckforNeg(year, monthStr2Num(month), day);
	CheckforRealDate(year, monthStr2Num(month), day);
	this->year_ = year;
	this->month_ = monthStr2Num(month);
	this->day_ = day;
}

// ***** ACCESSORS ***** //

/********************
	 * Description  :	Accessor
	 *
	 * Input        :	None
	 *
	 * Output       :   int: month of date
	 ********************/
int Date::getMonth()
// Accessor: Allows access to the month variable of a Date object
// POST: Returns the month
{
  return this->month_;
}

/********************
	 * Description  :	Accessor
	 *
	 * Input        :	None
	 *
	 * Output       :   int: day of date
	 ********************/
int Date::getDay()
// Accessor: Allows access to the day variable of a Date object
// POST: Returns the day
{
  return this->day_;
}

/********************
	 * Description  :	Accessor
	 *
	 * Input        :	None
	 *
	 * Output       :   int: year of date
	 ********************/
int Date::getYear()
// Accessor: Allows access to the year variable of a Date object
// POST: Returns the year
{
  return this->year_;
}

/********************
	 * Description  :	Accessor
	 *
	 * Input        :	None
	 *
	 * Output       :   string: the date in a human readable format
	 ********************/
string Date::toString()
{
	return to_string(day_) + "/" + to_string(month_) + "/" + to_string(year_);
}

// ***** MUTATORS ***** //

/********************
	 * Description  :	Mutator
	 *
	 * Input        :   int month
	 *
	 * Output       :   None
	 ********************/
void Date::setMonth(int month)
// Mutator: Allows the month variable of a Date object to be set
// POST: The month is set to the input value
{
  this->month_ = month;
  // **TODO** Right now this will let anything be a month!
}

/********************
	 * Description  :	Mutator
	 *
	 * Input        :   int day
	 *
	 * Output       :   None
	 ********************/
void Date::setDay(int day)
// Mutator: Allows the day variable of a Date object to be set
// POST: The day is set to the input value
{
	
	this->day_ = day;
  // **TODO** Right now this will let anything be a day!
}

/********************
* Description  :	Mutator
*
* Input        :   int year
*
* Output       :   None
********************/
void Date::setYear(int year)
// Mutator: Allows the year variable of a Date object to be set
// POST: The year is set to the input value
{
  this->year_ = year;
  // **TODO** Right now this will let anything be a day!
}

/********************
* Description  :	Mutator
*
* Input        :   int year, int month, int day
*
* Output       :   bool: true if setDate is successful
********************/
bool Date::setDate( int year, int month, int day)
// Mutator: Allows the year, month and day variables of a Date object to be set
// POST: Updates the year, month and day with the input values (month is an int)
{
	CheckforNeg(year, month, day);
	if(CheckforRealDate(year, month, day))
	{
	this->year_ = year;
	this->month_ = month;
	this->day_ = day;
	return true;
	}
	return false;
}

/********************
* Description  :	Mutator
*
* Input        :   int year, string month, int day
*
* Output       :   bool: true if setDate is successful
********************/
bool Date::setDate( int year, string month, int day)
// Mutator: Allows the year, month and day variables of a Date object to be set
// POST: Updates the year, month and day with the input values (month is a string)
{
	if(CheckforNeg(year, monthStr2Num(month), day) && CheckforRealDate(year, monthStr2Num(month), day))
	{
	this->year_ = year;
	this->month_ = monthStr2Num(month);
	this->day_ = day;
	return true;
	}
	return false;
}

// ***** HELPER METHODS ***** //

int Date::monthStr2Num( string month )
// Converts from string notation and integer notation for month
// POST: The function returns the integer month equivalent, returns -1 not sucessful
{
	int n=0;
	while(n<numMonths)
	{
		if(month ==monthsNames[n])
			return n+1;
		else
			n++;
	}
	return -1;
}

string Date::intToString ( int i )
// Converts integer to string
// POST: i is returned as string
{
	stringstream ss;
	ss << i;
	return ss.str();
}

bool Date::CheckforNeg(int year, int month, int day)
// Checks to see if any values are negative
// POST: prints related error message
{
	if(year<0 || month<=0 || day<=0)
	{
		cerr<<"Negative Input Error: one of the inputs in the date below is negative or zero"<<endl;
		return false;
	}
	return true;
}

bool Date::CheckforRealDate(int year, int month, int day)
// Checks to see if the date is real. i.e. that the date actually exists on a calendar
// POST: prints related error message
{
	// Check to use if the month is real (i.e. no more than 12)
	if(month>12)
	{
		cerr<<"Real Date Error: This month entered is greater than 12"<<endl;
		return false;
	}
	//Check if the day fits within the number of days in the month
	if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		if(day>31)
		{
			cerr<<"Real Date Error: This month in the date below only has 31 days, please enter a day within 1-31"<<endl;
			return false;
		}
	else if(month == 4 || month == 6 || month == 9 || month == 11)
		if(day>30)
		{
			cerr<<"Real Date Error: This month in the date below has 30 days, please enter a day within 1-30"<<endl;
			return false;
		}
	//Check to see if the year is valid
	else if(CheckforLeapYear(year)==true)
	{
		cout<<"Real Date Error: This year in the date below is a leap year so February has 29 days, please enter a within 1-29"<<endl;
		return false;
	}
	else
	{
		cout<<"Real Date Error: This year is not leap year so February has 28 days, please enter a within 1-28"<<endl;
		return false;
	}
	return true;
}

bool Date::CheckforLeapYear(int year)
// Checks to see if the year is a leap year
// POSTS: returns true if it is a leap year
{
	if(year%4 == 0 && year%100 != 0)
		return true;
	else if(year%400 == 0)
		return true;
	else
		return false;
}