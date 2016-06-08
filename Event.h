/*********************
 * File         :   Event.h
 *
 * Author       :   John and David
 * SID          :   28132108
 * Created      :   November 17 2013
 *
 * Description  :   This file defines the Event class
 *********************/

#ifndef C___Event_h
#define C___Event_h

#include<string>
#include<vector>
#include "Date.hpp"
#include "User.h"

using namespace std;

class Event
{
public:

	// ***** CONSTRUCTORS & DESTRUCTORS ***** //
    /********************
     * Description  :   Default constructor to make a new Event object.
     *
     * Input        :   None
     *
     * Output       :   New Event object.
     ********************/
    Event();
	/********************
	 * Description  :   Constructor to make a new Event object.
	 *
	 * Input        :   Event date, beginning hour, ending hour, name of event, event description, event creator, event category
	 *
	 * Output       :   New Event object.
	 ********************/
	Event(Date* event_date, int beginning_hour, int ending_hour, string name, string description, User* event_creator, int category);
	/********************
	 * Description  :   Default destructor
	 *
	 * Input        :   None
	 *
	 * Output       :   Deletes event
	 ********************/
    ~Event();

    // ***** ACCESSORS ***** //
	/********************
	 * Description  :   Accessor to get the name of the event
	 *
	 * Input        :   None
	 *
	 * Output       :   Event's name as a string
	 ********************/
    string getName();
	/********************
	 * Description  :   Accessor to get the description of the event
	 *
	 * Input        :   None
	 *
	 * Output       :   Event's description as a string
	 ********************/
    string getDescription();
	/********************
	 * Description  :   Accessor to get the category of the event
	 *
	 * Input        :   None
	 *
	 * Output       :   Event's category as a string
	 ********************/
    string getCategory();
	/********************
	 * Description  :   Accessor to get the date of the event
	 *
	 * Input        :   None
	 *
	 * Output       :   Event's date as a string
	 ********************/
    string getDateString();
	/********************
	 * Description  :   Accessor to get the date of the event
	 *
	 * Input        :   None
	 *
	 * Output       :   Event's date as a Date
	 ********************/
	Date* getDate();
	/********************
	 * Description  :   Accessor to get the participants of the event
	 *
	 * Input        :   None
	 *
	 * Output       :   Participants as a vector of User pointers
	 ********************/
    vector<User*> getParticipants();
	/********************
	 * Description  :   Accessor to get the beginning hour of the event
	 *
	 * Input        :   None
	 *
	 * Output       :   Event's beginning hour as an int
	 ********************/
    int getBeginning_Hour();
	/********************
	 * Description  :   Accessor to get the ending hour of the event
	 *
	 * Input        :   None
	 *
	 * Output       :   Event's ending hour as an int
	 ********************/
    int getEnding_Hour();
	/********************
	* Description	:	This analyzes the number of males in the event
	*
	* Input			:	None
	*
	* Output		:	Percentage of males in the event as a double. Note that the return has not been converted to percent.
	********************/
	double getPercentageMale();
	/********************
	* Description	:	This analyzes the number of females in the event
	*
	* Input			:	None
	*
	* Output		:	percentage
	********************/
	double getPercentageFemale();
	/********************
	* Description	:	This analyzes the age percentage
	*
	* Input			:	Upper limit age, lower limit age
	*
	* Output		:	percentage
	********************/
	double getPercentageAge(int age_upper, int age_lower);

    // ***** MUTATORS ***** //
	/********************
	 * Description  :   Mutator to add a user to the event.
	 *					This will also add the event to the user.
	 *
	 * Input        :   User pointer of the user
	 *
	 * Output       :   True if user successfully added, false if user already exists or could not be added
	 ********************/
    bool addUser(User* user);
	/********************
	 * Description  :   Mutator to add a user to the event.
	 *
	 * Input        :   User pointer of the user
	 *
	 * Output       :   True if user successfully added, false if user already exists or could not be added
	 ********************/
	bool addUserM(User* user);
	/********************
	 * Description  :   Mutator to delete a user from the event.
	 *
	 * Input        :   User pointer of the user
	 *
	 * Output       :   True if user successfully deleted, false if user could not be deleted or does not exist
	 ********************/
    bool deleteUser(User* user);
	/********************
	 * Description  :   Mutator to set the event's name
	 *
	 * Input        :   New name of the event as a string
	 *
	 * Output       :   None
	 ********************/
    void setName(string name);
	/********************
	 * Description  :   Mutator to set the event's description
	 *
	 * Input        :   New description of the event as a string
	 *
	 * Output       :   None
	 ********************/
    void setDescription(string description);
	/********************
	 * Description  :   Mutator to set the event's date
	 *
	 * Input        :   New date of the event as a Date
	 *
	 * Output       :   None
	 ********************/
    void setDate(Date* date);
	/********************
	 * Description  :   Mutator to set the event's category
	 *
	 * Input        :   New category of the event as an int that corresponds to the correct category
	 *
	 * Output       :   None
	 ********************/
    void setCategory(int category);

private:
    Date* date_;
    int beginning_hour_;
    int ending_hour_;
    int length_;
    string name_;
    string description_;
    vector<User*> participants_;
    int category_;
    static string categories_list_[];

};

#endif

