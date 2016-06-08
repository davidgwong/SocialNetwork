/*********************
 * File         :   DaySlot.cpp
 *
 * Author       :   John and David
 * SID          :   2813210 and 44627107
 * Created      :   November 19 2013
 *
 * Description  :   This file defines the DaySlot class
 *********************/

#include<string>
#include<vector>
#include "DaySlot.h"
#include "Date.hpp"
#include "Event.h"
#include <algorithm>

using namespace std;

// ============ CONSTRUCTORS ============ //

/********************
 * Description  :   Default constructor to make a new DaySlot object.
 *
 * Input        :   None
 *
 * Output       :   New DaySlot object.
 ********************/

DaySlot::DaySlot()
{

}

/********************
 * Description  :   Constructor overload to make a new DaySlot objected based on date.
 *
 * Input        :   Date* date
 *
 * Output       :   New DaySlot object baed on date input.
 ********************/
DaySlot::DaySlot(Date* date)
{
	date_ = date;
}

// ============ ACCESSORS ============ //

/********************
 * Description  :   Accessor to get the a vector of all the Events in the DaySlot.
 *
 * Input        :   None.
 *
 * Output       :   A Vector of Event* in DaySlot object.
 ********************/
vector<Event*> DaySlot::getEvents() const
{
	return events_;
}

/********************
 * Description  :   Accessor to get the a vector of all the Events happening during a certain hour in the DaySlot.
 *
 * Input        :   The int of the hour.
 *
 * Output       :   A Vector of Event* in DaySlot object happening during that hour.
 ********************/
vector<Event*> DaySlot::getEventsInHour(int hour) const
{
	vector<Event*> temp;

	for(int i = 0; i < events_.size(); i++)
	{
		if(events_.at(i)->getBeginning_Hour() <= hour && events_.at(i)->getEnding_Hour() > hour)
			temp.push_back(events_[i]);
	}

	return temp;
}

/********************
 * Description  :   Accessor to get the Date of the DaySlot.
 *
 * Input        :   None.
 *
 * Output       :   Date as a Date*.
 ********************/
Date* DaySlot::getDate() const
{
	return date_;
}

// ============ MUTATORS ============ //

/********************
 * Description  :   Mutator that deletes an Event in DaySlot.
 *
 * Input        :   Event* of the event that is to be deleted.
 *
 * Output       :   True if event was found deleted, false if event was not found
 ********************/
bool DaySlot::deleteEvent(Event* event)
{
	string new_event_name = event->getName();
	transform(new_event_name.begin(), new_event_name.end(), new_event_name.begin(), ::toupper);

	for(int i = 0; i < events_.size(); i++)
	{
		string event_list_name = events_.at(i)->getName();
		transform(event_list_name.begin(), event_list_name.end(), event_list_name.begin(), ::toupper);

		if(event_list_name == new_event_name)
		{
			events_.erase(events_.begin() + i);
			return true;
		}
	}
	return false;
}

/********************
 * Description  :   Mutator that adds an Event to the DaySlot
 *
 * Input        :   Event* of the event to be added
 *
 * Output       :   True if the event was successfully added, false if the event already exists in the DaySlot
 ********************/
bool DaySlot::addEvent(Event* event)
{
	string new_event_name = event->getName();
	transform(new_event_name.begin(), new_event_name.end(), new_event_name.begin(), ::toupper);
	
	for(int i = 0; i < events_.size(); i++)
	{
		string event_list_name = events_.at(i)->getName();
		transform(event_list_name.begin(), event_list_name.end(), event_list_name.begin(), ::toupper);

		if(event_list_name == new_event_name)
		{
			return false;
		}
	}
	events_.push_back(event);
	return true;
}

// ============ QUERIES ============ //

/********************
 * Description  :   Queries the DaySlot to determine the most populat Event in DaySlot
 *
 * Input        :   None.
 *
 * Output       :   Event* of the most popular Event in DaySlot.
 ********************/
vector<Event*> DaySlot::getPopularEvent() const
{
	int most_users = 0;	// Events can never have less than 0 users
	vector<Event*> most_users_event;

	for(int i = 0; i < events_.size(); i++)
	{
		if(events_.at(i)->getParticipants().size() > most_users)
		{
			most_users = events_.at(i)->getParticipants().size();
			most_users_event.clear();
			most_users_event.push_back(events_.at(i));
		}
		else if(events_.at(i)->getParticipants().size() == most_users)
		{
			most_users_event.push_back(events_.at(i));
		}
	}

	return most_users_event;
}

/********************
 * Description  :   Queries the DaySlot to find an Event that is most popular with males.
 *					It is assumed that the most popular events for males will contain the highest percentage of males.
 *
 * Input        :   None.
 *
 * Output       :   Event* of the most popular Event for males in DaySlot.
 ********************/
vector<Event*> DaySlot::getPopularEventForMales() const
{
	double percentage_most_users = 0;	// Events can never have less than 0 percentage
	vector<Event*> most_event_with_males;

	for(int i = 0; i < events_.size(); i++)
	{
		double num_of_males = 0;
		
		// Loops all the users at the current iteration of event
		for(int j = 0; j < events_.at(i)->getParticipants().size(); j++)
		{
			if(events_.at(i)->getParticipants().at(j)->getGender())
				num_of_males++;
		}

		// Stores the number of males in the current event iteration as a percentage
		double percentage_males_current =  num_of_males/events_.at(i)->getParticipants().size();

		if(percentage_males_current > percentage_most_users)	// Compare current percentage with counter percentage
		{
			percentage_most_users = percentage_males_current;
			most_event_with_males.clear();
			most_event_with_males.push_back(events_.at(i));
		}
		else if(percentage_males_current == percentage_most_users)
		{
			most_event_with_males.push_back(events_.at(i));
		}
	}

	return most_event_with_males;
}

/********************
 * Description  :   Queries the DaySlot to find an Event that is most popular with females.
 *					It is assumed that the most popular events for females will contain the highest percentage of females.
 *
 * Input        :   None.
 *
 * Output       :   Event* of the most popular Event for females in DaySlot.
 ********************/
vector<Event*> DaySlot::getPopularEventForFemales() const
{
	double percentage_most_users = 0;	// Events can never have less than 0 percentage
	vector<Event*> most_event_with_females;

	for(int i = 0; i < events_.size(); i++)
	{
		double num_of_females = 0;
		
		// Loops all the users at the current iteration of event
		for(int j = 0; j < events_.at(i)->getParticipants().size(); j++)
		{
			if(events_.at(i)->getParticipants().at(j)->getGender())
				num_of_females++;
		}

		// Stores the number of males in the current event iteration as a percentage
		double percentage_females_current =  num_of_females/events_.at(i)->getParticipants().size();

		if(percentage_females_current > percentage_most_users)	// Compare current percentage with counter percentage
		{
			percentage_most_users = percentage_females_current;
			most_event_with_females.clear();
			most_event_with_females.push_back(events_.at(i));
		}
		else if(percentage_females_current == percentage_most_users)
		{
			most_event_with_females.push_back(events_.at(i));
		}
	}

	return most_event_with_females;
}

/********************
 * Description  :   Queries the DaySlot to find an Event that is most popular with females.
 *					It is assumed that the most popular events for females will contain the highest percentage of females.
 *
 * Input        :   Upper age limit (int), lower age limit (int). Age limit is inclusive.
 *
 * Output       :   double: percentage of the social network users who fall within the age limits
 ********************/
vector<Event*> DaySlot::getPopularEventForAge(int upper_age, int lower_age) const
{
	double percentage_most_users = 0;	// Events can never have less than 0 percentage
	vector<Event*> most_event_within_age;

	for(int i = 0; i < events_.size(); i++)
	{
		double num_of_users = 0;
		
		// Loops all the users at the current iteration of event
		for(int j = 0; j < events_.at(i)->getParticipants().size(); j++)
		{
			if(events_.at(i)->getParticipants().at(j)->getAge() >= lower_age && events_.at(i)->getParticipants().at(i)->getAge() <= upper_age)
				num_of_users++;
		}

		// Stores the number of males in the current event iteration as a percentage
		double percentage_users_current =  num_of_users/events_.at(i)->getParticipants().size();

		if(percentage_users_current > percentage_most_users)	// Compare current percentage with counter percentage
		{
			percentage_most_users = percentage_users_current;
			most_event_within_age.clear();
			most_event_within_age.push_back(events_.at(i));
		}
		else if(percentage_users_current == percentage_most_users)
		{
			most_event_within_age.push_back(events_.at(i));
		}
	}

	return most_event_within_age;
}