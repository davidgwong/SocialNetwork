// File:     Date.hpp
//
// Author:   John Henderson
// SID:      28132108
// Modified: 2013 November 25
//
// This file declares the Date class for the Date class

#ifndef _DATE_HPP_
#define _DATE_HPP_

#include <string>

using namespace std;

class Date {

  public:

	// ***** CONSTRUCTORS & DESTRUCTORS ***** //

	/********************
 * Description  :   Default constructor to make a new Date object.
 *
 * Input        :   None
 *
 * Output       :   New Date object
 ********************/
    Date();

    /********************
	* Description  :   Parametrized constructor to make a new Date object.
	*
	* Input        :   int year. int month, int day
	*
	* Output       :   New Date object
	********************/
	Date( int year, int month, int day);
	
	/********************
	* Description  :   Parametrized constructor to make a new Date object. Takes month as input string
	*
	* Input        :   int year, string month, int day
	*
	* Output       :   New Date object
	********************/
	Date( int year, string month, int day);

	/********************
	* Description  :   Destructor
	*
	* Input        :   None
	*
	* Output       :   None
	********************/
	~Date();

	// ***** ACCESSORS ***** //

	/********************
	 * Description  :	Accessor
	 *
	 * Input        :	None
	 *
	 * Output       :   int: month of date
	 ********************/
    int getMonth();

	/********************
	 * Description  :	Accessor
	 *
	 * Input        :	None
	 *
	 * Output       :   int: day of date
	 ********************/
	int getDay();

	/********************
	 * Description  :	Accessor
	 *
	 * Input        :	None
	 *
	 * Output       :   int: year of date
	 ********************/
	int getYear();

	/********************
	 * Description  :	Accessor
	 *
	 * Input        :	None
	 *
	 * Output       :   string: the date in a human readable format
	 ********************/
	string toString();

	// ***** MUTATORS ***** //

	/********************
	 * Description  :	Mutator
	 *
	 * Input        :   int month
	 *
	 * Output       :   None
	 ********************/
    void setMonth(int month);
    
	/********************
	 * Description  :	Mutator
	 *
	 * Input        :   int day
	 *
	 * Output       :   None
	 ********************/
	void setDay(int day );

	/********************
	 * Description  :	Mutator
	 *
	 * Input        :   int year
	 *
	 * Output       :   None
	 ********************/
	void setYear(int year );

	/********************
	 * Description  :	Mutator
	 *
	 * Input        :   int year, int month, int day
	 *
	 * Output       :   bool: true if setDate is successful
	 ********************/
	bool setDate( int year, int month, int day);
	
	/********************
	 * Description  :	Mutator
	 *
	 * Input        :   int year, string month, int day
	 *
	 * Output       :   bool: true if setDate is successful
	 ********************/
	bool setDate( int year, string month, int day);

  private:

    // ***** HELPER METHODS ***** //
	
    int monthStr2Num(string month);
    // Converts from string notation to integer notation for month
    // POST: The function returns the integer month equivalent

    static string intToString (int i);
    // Converts an integer to a string
    // POST: i is returned as string

	bool CheckforNeg(int year, int month, int day);
	// Checks to see if any values are negative
	// POST: prints related error message

	bool CheckforRealDate(int year, int month, int day);
	// Checks to see if the date is real. i.e. that the date actually exists on a calendar
	// POST: prints related error message

	bool CheckforLeapYear(int year);
	// Checks to see if the year is a leap year
	// POSTS: returns true if it is a leap year

    //Member Variables
	int year_;
	int month_;
	int day_;

};

#endif
