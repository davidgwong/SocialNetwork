/********************
 * File         :   SocialNetwork.cpp
 *
 * Author       :   David Wong and John Henderson
 * SID          :   44627107 and 28132108
 * Created      :   2013 November 11
 *
 * Description  :   This file implements the Social Network class
 ********************/

#include "SocialNetwork.h"
#include "Date.hpp"
#include "Calendar.h"
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

// ***** CONSTRUCTORS & DESTRUCTORS ***** //
/********************
 * Description  :   Default constructor to make a new Social Network object.
 *
 * Input        :   None
 *
 * Output       :   New Social Network object.
 ********************/
SocialNetwork::SocialNetwork()
{
    master_calendar_ = new Calendar();
	user_number_counter_ = 0;
}

/********************
 * Description  :   Destructor for the Social Network object.
 *
 * Input        :   None
 *
 * Output       :   None
 ********************/
SocialNetwork::~SocialNetwork()
{
}

// ***** ACCESSORS ***** //
/********************
 * Description  :   Accessor
 *
 * Input        :   None
 *
 * Output       :	Calendar*, this is the master calendar of the social network
 ********************/
Calendar* SocialNetwork::getCalendar() const
{
    return master_calendar_;
}

/********************
 * Description  :   Accessor to get the number of users currently in the social network
 *
 * Input        :   None
 *
 * Output       :	int: the number of users in the social network
 ********************/
int SocialNetwork::getNumUsers() const
{
    return users_.size();
}

/********************
 * Description  :   Accessor 
 *
 * Input        :   User*
 *
 * Output       :   User*: a user of the social network
 ********************/
User* SocialNetwork::getUser(User* user) const
{
    for(int i = 0; i < users_.size(); i++)
    {
        if (users_.at(i)->getUserNumber() == user->getUserNumber())
            return users_.at(i);
    }
}

/********************
 * Description  :   Accessor to get a user based on the user name
 *
 * Input        :   string firstname, string lastname
 *
 * Output       :   User*: a user of the social network
 ********************/
User* SocialNetwork::getUserBasedOnName(string firstname, string lastname) const
{
	for(int i=0; i<getNumUsers(); i++)
	{
		if(users_.at(i)->getFirstName() == firstname && users_.at(i)->getLastName() == lastname)
			return users_.at(i);
	}
}

/********************
 * Description  :   Accessor
 *
 * Input        :   None
 *
 * Output       :	Vector of Users stored in Social Network
 ********************/
vector<User*> SocialNetwork::getUsers() const
{
    return users_;
}

/********************
 * Description  :   Accessor to get an event in the social network based on event name
 *
 * Input        :   string event_name
 *
 * Output       :	Event*: pointer to the event
 ********************/
Event* SocialNetwork::getEvent(string event_name) const
{
	string event_name_upper = event_name;
	transform(event_name_upper.begin(), event_name_upper.end(), event_name_upper.begin(), ::toupper);

	for(int i = 0; i < event_list_.size(); i++)
	{
		string event_list_name = event_list_.at(i)->getName();
		transform(event_list_name.begin(), event_list_name.end(), event_list_name.begin(), ::toupper);

		if(event_list_name == event_name_upper)
		{
			return event_list_.at(i);
		}
	}

	return NULL;
}

// ***** MUTATORS ***** //
/********************
 * Description  :   Mutator
 *
 * Input        :   User* new_user
 *
 * Output       :   bool: true if the add is successful
 ********************/
bool SocialNetwork::addNewUser(User* new_user)
{
    for(int i = 0; i < users_.size(); i++)
    {
        if (users_.at(i)->getEmail() == new_user->getEmail())
            return false;
    }
	// Assign user number to the new user
	new_user->setUserNumber(user_number_counter_);
	incrementUserCounter(); //increment user counter to prep for the next user

	// Add the user to the social network list
    users_.push_back(new_user);
    return true;
}

/********************
 * Description  :   Mutator
 *
 * Input        :   Date* date: date of new event, int beginning_hour: hour when event starts, int ending_hour: hour when event ends, string description: description of the event
 *					User* event_creator: first participant in event, int category: an integer value which represents the category of the event
 *
 * Output       :   None
 ********************/
bool SocialNetwork::addNewEvent(Date* date, int beginning_hour, int ending_hour, string name, string description, User* event_creator, int category)
{
    // Check to see if daySlot exists. If not, create it
    //Date* event_date = new Date(event_year, event_month, event_day); //create a local date based on input times
    if (!master_calendar_->doesDaySlotExist(date))  //check for day slot is a method of the calendar class
    {
        master_calendar_->addDaySlot(date);
    }
	else
	{
		date = master_calendar_->getDaySlotDate(date);
	}

    // Add event to DaySlot
	Event* temp_event = new Event(date, beginning_hour, ending_hour, name, description, event_creator, category);
    if (master_calendar_->getDaySlot(date)->addEvent(temp_event))
	{
		event_list_.push_back(temp_event);
		return true;
	}
	else
	{
		delete temp_event; // Delete the temp event object from heap
		return false;
	}

}

/********************
 * Description  :   Mutator
 *
 * Input        :   User* user: the user to be deleted from the social network
 *
 * Output       :   bool: true if delete is succesfull
 ********************/
//bool SocialNetwork::deleteUser(User* user)
//{
//	bool found_in_SN = false;
//	// Remove from the SN user list
//	for(int i = 0; i < users_.size(); i++)
//    {
//        if (users_.at(i)->getUserNumber() == user->getUserNumber())
//        {
//			users_.erase(users_.begin() + i);
//			found_in_SN = true;
//			break;
//		}
//	}
//	
//	// Return false if the user is not is social network
//	if(!found_in_SN)
//		return false;
//
//	
//	// Remove from the user's friends' lists
//	for(int j = 0; j<user->getFriends().size(); j++)
//	{
//		//vector<User*> user_friends = user->getFriends().at(j)->getFriends(); //This is friend list of the delete user's jth friend
//		//int temp_size = user_friends.size();
//		//int position;
//		//for(int k = 0; k<temp_size; k++)
//		//{
//		//	if (user_friends.at(k)->getUserNumber() == user->getUserNumber())
//		//	{
//		//		position = k;
//		//	}
//		//}
//		//vector<User*>::iterator it = (user->getFriends().at(j)->getFriends().begin()) + position;
//		//user->getFriends().at(j)->getFriends().erase(it);
//
//		int thesize = user->getFriends().at(j)->getFriends().size() - 1;
//		auto iend = user->getFriends().at(j)->getFriends().begin() + thesize;
//
//		for(auto ii = user->getFriends().at(j)->getFriends().begin(); ii != iend; ++ii)
//		{
//			if ((*ii)->getUserNumber() == user->getUserNumber())
//			{
//				ii = user->getFriends().at(j)->getFriends().erase(ii);
//				if (ii != user->getFriends().at(j)->getFriends().begin())
//				{
//					ii = prev(ii);
//					continue;
//				}
//			}
//		}
//
//	}
//
//
//	// Remove from all of the user's events' lists
//	for(int j = 0; j<user->getEvents().size(); j++)
//	{
//		//vector<User*> event_participants = user->getEvents().at(j)->getParticipants(); //This is friend list of the delete user's jth friend
//		for(int k = 0; k<user->getEvents().at(j)->getParticipants().size(); k++)
//		{
//			if (user->getEvents().at(j)->getParticipants().at(k)->getUserNumber() == user->getUserNumber())
//				user->getEvents().at(j)->getParticipants().erase(user->getEvents().at(j)->getParticipants().begin() + k);
//		}
//	}
//
//	
//	// Remove user from heap
//	delete user;
//            
//	return true;
//}

/********************
 * Description  :   Mutator
 *
 * Input        :   None
 *
 * Output       :   None
 ********************/
//bool SocialNetwork::deleteEvent(Calendar event)
//{
//}

/********************
 * Description  :   Mutator, increments the user_number_counter to facilitate assigning a new user number
 *
 * Input        :   None
 *
 * Output       :   None
 ********************/
void SocialNetwork::incrementUserCounter()
{
	user_number_counter_++;
}

// ***** ANALYZER METHODS ***** //

/********************
	* Description	:	Gets the smallest number of friends linking to users, returns the smallest number. Returns -1 is there is no path from the start user to the end user
	*					In order to do so, creates a master list of friends in the yale format
	*
	* Input			:	User* StartUserPointer, User* EndUserPointer
	*
	* Output		:	int: the smallest number of friend "steps" linking two friends
	********************/
int SocialNetwork::findSmallestConnections(User* StartUserPointer, User* EndUserPointer)
{
	// Need to create yale format vectors for use in algorithm. These vectors represent the master list of friends
	vector<int> UserInitialIndex;
	vector<int> FriendsOfUser;
	
	int i = 0; //i will be main incrementer to increment through and create FriendsofUser

		for(int j=0; j<users_.size(); j++) //j will be incrementer to increment through the master vector of Users
		{
			UserInitialIndex.push_back(i);

			for(int k=0; k<users_.at(j)->getFriends().size(); k++) //k is the incrementer to increment through the friends of the jth user
			{
				for(int l=0; l<users_.size(); l++)
				{
					if(users_.at(l)->getUserNumber() == users_.at(j)->getFriends().at(k)->getUserNumber()) //Comparison to see if the friend link exists
					{
						FriendsOfUser.push_back(l); //This means that the jth user is friends with the lth user
						i++; //Increment i to move through FriendsOfUser
					}
				}
			}
		}
	UserInitialIndex.push_back(i);  //Allows the count of the friends of the last user in the user list

	// Get position of users in social network user list
	int StartUserPosition;
	int EndUserPosition;
	for(int x=0; x<users_.size(); x++)
	{
		if(StartUserPointer->getUserNumber() == users_.at(x)->getUserNumber())
			StartUserPosition = x;
		else if(EndUserPointer->getUserNumber() == users_.at(x)->getUserNumber())
			EndUserPosition = x;
	}

	//Initialise PathRecord vector
	vector< vector< int > >* PathRecord = new vector< vector< int > >;
	for ( int i = 0; i < users_.size(); i++ )
	{
		PathRecord->push_back ( vector<int>() );
		for ( int j = 0; j < users_.size(); j++ )
			PathRecord->at(i).push_back (0);
	 }

	// Call shortest path to get the shortest path between two friends
	int answer = CalculateShortestPath(users_.size(), StartUserPosition, EndUserPosition, PathRecord, FriendsOfUser, UserInitialIndex);

	// Print out path
	if(answer != -1)  // -1 would mean that there is no path between two users
	{
		cout<<"the shortest path between two friends is ";
		for(int s = 0; s<answer;s++)
		{
			cout<<users_.at(PathRecord->at(EndUserPosition).at(s))->getFirstName()<<"-";
		}
		cout<<users_.at(EndUserPosition)->getFirstName();
		cout<<endl;
	}

	return answer;
}

/********************
	* Description	:	This analyzes the similar friends between two users
	*
	* Input			:	User 1 and user 2
	*
	* Output		:	Vector of users
	********************/
vector<User*> SocialNetwork::findSimilarFriends(User* user1, User* user2)
{
	vector<User*> similar_friends;

	for(int i = 0; i < user1->getFriends().size(); i++)
	{
		for(int j = 0; j < user2->getFriends().size(); j++)
		{
			if(user1->getFriends().at(i)->getUserNumber() == user2->getFriends().at(j)->getUserNumber())
			{
				similar_friends.push_back(user1->getFriends().at(i));
				break;
			}
		}
	}
	return similar_friends;
}

/********************
	* Description	:	This analyzes the number of males in the social network
	*
	* Input			:	None
	*
	* Output		:	double: percentage of male users in the social network
	********************/
double SocialNetwork::getPercentageMale()
{
	double num_of_males = 0;
	
	for(int i = 0; i < users_.size(); i++)
	{
		if(users_.at(i)->getGender())
			num_of_males++;
	}

	return num_of_males/users_.size();
}

/********************
	* Description	:	This analyzes the number of females in the social network
	*
	* Input			:	None
	*
	* Output		:	double: percentage of female users in the social network
	********************/
double SocialNetwork::getPercentageFemale()
{
	double num_of_females = 0;
	
	for(int i = 0; i < users_.size(); i++)
	{
		if(!users_.at(i)->getGender())
			num_of_females++;
	}

	return num_of_females/users_.size();
}

/********************
	* Description	:	This analyzes the age percentage
	*
	* Input			:	Upper limit age, lower limit age
	*
	* Output		:	double: percentage of the social network users who fall within the age limits
	********************/
double SocialNetwork::getPercentageAge(int upper_age, int lower_age)
{
	double num_of_users = 0;
	
	for(int i = 0; i < users_.size(); i++)
	{
		if(users_.at(i)->getAge() >= lower_age && users_.at(i)->getAge() <= upper_age)
			num_of_users++;
	}

	return num_of_users/users_.size();
}

	// ***** HELPER METHODS ***** //

/********************
	* Description	:	This does the actual computation of the distance between two friends using the input friend list (in yale format) and dijkstra's algorithm
	*
	* Input			:	int NumUsers: the number of users in the network, int StartUser: the starting user of the algorithm - must be a valid positive user, int EndUser: the ending user of the algorithm - must be a valid positive user, vector<int> FriendsOfUser array of friends who are friends with a given user, vector<int> UserInitialIndex array whose i-th value is the index number of first value in the weights array corresponding to node i
	*
	* Output		:	int: the distance betweent the two friends, returns -1 if there is no path
	********************/
int SocialNetwork::CalculateShortestPath(int NumUsers, int StartUser, int EndUser,  vector< vector<int> >* PathRecord, vector<int> FriendsOfUser, vector<int> UserInitialIndex)
{
	//Declare and initialize variable and arrays
	vector<int> DistanceFromStartUser; //This vector contains the current shortest path from the start user to all other users

	for(int n=0; n<NumUsers; n++)
	{
		DistanceFromStartUser.push_back(NumUsers+1); //Initialize distances as to the Number of Users
	}
	DistanceFromStartUser.at(StartUser)=0;

	vector<bool> VisitedUsers; //This vector will contain the list of visited users
	for(int n=0; n<NumUsers; n++)
		VisitedUsers.push_back(false); //Initialize each element of the list to false. Change it to true when the node has been visited
	VisitedUsers.at(StartUser)=true;

	int CurrentUser = StartUser; //Current node is the node currently being visited

	//The actual algorithm in action
	while(CurrentUser != EndUser) //Because we're always visting node with smallest path next, we can end if current node is end node
	{
		int i = UserInitialIndex.at(CurrentUser); //Index used to progress through EdgeDestinationNode arrays

		while(i < UserInitialIndex.at(CurrentUser+1)) //Check DestinationNode are still starting from CurrentNode
		{
			if(DistanceFromStartUser.at(FriendsOfUser.at(i)) > (DistanceFromStartUser.at(CurrentUser) + 1)) //Test for benefit of new weight
			{
				DistanceFromStartUser.at(FriendsOfUser.at(i)) = (DistanceFromStartUser.at(CurrentUser) + 1); //If there is benefit, update shortest path array
				UpdatePathRecord(PathRecord, CurrentUser, FriendsOfUser.at(i));
			}
	
		i++;

		}

		VisitedUsers.at(CurrentUser) = true;

		//Find un-visited user with shortest path thus far and set to CurrentUser
		int SmallestDistanceIndex = NumUsers+1;
		bool NodeHasChanged = false;
		for(int j=0; j<NumUsers; j++)
		{
			if(VisitedUsers.at(j)==false && DistanceFromStartUser.at(j)<SmallestDistanceIndex)
			{
				CurrentUser = j;
				SmallestDistanceIndex = DistanceFromStartUser.at(j);
				NodeHasChanged = true;
			}
		}
	
	if(NodeHasChanged == false)
		return -1; //if we arrive here it means that there is no path to the end user from the start user
	}

	return DistanceFromStartUser.at(EndUser); //Return the value stored in the EndNode position of the distance array

}

void SocialNetwork::UpdatePathRecord(vector< vector<int> >* PathRecord, int CurrentNode, int DestinationNode)
{
	int i = 0;
	while(PathRecord->at(CurrentNode).at(i) != 0)
	{
		PathRecord->at(DestinationNode).at(i) = PathRecord->at(CurrentNode).at(i);  //This copies the shortest path to get the currently visited node to the destination node in question
		i++; 
	}
	PathRecord->at(DestinationNode).at(i) = CurrentNode;
}