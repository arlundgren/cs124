/***********************************************************************
* Program:
*    Assignment ##, ????          (e.g. Assignment 10, Hello World)
*    Brother {Cook, Comeau, Falin, Lilya, Honeycutt, Unsicker, Peterson, Phair, Ellsworth}, CS124
* Author:
*    your name
* Summary: 
*    Enter a brief description of your program here!  Please note that if
*    you do not take the time to fill out this block, YOU WILL LOSE POINTS.
*    Before you begin working, estimate the time you think it will
*    take you to do the assignment and include it in this header block.
*    Before you submit the assignment include the actual time it took.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
void displayTable(int numDays, int offset);

int main()
{
   int numDays;
   int offset;
   
   cout << "Number of days: ";
   cin >> numDays;
   cout << "Offset: ";
   cin >> offset;
   
   displayTable(numDays, offset);
   
   return 0;
}

void displayTable(int numDays, int offset)
{
   // Make a standard for the first setw()
   if (offset <= 5)
      width = (offset + 1);
   else if (offset > 5)
      width = 7;
   int startNum = 
   
   // Create a loop to produce the first week
   for (int i = width; i >= 1; i--)
   {
      if (width = 7)
         for (i; i >= 1; i--)
         {
            cout << setw(width * 4) << i;
         }
      else}
   for (int i = 1; i < width; i++)
   {
      cout << setw(i * 4)
