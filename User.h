/*********************
 * File			:	User.h
 * 
 * Author		:	John Henderson
 * SID			:	28132108
 * Created		:	November 11 2013
 *
 * Description	:	This file defines the User class
 *********************/


#include<string>
#include<vector>
#include<list>
#include "Event.h"

using namespace std;

#ifndef C___User_h
#define C___User_h

class User
{
public:
	// CONSTRUCTORS //

	// Parameterized constructor
	// @param email --> this is the email of the user
	// @param first_name --> this is the first_name of the user
	// @param age --> this is the age of the user
	User(string email, string first_name, string last_name, int age, bool gender);

	// ACCESSORS //

	int getUserNumber();
	// Accessor: gets the user number of a user
	// Returns: user number as an integer

	string getEmail();
	// Accessor: gets the email of a user
	// Returns: user email as a string

	string getFirstName();
	// Accessor: gets the fist name of a user
	// Returns: user first name as a string
	
	string getLastName();
	// Accessor: gets the last name of a user
	// Returns: user last name as a string
	
	int getAge();
	// Accessor: gets the age of a user
	// Returns: user age as an integer
	
	bool getGender();
	// Accessor: gets the gender of a user
	// Returns: user gender as a boolean

	vector<User*> getFriends();
	//Accessor: gets the friends of a user
	//Returns: user friends as a vector of users

	vector<class Event*> getEvents();
	//Accessor: gets the events of a user
	//Returns: events that a user is attending 

	// MUTATORS //
	void setEmail(string email);
	// Mutator: sets the email of a user
	// @param email --> the new email of a user

	void setFirstName(string firstName);
	// Mutator: sets the FirstName of a user
	// @param firstName --> the new first name of a user

	void setLastName(string lastName);
	// Mutator: sets the LastName of a user
	// @param lastName --> the new last name of a user

	void setUserNumber(int userNumber);
	// Mutator: sets the userNumber of a user
	// @param lastName --> the new userNunmber of a user

	void addFriend(User* new_friend);

	void addFriendM(User* new_friend);

	void addEvent(class Event* new_event);

	void addEventM(class Event* new_event);

private:
	int user_number_;
	string email_;
	string first_name_;
	string last_name_;
	int age_;
	bool gender_;
	vector<User*> friends_;
	vector<class Event*> user_events_;
};

#endif