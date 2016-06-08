// File:     Calendar.h
//
// Author:   David Wong
// SID:      44627107
// Modified: 2013 November 25
//
// This file declares the Calendar class

#ifndef _CALENDAR_HPP
#define _CALENDAR_HPP

#include "Date.hpp"
#include "DaySlot.h"
#include <string>

class Calendar
{

public:
	// ***** CONSTRUCTORS & DESTRUCTORS ***** //

	/********************
 * Description  :   Default constructor to make a new Calendar object.
 *
 * Input        :   None
 *
 * Output       :   New Calendar object
 ********************/
	Calendar();

	~Calendar();

	// ***** ACCESSORS ***** //

	/********************
	 * Description  :   Accessor
	 *
	 * Input        :   None
	 *
	 * Output       :   int: the number of events in the calendar
	 ********************/
	int getNumEvents();

	/********************
	 * Description  :   Accessor
	 *
	 * Input        :   Date* date: the day for which a dayslot is wanted
	 *
	 * Output       :   DaySlot* : the dayslot corresponding to the input date
	 ********************/
	DaySlot* getDaySlot(Date* date);

	/********************
	 * Description  :   Accessor
	 *
	 * Input        :   Date* date: the day for which a dayslot is wanted
	 *
	 * Output       :   bool: true if the DaySlot exists
	 ********************/
	bool doesDaySlotExist(Date* date);

	/********************
	 * Description  :   Accessor that gets an existing date in the calendar
	 *
	 * Input        :   Date* that's being looked for in the calendar to get an existing date object
	 *
	 * Output       :   Date* of the dayslot date
	 ********************/
	Date* getDaySlotDate(Date* date);

	// ***** MUTATORS ***** //

	/********************
	 * Description  :   Mutator
	 *
	 * Input        :   Date* date: the day for which a dayslot is to be added
	 *
	 * Output       :   None
	 ********************/
	void addDaySlot(Date* date);

private:
	// instance variables go here!
	vector<DaySlot*> days_;

};

#endif
