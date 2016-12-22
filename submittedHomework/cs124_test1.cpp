/**************************************************
* Program:
*    Test 1, Video Game Rationing
*    Brother Falin, CS124
* Author:
*    Andrew Lundgren
* Summary: 
*    This program will let Jimmy whether or not he can play
*    video games based on the amount of time he played today
*    and last week.
************************************************************/
#include <iostream>
using namespace std;

int getTodaysHours();
int getLastWeeksHours();
void displayCanPlay();
void displayCannotPlay();
int main();

/***************************************************
 * Main will call getTodaysHours, getLastWeeksHours,
 * and will use the data gathered from them to
 * determine whether to run displayCanPlay or
 * displayCannotPlay, based on the amount of time
 * that Jimmy has played.
 ***************************************************/
int main()
{
   int dayHours;
   int lastWeekHours;
   
   dayHours = getTodaysHours();
   lastWeekHours = getLastWeeksHours();
   
   if (dayHours <= 2 && lastWeekHours <= 8)
      displayCanPlay();
   if (dayHours > 2 || lastWeekHours > 8)
      displayCannotPlay();

   return 0;
}

/****************************************************
 * This function will determine how long Jimmy has
 * played today, and report that amount of time to
 * Main.
 ****************************************************/
int getTodaysHours()
{
   int hours;
   
   cout << "How many hours have you played today: ";
   cin >> hours;
   
   return hours;
}

/****************************************************
 * This function will determine how long Jimmy played
 * last week and report that amount of time to Main.
 ****************************************************/
int getLastWeeksHours()
{
   int hours;
   
   cout << "How many hours did you play last week: ";
   cin >> hours;
   
   return hours;
}

/****************************************************
 * This will display a message that Jimmy can play
 * for an hour.
 ****************************************************/
void displayCanPlay()
{
   cout << "\tYou can play for one hour!\n";
}

/****************************************************
 * This will display a message that Jimmy has played
 * enough for today.
 ****************************************************/
void displayCannotPlay()
{
   cout << "\tYou have played enough today.\n";
}
