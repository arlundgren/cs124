/***********************************************************************
* Program:
*    Assignment 30, Array Syntax
*    Brother Falin, CS124
* Author:
*    Andrew Lundgren
* Summary: 
*    This program takes a list of ten user-inputted grades and passes
*    them as an array to a function to determine the average grade.
*
*    Estimated:  1.0 hrs   
*    Actual:     0.5 hrs
*      The hardest part was that I was using the wrong loop requirements.
************************************************************************/

#include <iostream>
using namespace std;

int getGrades(int listGrades[], int numGrades);
int averageGrades(int listGrades[], int numGrades);

/**********************************************************************
 * Main declares an array and uses that array, along with the number
 * of grades required, to run two functions to determine the average
 * in the array. It then displays to the user what the average is.
 ***********************************************************************/
int main()
{
   cout.precision(0);
   int listGrades[10] = {};
   int numGrades = 10;
   
   int itemsInList = getGrades(listGrades, numGrades);
   
   int average = averageGrades(listGrades, itemsInList);

   if (average >= 0)
      cout << "Average Grade: " << average << "%" << endl;
   else
      cout << "Average Grade: ---%" << endl;

   return 0;
}

/*******************************************************************
 * getGrades() uses a loop to receive user input and store it in the
 * previously declared array.
 *******************************************************************/
int getGrades(int listGrades[], int numGrades)
{
   int itemsInList = 0;
   for (int i = 0; i < numGrades; i++)
   {
      cout << "Grade " << i + 1 << ": ";
      cin >> listGrades[i];
      if (listGrades[i] > -1)
         itemsInList++;
   }
   return itemsInList;
}

/******************************************************************
 * averageGrades() extracts the information from the array and
 * returns the average of all the numbers in the array.
 ******************************************************************/
int averageGrades(int listGrades[], int numGrades)
{
   int sumGrades = 0;
   
   for (int i = 0; i < numGrades; i++)
   {
      if (listGrades[i] > -1)
         sumGrades += listGrades[i];
   }
   return sumGrades / numGrades;
}
