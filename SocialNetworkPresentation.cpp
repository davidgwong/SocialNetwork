/********************
 * File			:	SocialNetworkPresentation.cpp
 * 
 * Author		:	David Wong
 * SID			:	44627107
 * Created		:	2013 November 18
 *
 * Description	:	This file is used to present the implentation of the Social Network to the Professor and TAs.
 ********************/

#include <iostream>
#include "Date.hpp"
#include "DaySlot.h"
#include "Event.h"
#include "SocialNetwork.h"
#include "User.h"
#include "Calendar.h"

using namespace std;

int main()
{
	// ========== PART 1: Creation of Social Network ========== //
	cout << "Creating the Social Network..." << endl;
	SocialNetwork Facebook; // Creating a new SocialNetwork object called 'Facebook'

	cout << "The number of users currently registered in the Social Network: ";
	cout << Facebook.getNumUsers() << endl; // Verifying that Facebook was created by outputting the number of users in Facebook

	system("pause");

	// ========== PART 2: Populating the Social Network with Users ========== //
	cout << endl << "Populating the Social Network with new users..." << endl;

	Facebook.addNewUser(new User ("JohnH@gmail.com", "John", "Henderson", 21, true));				// User 1
	Facebook.addNewUser(new User ("DavidW@gmail.com", "David", "Wong", 20, true));					// User 2
	Facebook.addNewUser(new User ("Batman@gmail.com", "Bruce", "Wayne", 35, true));					// User 3
	Facebook.addNewUser(new User ("EmilyM@gmail.com", "Emily", "McEmily", 50, false));				// User 4
	Facebook.addNewUser(new User ("BobM@gmail.com", "Bob", "McBob", 50, true));						// User 5
	Facebook.addNewUser(new User ("AngelinaM@gmail.com", "Angelina", "McAngelina", 26, false));		// User 6
	Facebook.addNewUser(new User ("WinstonM@gmail.com", "Winston", "McWinston", 50, true));			// User 7
	Facebook.addNewUser(new User ("MrBean@gmail.com", "Mr", "Bean", 55, true));						// User 8
	Facebook.addNewUser(new User ("Spongebob@gmail.com", "Spongebob", "Squarepants", 12, true));	// User 9
	Facebook.addNewUser(new User ("SailorMoon@gmail.com", "Sailor", "Moon", 16, false));			// User 10
	Facebook.addNewUser(new User ("JackieC@gmail.com", "Jackie", "Chan", 48, true));				// User 11
	Facebook.addNewUser(new User ("JaneD@gmail.com", "Jane", "Doe", 35, false));					// User 12
	Facebook.addNewUser(new User ("LonelyM@gmail.com", "Lonely", "Man", 26, true));					// User 13
	Facebook.addNewUser(new User ("CharlotteW@gmail.com", "Charlotte", "White", 23, false));		// User 14
	Facebook.addNewUser(new User ("LucyC@gmail.com", "Lucy", "Chan", 29, false));					// User 15
	Facebook.addNewUser(new User ("BrandonD@gmail.com", "Brandon", "Davis", 32, true));				// User 16
	Facebook.addNewUser(new User ("BenjaminD@gmail.com", "Benjamin", "Davis", 30, true));			// User 17
	Facebook.addNewUser(new User ("AshleyG@gmail.com", "Ashley", "Green", 25, false));				// User 18
	Facebook.addNewUser(new User ("RoxyC@gmail.com", "Roxy", "Cleopatra", 37, false));				// User 19
	Facebook.addNewUser(new User ("JennyL@gmail.com", "Jenny", "Lo", 42, false));					// User 20

	cout << "The number of users now registered in the Social Network: ";
	cout << Facebook.getNumUsers() << endl; // Verifying that 20 Users were created and added to Facebook

	system("pause");

	// ========== PART 3: Verifying that duplicate Users cannot be added ========== //
	cout << endl << "Verifying that duplicate users cannot be added..." << endl;
	if (Facebook.addNewUser(new User ("JohnH@gmail.com", "John", "Henderson", 21, true)))
		cout << "Another 'John Henderson' was added!" << endl;
	else cout << "Another 'John Henderson' was not added!" << endl;

	system("pause");

	// ========== PART 4: Populating the Social Network with Events ========== //
	cout << endl << "Populating the Social Network with new events..." << endl;

	Facebook.addNewEvent(new Date(2013,11,25),13,14,"CPSC 260 Project Presentation","The Three Percent!!!",Facebook.getUserBasedOnName("David","Wong"),3);									// Event 1
	Facebook.addNewEvent(new Date(2013,12,25),9,17,"Christmas Party!","Merry Christmas everyone!",Facebook.getUserBasedOnName("David","Wong"),6);											// Event 2
	Facebook.addNewEvent(new Date(2013,12,25),11,13,"Davis Family & Friend Christmas Potluck","Please bring some food to share! :-)",Facebook.getUserBasedOnName("Brandon","Davis"),6);		// Event 3
	Facebook.addNewEvent(new Date(2013,12,26),9,17,"Boxing Day!","Buy ALL the Surface Pro 2s!",Facebook.getUserBasedOnName("David","Wong"),6);												// Event 4
	Facebook.addNewEvent(new Date(2013,11,30),9,17,"Tough Guys Sporting Event","How tough are ya?",Facebook.getUserBasedOnName("Spongebob","Squarepants"),0);								// Event 5

	cout << "The number of events created in the Social Network: ";
	cout << Facebook.getCalendar()->getNumEvents() << endl; // Verifying that 5 Events were created and added to Facebook

	system("pause");

	// ========== PART 5: Verifying that duplicate Events cannot be added ========== //
	cout << endl << "Verifying that duplicate events cannot be added..." << endl;
	if (Facebook.addNewEvent(new Date(2013,11,25),13,14,"CPSC 260 Project Presentation","The Three Percent!!!",Facebook.getUserBasedOnName("David","Wong"),3))
		cout << "Another 'CPSC 260 Project Presentation' was added!" << endl;
	else cout << "Another 'CPSC 260 Project Presentation' was not added!" << endl;

	system("pause");

	// ========== PART 6: Populating the Events with Users ========== //
	cout << endl << "Populating the events with users..." << endl;

	Facebook.getEvent("CPSC 260 Project Presentation")->addUser(Facebook.getUserBasedOnName("John", "Henderson"));

	Facebook.getEvent("Davis Family & Friend Christmas Potluck")->addUser(Facebook.getUserBasedOnName("Benjamin", "Davis"));
	Facebook.getEvent("Davis Family & Friend Christmas Potluck")->addUser(Facebook.getUserBasedOnName("Emily", "McEmily"));
	Facebook.getEvent("Davis Family & Friend Christmas Potluck")->addUser(Facebook.getUserBasedOnName("Angelina", "McAngelina"));
	Facebook.getEvent("Davis Family & Friend Christmas Potluck")->addUser(Facebook.getUserBasedOnName("Winston", "McWinston"));
	Facebook.getEvent("Davis Family & Friend Christmas Potluck")->addUser(Facebook.getUserBasedOnName("Bob", "McBob"));

	Facebook.getEvent("Christmas Party!")->addUser(Facebook.getUserBasedOnName("John", "Henderson"));
	Facebook.getEvent("Christmas Party!")->addUser(Facebook.getUserBasedOnName("Bruce", "Wayne"));
	Facebook.getEvent("Christmas Party!")->addUser(Facebook.getUserBasedOnName("Mr", "Bean"));
	Facebook.getEvent("Christmas Party!")->addUser(Facebook.getUserBasedOnName("Spongebob", "Squarepants"));
	Facebook.getEvent("Christmas Party!")->addUser(Facebook.getUserBasedOnName("Sailor", "Moon"));
	Facebook.getEvent("Christmas Party!")->addUser(Facebook.getUserBasedOnName("Jackie", "Chan"));
	Facebook.getEvent("Christmas Party!")->addUser(Facebook.getUserBasedOnName("Charlotte", "White"));
	Facebook.getEvent("Christmas Party!")->addUser(Facebook.getUserBasedOnName("Ashley", "Green"));

	Facebook.getEvent("Boxing Day!")->addUser(Facebook.getUserBasedOnName("John", "Henderson"));
	Facebook.getEvent("Boxing Day!")->addUser(Facebook.getUserBasedOnName("Bruce", "Wayne"));
	Facebook.getEvent("Boxing Day!")->addUser(Facebook.getUserBasedOnName("Jenny", "Lo"));
	Facebook.getEvent("Boxing Day!")->addUser(Facebook.getUserBasedOnName("Lucy", "Chan"));

	Facebook.getEvent("Tough Guys Sporting Event")->addUser(Facebook.getUserBasedOnName("John", "Henderson"));
	Facebook.getEvent("Tough Guys Sporting Event")->addUser(Facebook.getUserBasedOnName("David", "Wong"));

	system("pause");

	// ========== PART 7: Populating the Users with friends ========== //
	cout << endl << "Populating the Users with friends..." << endl;

	Facebook.getUserBasedOnName("John", "Henderson")->addFriend(Facebook.getUserBasedOnName("David", "Wong"));
	Facebook.getUserBasedOnName("John", "Henderson")->addFriend(Facebook.getUserBasedOnName("Jackie", "Chan"));
	Facebook.getUserBasedOnName("John", "Henderson")->addFriend(Facebook.getUserBasedOnName("Benjamin", "Davis"));
	Facebook.getUserBasedOnName("John", "Henderson")->addFriend(Facebook.getUserBasedOnName("Ashley", "Green"));
	Facebook.getUserBasedOnName("John", "Henderson")->addFriend(Facebook.getUserBasedOnName("Sailor", "Moon"));
	Facebook.getUserBasedOnName("John", "Henderson")->addFriend(Facebook.getUserBasedOnName("Mr", "Bean"));
	Facebook.getUserBasedOnName("John", "Henderson")->addFriend(Facebook.getUserBasedOnName("Bruce", "Wayne"));

	Facebook.getUserBasedOnName("David", "Wong")->addFriend(Facebook.getUserBasedOnName("Spongebob", "Squarepants"));
	Facebook.getUserBasedOnName("David", "Wong")->addFriend(Facebook.getUserBasedOnName("Mr", "Bean"));
	Facebook.getUserBasedOnName("David", "Wong")->addFriend(Facebook.getUserBasedOnName("Jackie", "Chan"));
	Facebook.getUserBasedOnName("David", "Wong")->addFriend(Facebook.getUserBasedOnName("Brandon", "Davis"));

	Facebook.getUserBasedOnName("Benjamin", "Davis")->addFriend(Facebook.getUserBasedOnName("Brandon", "Davis"));

	system("pause");

	// ========== PART 8: Querying Facebook with the project requirements ========== //
	// *~*~* Finding a user's friends *~*~* //
	cout << endl << "Finding a user's friends..." << endl;

	cout << endl << "John's connections:" << endl;
	for (int i = 0; i < Facebook.getUserBasedOnName("John", "Henderson")->getFriends().size(); i++)
		cout << "\t" << Facebook.getUserBasedOnName("John", "Henderson")->getFriends().at(i)->getFirstName() << " " 
		<< Facebook.getUserBasedOnName("John", "Henderson")->getFriends().at(i)->getLastName() << endl;
	cout << endl;

	cout << endl << "David's connections:" << endl;
	for (int i = 0; i < Facebook.getUserBasedOnName("David", "Wong")->getFriends().size(); i++)
		cout << "\t" << Facebook.getUserBasedOnName("David", "Wong")->getFriends().at(i)->getFirstName() << " " 
		<< Facebook.getUserBasedOnName("David", "Wong")->getFriends().at(i)->getLastName() << endl;
	cout << endl;

	system("pause");

	// *~*~* Finding mutual friends *~*~* //
	cout << endl << "Finding mutual friends between John and David..." << endl;

	vector<User*> common_friends = Facebook.findSimilarFriends(Facebook.getUserBasedOnName("John", "Henderson"), Facebook.getUserBasedOnName("David", "Wong"));
	for (int i = 0; i < common_friends.size(); i++)
		cout << "\t" << common_friends.at(i)->getFirstName() << " " << common_friends.at(i)->getLastName() << endl;
	cout << endl;

	system("pause");

	// *~*~* Finding the shortest path of friends between two users *~*~* //
	cout << endl << "Finding the shortest path of friends between Benjamin and David: ";
	int answer = Facebook.findSmallestConnections(Facebook.getUserBasedOnName("Benjamin", "Davis"),Facebook.getUserBasedOnName("David", "Wong"));
	if(answer!=-1)
		cout<<answer<<endl;
	else
		cout<<"There is no path between Benjamin and David"<<endl;

	cout << endl << "Finding the shortest path of friends between John and Lonely Man: ";
	answer = Facebook.findSmallestConnections(Facebook.getUserBasedOnName("John", "Henderson"),Facebook.getUserBasedOnName("Lonely", "Man"));
	if(answer!=-1)
		cout<<answer<<endl;
	else
		cout<<"There is no path between John and Lonely Man!"<<endl;

	system("pause");

	// ========== PART 9: Querying Facebook for other statistics ========== //
	cout << endl << "Extra queries..." << endl << endl;

	cout << "Percentage of males in Social Network: " << Facebook.getPercentageMale() << endl;
	cout << "Percentage of females in Social Network: " << Facebook.getPercentageFemale() << endl;
	cout << "Percentage of users between 18-24 years old in Social Network: " << Facebook.getPercentageAge(24,18) << endl << endl;

	cout << "Percentage of males in Christmas Party!: " << Facebook.getEvent("Christmas Party!")->getPercentageMale() << endl;
	cout << "Percentage of females in Christmas Party!: " << Facebook.getEvent("Christmas Party!")->getPercentageFemale() << endl;
	cout << "Percentage of users between 18-24 years old in Christmas Party!: " << Facebook.getEvent("Christmas Party!")->getPercentageAge(24,18) << endl << endl;

	cout << "Percentage of males in Davis Family & Friend Christmas Potluck: " << Facebook.getEvent("Davis Family & Friend Christmas Potluck")->getPercentageMale() << endl;
	cout << "Percentage of females in Davis Family & Friend Christmas Potluck: " << Facebook.getEvent("Davis Family & Friend Christmas Potluck")->getPercentageFemale() << endl;
	cout << "Percentage of users between 18-24 years old in Davis Family & Friend Christmas Potluck: " << Facebook.getEvent("Davis Family & Friend Christmas Potluck")->getPercentageAge(24,18) << endl << endl;

	cout << "CPSC 260 Project Presentation information..." << endl;
	cout << "NAME: " << Facebook.getEvent("CPSC 260 Project Presentation")->getName() << endl;
	cout << "DESCRIPTION: " << Facebook.getEvent("CPSC 260 Project Presentation")->getDescription() << endl;
	cout << "CATEGORY: " << Facebook.getEvent("CPSC 260 Project Presentation")->getCategory() << endl;
	cout << "DATE: " << Facebook.getEvent("CPSC 260 Project Presentation")->getDateString() << endl;
	cout << "BEGINS: " << Facebook.getEvent("CPSC 260 Project Presentation")->getBeginning_Hour() << ":00" << endl;
	cout << "ENDS: " << Facebook.getEvent("CPSC 260 Project Presentation")->getEnding_Hour() << ":00" << endl;
	cout << "PARTICIPANTS: " << endl;
	for (int i = 0; i < Facebook.getEvent("CPSC 260 Project Presentation")->getParticipants().size(); i++)
		cout << "\t" << Facebook.getEvent("CPSC 260 Project Presentation")->getParticipants().at(i)->getFirstName() << " " << Facebook.getEvent("Boxing Day!")->getParticipants().at(i)->getLastName() << endl;
	cout << endl;

	system("pause");

	// ========== PART 10: Deleting users ========== //
	//cout << endl << "Deleting users from Social Network..." << endl;

	//if (Facebook.deleteUser(Facebook.getUserBasedOnName("David", "Wong")))
	//{
	//	cout << "Deleted David. Now checking to see if David is a still exists as John's friend...";
	//	cout << endl << "John's connections:" << endl;
	//	for (int i = 0; i < Facebook.getUserBasedOnName("John", "Henderson")->getFriends().size(); i++)
	//		cout << "\t" << Facebook.getUserBasedOnName("John", "Henderson")->getFriends().at(i)->getFirstName() << " " 
	//		<< Facebook.getUserBasedOnName("John", "Henderson")->getFriends().at(i)->getLastName() << endl;
	//	cout << endl;
	//}
	//else
	//	cout << "David was not deleted!" << endl;

	//system("pause");
	return 0;
}