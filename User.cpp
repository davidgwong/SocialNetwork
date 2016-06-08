/*********************
 * File			:	User.cpp
 * 
 * Author		:	John Henderson
 * SID			:	28132108
 * Created		:	November 11 2013
 *
 * Description	:	This file defines the User class
 *********************/

#include<string>
#include<vector>
#include"Calendar.h"
#include"User.h"
#include"Event.h"

using namespace std;

// CONSTRUCTORS //

User::User(string email, string first_name, string last_name, int age, bool gender)
// Parameterized constructor
// @param email --> this is the email of the user
// @oaran first_name --> this is the first_name of the user
{
	email_ = email;
	first_name_ = first_name;
	last_name_ = last_name;
	age_ = age;
	gender_ = gender;
}

// ACCESSORS //

int User::getUserNumber()
// Accessor: gets the user number of a user
// Returns: user number as an integer
{
	return user_number_;
}

string User::getEmail()
// Accessor: gets the email of a user
// Returns: user email as a string
{
	return email_;
}

string User::getFirstName()
// Accessor: gets the fist name of a user
// Returns: user first name as a string
{
	return first_name_;
}

string User::getLastName()
// Accessor: gets the last name of a user
// Returns: user last name as a string
{
	return last_name_;
}

int User::getAge()
// Accessor: gets the age of a user
// Returns: user age as an integer
{
	return age_;
}

bool User::getGender()
// Accessor: gets the gender of a user
// Returns: user gender as a boolean
{
	return gender_;
}

vector<User*> User::getFriends()
//Accessor: gets the friends of a user
//Returns: user friends as a vector of
{
	return friends_;
}

vector<Event*> User::getEvents()
//Accessor: gets the events of a user
//Returns: events that a user is attending 
{
	return user_events_;
}
// MUTATORS //
void User::setEmail(string email)
// Mutator: sets the email of a user
// @param email --> the new email of a user
{
	email_ = email;
}

void User::setFirstName(string firstName)
// Mutator: sets the FirstName of a user
// @param firstName --> the new first name of a user
{
	first_name_ = firstName;
}

void User::setLastName(string lastName)
// Mutator: sets the LastName of a user
// @param lastName --> the new last name of a user
{
	last_name_ = lastName;
}

void User::setUserNumber(int userNumber)
// Mutator: sets the userNumber of a user
// @param lastName --> the new userNunmber of a user
{
	user_number_ = userNumber;
}

void User::addFriend(User* new_friend)
{
	friends_.push_back(new_friend);
	new_friend->addFriendM(this);
}

void User::addFriendM(User* new_friend)
{
	friends_.push_back(new_friend);
}

void User::addEvent(Event* new_event)
{
	user_events_.push_back(new_event);
	new_event->addUserM(this);
}

void User::addEventM(Event* new_event)
{
	user_events_.push_back(new_event);
}