/*********************
 * File         :   DaySlot.h
 *
 * Author       :   John and David
 * SID          :   2813210
 * Created      :   November 17 2013
 *
 * Description  :   This file defines the DaySlot class
 *********************/

#include<string>
#include<vector>
#include "Date.hpp"
#include "Event.h"

using namespace std;

#ifndef C___DaySlot_h
#define C___DaySlot_h

class DaySlot
{
public:

	// ============ CONSTRUCTORS ============ //
    /********************
     * Description  :   Default constructor to make a new DaySlot object.
     *
     * Input        :   None
     *
     * Output       :   New DaySlot object.
     ********************/
    DaySlot();
	/********************
	 * Description  :   Constructor overload to make a new DaySlot objected based on date.
	 *
	 * Input        :   Date* date
	 *
	 * Output       :   New DaySlot object baed on date input.
	 ********************/
    DaySlot(Date* date);

    // ============ ACCESSORS ============ //
	/********************
	 * Description  :   Accessor to get the Date of the DaySlot.
	 *
	 * Input        :   None.
	 *
	 * Output       :   Date as a Date*.
	 ********************/
	Date* getDate() const;
	/********************
	 * Description  :   Accessor to get the a vector of all the Events in the DaySlot.
	 *
	 * Input        :   None.
	 *
	 * Output       :   A Vector of Event* in DaySlot object.
	 ********************/
    vector<Event*> getEvents() const;
	/********************
	 * Description  :   Accessor to get the a vector of all the Events happening during a certain hour in the DaySlot.
	 *
	 * Input        :   The int of the hour.
	 *
	 * Output       :   A Vector of Event* in DaySlot object happening during that hour.
	 ********************/
    vector<Event*> getEventsInHour(int hour) const;

	// ============ MUTATORS ============ //
	/********************
	 * Description  :   Mutator that deletes an Event in DaySlot.
	 *
	 * Input        :   Event* of the event that is to be deleted.
	 *
	 * Output       :   True if event was found deleted, false if event was not found
	 ********************/
    bool deleteEvent(Event* event);
	/********************
	 * Description  :   Mutator that adds an Event to the DaySlot
	 *
	 * Input        :   Event* of the event to be added
	 *
	 * Output       :   True if the event was successfully added, false if the event already exists in the DaySlot
	 ********************/
    bool addEvent(Event* event);

	// ============ QUERIES ============ //
	/********************
	 * Description  :   Queries the DaySlot to determine the most populat Event in DaySlot
	 *
	 * Input        :   None.
	 *
	 * Output       :   Event* of the most popular Event in DaySlot.
	 ********************/
	vector<Event*> getPopularEvent() const;
	/********************
	 * Description  :   Queries the DaySlot to find an Event that is most popular with males.
	 *					It is assumed that the most popular events for males will contain the highest percentage of males.
	 *
	 * Input        :   None.
	 *
	 * Output       :   Event* of the most popular Event for males in DaySlot.
	 ********************/
	vector<Event*> getPopularEventForMales() const;
	/********************
	 * Description  :   Queries the DaySlot to find an Event that is most popular with females.
	 *					It is assumed that the most popular events for females will contain the highest percentage of females.
	 *
	 * Input        :   None.
	 *
	 * Output       :   Event* of the most popular Event for females in DaySlot.
	 ********************/
	vector<Event*> getPopularEventForFemales() const;
	/********************
	 * Description  :   Queries the DaySlot to find an Event that is most popular with females.
	 *					It is assumed that the most popular events for females will contain the highest percentage of females.
	 *
	 * Input        :   Upper age limit (int), lower age limit (int). Age limit is inclusive.
	 *
	 * Output       :   double: percentage of the social network users who fall within the age limits
	 ********************/
	vector<Event*> getPopularEventForAge(int upper_limit, int lower_limit) const;

private:
    vector<Event*> events_;
    Date* date_;
};

#endif
