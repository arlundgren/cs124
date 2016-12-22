/****************************************************************************
* Program:
*    Project 07, Calendar
*    Brother Falin, CS124
* Author:
*    Andrew Lundgren
* Summary:
*    This program takes input from the user and creates a calendar
*    based on that input.
*
*    Estimated:  2.0 hrs
*    Actual:     4.5 hrs
*      The hardest part of this assignment was definitely calculating the
*      offset correctly and formulating the isLeapYear() function.
*****************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

void displayTable(int numDays, int month, int year,  int offset);
int getMonth();
int getYear();
bool isLeapYear(int year);
int getNumDays(int month, int year);
int calcOffset(int month, int year);

/***********************************************************************
 * Main collects information from the user and calls displayTable().
 ***********************************************************************/
int main()
{
   int month = getMonth();
   int year = getYear();
   int numDays = getNumDays(month, year);
   int offset = calcOffset(month, year);
   cout << endl;
   displayTable(numDays, month, year, offset);
  
   return 0;
}

/*********************************************************************
 * This function runs a loop using information gathered from various
 * functions to create a calendar based on the month and year.
 *********************************************************************/
void displayTable(int numDays, int month, int year, int offset)
{  
   if (month == 1)
      cout << "January, "   << year << endl;
   else if (month == 2)
      cout << "February, "  << year << endl;
   else if (month == 3)
      cout << "March, "     << year << endl;
   else if (month == 4)
      cout << "April, "     << year << endl;
   else if (month == 5)
      cout << "May, "       << year << endl;
   else if (month == 6)
      cout << "June, "      << year << endl;
   else if (month == 7)
      cout << "July, "      << year << endl;
   else if (month == 8)
      cout << "August, "    << year << endl;
   else if (month == 9)
      cout << "September, " << year << endl;
   else if (month == 10)
      cout << "October, "   << year << endl;
   else if (month == 11)
      cout << "November, "  << year << endl;
   else if (month == 12)
      cout << "December, "  << year << endl;
   
   cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";

   if (offset == 6)
      offset = -1;

   int spaces = (offset + 1) % 7;
   cout << setw(spaces * 4) << "";
   
   int currentDay = 0;
   
   for (currentDay = 1; currentDay <= numDays; currentDay++)
   {
      cout << setw(4) << currentDay;

      if (currentDay == numDays ||
          (spaces + currentDay) % 7 == 0)
         cout << endl;
   }
}

/***********************************************************
 * Gets the month from the user, it will only accept values
 * from 1 and 12.
 ***********************************************************/
int getMonth()
{
   int month = 0;

   do
   {
      cout << "Enter a month number: ";
      cin >> month;
      if (month > 12 || month < 1)
         cout << "Month must be between 1 and 12.\n";
   }
   while (month > 12 || month < 1);
   return month;
}

/*************************************************************
 * This gets the year from the user. It must be 1753 or later.
 *************************************************************/
int getYear()
{
   int year = 0;
   do
   {
      cout << "Enter year: ";
      cin >> year;
      if (year < 1753)
         cout << "Year must be 1753 or later.\n";
   }
   while (year < 1753);
   
   return year;
}

/************************************************************
 * This will test to see if the year received is a leap year.
 ************************************************************/
bool isLeapYear(int year)
{
   if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
      return true;
   else
      return false;
}

/**************************************************************
 * This returns the number of days in a month depending on the
 * month as well as if February is in a leap year.
 **************************************************************/
int getNumDays(int month, int year)
{
   if (month == 9 || month == 4 || month == 6
       || month == 11)
      return 30;
   else if (month == 1 || month == 3 || month == 5
            || month == 7 || month == 8 || month == 10
            || month == 12)
      return 31;
   else if (isLeapYear(year) && month == 2)
      return 29;
   else if (month == 2)
      return 28;
}

/*******************************************************
 * This function calculates the offset using two loops
 * and data collected from other functions.
 *******************************************************/
int calcOffset(int month, int year)
{  
   if (year == 1753 && month == 1)
      return 0;
   int monthsTracked = 0;
   int totalDays = 0;

   for (int currentYear = 1753; currentYear < year; currentYear++)
   {
      if (isLeapYear(currentYear))
         totalDays += 366;
      else
         totalDays += 365;
   }

   for (int currentMonth = 1; currentMonth <= month; currentMonth++)
   {
      totalDays += getNumDays(monthsTracked, year);
      monthsTracked++;
   }

   int offset = (totalDays % 7);

   return offset;
}

   
