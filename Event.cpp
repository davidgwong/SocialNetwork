/*********************
 * File         :   Event.cpp
 *
 * Author       :   John and David
 * SID          :   28132108
 * Created      :   November 17 2013
 *
 * Description  :   This file defines the Event class
 *********************/

#include<string>
#include<vector>
#include "Date.hpp"
#include "Event.h"
#include "User.h"

using namespace std;

// Array of strings that corresponds to the event's category
string Event::categories_list_[] = {"Sports","Music","Festival","School","Business","Party","Holiday"};

// ***** CONSTRUCTORS & DESTRUCTORS ***** //
/********************
 * Description  :   Default constructor to make a new Event object.
 *
 * Input        :   None
 *
 * Output       :   New Event object.
 ********************/
Event::Event()
{}

/********************
 * Description  :   Constructor to make a new Event object.
 *
 * Input        :   Event date, beginning hour, ending hour, name of event, event description, event creator, event category
 *
 * Output       :   New Event object.
 ********************/
Event::Event(Date* event_date, int beginning_hour, int ending_hour, string name, string description, User* event_creator, int category)
{
    date_ = event_date;
    beginning_hour_ = beginning_hour;
    ending_hour_ = ending_hour;
    name_ = name;
    description_ = description;
    participants_.push_back(event_creator);
    category_ = category;
}

/********************
 * Description  :   Default destructor
 *
 * Input        :   None
 *
 * Output       :   Deletes event
 ********************/
Event::~Event()
{

}

// ***** ACCESSORS ***** //
/********************
 * Description  :   Accessor to get the name of the event
 *
 * Input        :   None
 *
 * Output       :   Event's name as a string
 ********************/
string Event::getName()
{
    return name_;
}

/********************
 * Description  :   Accessor to get the description of the event
 *
 * Input        :   None
 *
 * Output       :   Event's description as a string
 ********************/
string Event::getDescription()
{
    return description_;
}

/********************
 * Description  :   Accessor to get the category of the event
 *
 * Input        :   None
 *
 * Output       :   Event's category as a string
 ********************/
string Event::getCategory()
{
  return categories_list_[category_];
}

/********************
 * Description  :   Accessor to get the date of the event
 *
 * Input        :   None
 *
 * Output       :   Event's date as a string
 ********************/
string Event::getDateString()
{
    return date_->toString();
}

/********************
 * Description  :   Accessor to get the date of the event
 *
 * Input        :   None
 *
 * Output       :   Event's date as a Date
 ********************/
Date* Event::getDate()
{
    return date_;
}

/********************
 * Description  :   Accessor to get the participants of the event
 *
 * Input        :   None
 *
 * Output       :   Participants as a vector of User pointers
 ********************/
vector<User*> Event::getParticipants()
{
    return participants_;
}

/********************
 * Description  :   Accessor to get the beginning hour of the event
 *
 * Input        :   None
 *
 * Output       :   Event's beginning hour as an int
 ********************/
int Event::getBeginning_Hour()
{
    return beginning_hour_;
}

/********************
 * Description  :   Accessor to get the ending hour of the event
 *
 * Input        :   None
 *
 * Output       :   Event's ending hour as an int
 ********************/
int Event::getEnding_Hour()
{
    return ending_hour_;
}

/********************
	* Description	:	This analyzes the number of males in the event
	*
	* Input			:	None
	*
	* Output		:	Percentage of males in the event as a double. Note that the return has not been converted to percent.
	********************/
double Event::getPercentageMale()
{
	double num_of_males = 0;
	
	for(int i = 0; i < participants_.size(); i++)
	{
		if(participants_.at(i)->getGender())
			num_of_males++;
	}

	return num_of_males/participants_.size();
}

/********************
	* Description	:	This analyzes the number of females in the event
	*
	* Input			:	None
	*
	* Output		:	percentage
	********************/
double Event::getPercentageFemale()
{
	double num_of_females = 0;
	
	for(int i = 0; i < participants_.size(); i++)
	{
		if(!participants_.at(i)->getGender())
			num_of_females++;
	}

	return num_of_females/participants_.size();
}

/********************
	* Description	:	This analyzes the age percentage
	*
	* Input			:	Upper limit age, lower limit age
	*
	* Output		:	percentage
	********************/
double Event::getPercentageAge(int upper_age, int lower_age)
{
	double num_of_users = 0;
	
	for(int i = 0; i < participants_.size(); i++)
	{
		if(participants_.at(i)->getAge() >= lower_age && participants_.at(i)->getAge() <= upper_age)
			num_of_users++;
	}

	return num_of_users/participants_.size();
}

// ***** MUTATORS ***** //
/********************
 * Description  :   Mutator to add a user to the event.
 *					This will also add the event to the user.
 *
 * Input        :   User pointer of the user
 *
 * Output       :   True if user successfully added, false if user already exists or could not be added
 ********************/
bool Event::addUser(User *user)
{
    if(addUserM(user))
	{
		user->addEventM(this);
		return true;
	}
	else
	{
		return false;
	}
}

/********************
 * Description  :   Mutator to add a user to the event.
 *
 * Input        :   User pointer of the user
 *
 * Output       :   True if user successfully added, false if user already exists or could not be added
 ********************/
bool Event::addUserM(User *user)
{
    for(int i = 0; i < participants_.size(); i++)
    {
        if(participants_[i]->getUserNumber() == user->getUserNumber())
            return false;
    }

    participants_.push_back(user);
    return true;
}

/********************
 * Description  :   Mutator to delete a user from the event.
 *
 * Input        :   User pointer of the user
 *
 * Output       :   True if user successfully deleted, false if user could not be deleted or does not exist
 ********************/
bool Event::deleteUser(User *user)
{
    for(int i = 0; i < participants_.size(); i++)
    {
        if(participants_[i]->getUserNumber() == user->getUserNumber())
        {
            participants_.erase(participants_.begin()+i);
            return true;
        }
    }
    return false;
}

/********************
 * Description  :   Mutator to set the event's name
 *
 * Input        :   New name of the event as a string
 *
 * Output       :   None
 ********************/
void Event::setName(string name)
{
    name_ = name;
}

/********************
 * Description  :   Mutator to set the event's description
 *
 * Input        :   New description of the event as a string
 *
 * Output       :   None
 ********************/
void Event::setDescription(string description)
{
    description_ = description;
}

/********************
 * Description  :   Mutator to set the event's date
 *
 * Input        :   New date of the event as a Date
 *
 * Output       :   None
 ********************/
void Event::setDate(Date* date)
{
    date_ = date;
}

/********************
 * Description  :   Mutator to set the event's category
 *
 * Input        :   New category of the event as an int that corresponds to the correct category
 *
 * Output       :   None
 ********************/
void Event::setCategory(int category)
{
    category_ = category;
}
