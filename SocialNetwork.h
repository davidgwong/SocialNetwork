/********************
 * File			:	SocialNetwork.h
 *
 * Author		:	David Wong
 * SID			:	44627107
 * Created		:	2013 November 11
 *
 * Description	:	This file implements the Social Network class signatures
 ********************/

#ifndef SOCIALNETWORK_H_INCLUDED
#define SOCIALNETWORK_H_INCLUDED

#include <vector>
#include "User.h"
#include "Calendar.h"
#include "Event.h"

class SocialNetwork
{

public:

	// ***** CONSTRUCTORS & DESTRUCTORS ***** //

	/********************
 * Description  :   Default constructor to make a new Social Network object.
 *
 * Input        :   None
 *
 * Output       :   New Social Network object.
 ********************/
	SocialNetwork();

	/********************
 * Description  :   Destructor for the Social Network object.
 *
 * Input        :   None
 *
 * Output       :   None
 ********************/
	~SocialNetwork();

	// ***** ACCESSORS ***** //
	/********************
 * Description  :   Accessor
 *
 * Input        :   None
 *
 * Output       :	Calendar*, this is the master calendar of the social network
 ********************/
	Calendar* getCalendar() const;

	/********************
 * Description  :   Accessor to get the number of users currently in the social network
 *
 * Input        :   None
 *
 * Output       :	int: the number of users in the social network
 ********************/
	int getNumUsers() const;

	/********************
 * Description  :   Accessor 
 *
 * Input        :   User*
 *
 * Output       :   User*: a user of the social network
 ********************/
	User* getUser(User* user) const;

	/********************
 * Description  :   Accessor to get a user based on the user name
 *
 * Input        :   string firstname, string lastname
 *
 * Output       :   User*: a user of the social network
 ********************/
	User* getUserBasedOnName(string firstname, string lastname) const;

	/********************
 * Description  :   Accessor
 *
 * Input        :   None
 *
 * Output       :	Vector of Users stored in Social Network
 ********************/
	vector<User*> getUsers() const;

	/********************
 * Description  :   Accessor to get an event in the social network based on event name
 *
 * Input        :   string event_name
 *
 * Output       :	Event*: pointer to the event
 ********************/
	Event* getEvent(string event_name) const;

	// ***** MUTATORS ***** //

	/********************
 * Description  :   Mutator
 *
 * Input        :   User* new_user
 *
 * Output       :   bool: true if the add is successful
 ********************/
	bool addNewUser(User* new_user);

	/********************
 * Description  :   Mutator
 *
 * Input        :   Date* date: date of new event, int beginning_hour: hour when event starts, int ending_hour: hour when event ends, string description: description of the event
 *					User* event_creator: first participant in event, int category: an integer value which represents the category of the event
 *
 * Output       :   None
 ********************/
	bool addNewEvent(Date* date, int beginning_hour, int ending_hour, string name, string description, User* event_creator, int category);

	/********************
 * Description  :   Mutator
 *
 * Input        :   User* user: the user to be deleted from the social network
 *
 * Output       :   bool: true if delete is succesfull
 ********************/
	//bool deleteUser(User* user);

	//bool deleteEvent(Event event);

	/********************
 * Description  :   Mutator, increments the user_number_counter to facilitate assigning a new user number
 *
 * Input        :   None
 *
 * Output       :   None
 ********************/
	void incrementUserCounter();

	// ***** ANALYZER METHODS ***** //

	/********************
	* Description	:	Gets the smallest number of friends linking to users, returns the smallest number. Returns -1 is there is no path from the start user to the end user
	*					In order to do so, creates a master list of friends in the yale format
	*
	* Input			:	User* StartUserPointer, User* EndUserPointer
	*
	* Output		:	int: the smallest number of friend "steps" linking two friends
	********************/
	int findSmallestConnections(User* User1, User* User2);

	/********************
	* Description	:	This analyzes the similar friends between two users
	*
	* Input			:	User 1 and user 2
	*
	* Output		:	Vector of users
	********************/
	vector<User*> findSimilarFriends(User* user1, User* user2);

	/********************
	* Description	:	This analyzes the number of males in the social network
	*
	* Input			:	None
	*
	* Output		:	double: percentage of male users in the social network
	********************/
	double getPercentageMale();

	/********************
	* Description	:	This analyzes the number of females in the social network
	*
	* Input			:	None
	*
	* Output		:	double: percentage of female users in the social network
	********************/
	double getPercentageFemale();

	/********************
	* Description	:	This analyzes the age percentage
	*
	* Input			:	Upper limit age, lower limit age
	*
	* Output		:	double: percentage of the social network users who fall within the age limits
	********************/
	double getPercentageAge(int age_upper, int age_lower);
	
private:
	// ***** HELPER METHODS ***** //
	
	/********************
	* Description	:	This does the actual computation of the distance between two friends using the input friend list (in yale format) and dijkstra's algorithm
	*
	* Input			:	int NumUsers: the number of users in the network, int StartUser: the starting user of the algorithm - must be a valid positive user, int EndUser: the ending user of the algorithm - must be a valid positive user, vector<int> FriendsOfUser array of friends who are friends with a given user, vector<int> UserInitialIndex array whose i-th value is the index number of first value in the weights array corresponding to node i
	*
	* Output		:	int: the distance betweent the two friends, returns -1 if there is no path
	********************/
	int CalculateShortestPath(int NumUsers, int StartUser, int EndUser,  vector< vector<int> >* PathRecord, vector<int> FriendsOfUser, vector<int> UserInitialIndex);

	/** UpdatePathRecord - Updates a Pathrecord matrix with new information about the shortest path to a given node
	@param PathRecord matrix storing the shortest path to a starting node to all the other nodes. Columns are path steps, rows are destination nodes
	@param CurrentNode the node that Dijkstra's algorithm is currently visiting
	@param DestinationNode the node whose path is getting updated, the updated row of PathRecord
	*/
	void UpdatePathRecord(vector< vector<int> >* PathRecord, int CurrentNode, int DestinationNode);

	//	DATA MEMBERS //

	Calendar* master_calendar_;
	vector<User*> users_;
	vector<Event*> event_list_;
	int user_number_counter_;
};

#endif // SOCIALNETWORK_H_INCLUDED
