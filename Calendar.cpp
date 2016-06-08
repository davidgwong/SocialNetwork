// File:     Calendar.CPP
//
// Author:   David Wong
// SID:      44627107
// Modified: 2013 November 25
//
// This file implements the Calendar class

#include <iostream>
#include <string>
#include <sstream>
#include "Calendar.h"
#include "DaySlot.h"
#include "Date.hpp"

using namespace std;


// ***** CONSTRUCTORS & DESTRUCTORS ***** //

/********************
 * Description  :   Default constructor to make a new Calendar object.
 *
 * Input        :   None
 *
 * Output       :   New Calendar object
 ********************/
Calendar::Calendar()
{

}

// ***** ACCESSORS ***** //

/********************
 * Description  :   Accessor
 *
 * Input        :   None
 *
 * Output       :   int: the number of events in the calendar
 ********************/
int Calendar::getNumEvents()
{
	int temp = 0;

	for(int i = 0; i < days_.size(); i++)
	{
		temp += days_.at(i)->getEvents().size();
	}
	return temp;
}

/********************
 * Description  :   Accessor
 *
 * Input        :   Date* date: the day for which a dayslot is wanted
 *
 * Output       :   DaySlot* : the dayslot corresponding to the input date
 ********************/
DaySlot* Calendar::getDaySlot(Date* date)
{
	for(int i = 0; i < days_.size(); i++)
	{
		if (days_.at(i)->getDate() == date)
			return days_.at(i);
	}
}

/********************
 * Description  :   Accessor
 *
 * Input        :   Date* date: the day for which a dayslot is wanted
 *
 * Output       :   bool: true if the DaySlot exists
 ********************/
bool Calendar::doesDaySlotExist(Date* date)
{
	for(int i = 0; i < days_.size(); i++)
	{
		if (days_.at(i)->getDate()->getYear() == date->getYear() && 
			days_.at(i)->getDate()->getMonth() == date->getMonth() &&
			days_.at(i)->getDate()->getDay() == date->getDay())
			return true;
	}
	return false;
}

/********************
* Description  :   Accessor that gets an existing date in the calendar
*
* Input        :   Date* that's being looked for in the calendar to get an existing date object
*
* Output       :   Date* of the dayslot date
********************/
Date* Calendar::getDaySlotDate(Date* date)
{
	for(int i = 0; i < days_.size(); i++)
	{
		if (days_.at(i)->getDate()->getYear() == date->getYear() && 
			days_.at(i)->getDate()->getMonth() == date->getMonth() &&
			days_.at(i)->getDate()->getDay() == date->getDay())
			return days_.at(i)->getDate();
	}
	return NULL;
}

// ***** MUTATORS ***** //

/********************
 * Description  :   Mutator
 *
 * Input        :   Date* date: the day for which a dayslot is to be added
 *
 * Output       :   None
 ********************/
void Calendar::addDaySlot(Date* date)
{
	days_.push_back(new DaySlot(date));
}
