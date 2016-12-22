/****************************************************************************
* Program:
*    Assignment 25, Loop Design
*    Brother Falin, CS124
* Author:
*    Andrew Lundgren
* Summary:
*    This program takes input from the user and creates a calendar
*    based on that input.
*
*    Estimated:  2.0 hrs
*    Actual:     2.5 hrs
*      The hardest part was setting my loops with the correct parameters.
*****************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

void displayTable(int numDays, int offset);

/***********************************************************************
 * Main collects information from the user and calls displayTable().
 ***********************************************************************/
int main()
{
   int offset = 0;
   int numDays = 0;
   
   cout << "Number of days: ";
   cin >> numDays;
   cout << "Offset: ";
   cin >> offset;
   
   displayTable(numDays, offset);

   return 0;
}

/*********************************************************************
 * This function runs a series of loops to using the offset and numDays
 * received from Main to create a nice looking calendar.
 *********************************************************************/
void displayTable(int numDays, int offset)
{
   int dayCounter = 1;
   int width = offset + 2;
   if (offset == 6)
   {
      width = 1;
   }
   
   cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";
   
   for (int day = 1; width <= 7; day++)
   {
      if (width == day)
      {
         cout << setw(4);
         cout << dayCounter;
         dayCounter += 1;
         width += 1;
         numDays -= 1;
      }
      else
         cout << setw(4) << " ";
   }
   
   cout << endl;

   while (numDays > 0)
   {
      for (int day = 1; day <= 7; day++)
      {
         if (numDays > 0)
         {
            numDays--;
            cout << setw(4) << dayCounter;
            dayCounter++;
         }
      }
      cout << endl;
   }
}
