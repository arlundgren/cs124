/***********************************************************************
* Program:
*    Assignment 23, Loop Syntax
*    Brother Falin, CS124
* Author:
*    Andrew Lundgren
* Summary: 
*    This program will prompt the user for a number to multiply by
*    in order to determine the total of the number's multiples
*    less than 100.
*
*    Estimated:  1.0 hrs   
*    Actual:     0.6 hrs
*      The most difficult part was determining how to tell program to
*      do the math I wanted it to do, and which kind of loop to use.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Main will prompt the user for a number to multiply by, and then
 * it will use a loop to determine the total of the multiples that fit
 * into 100.
 ***********************************************************************/
int main()
{
   //Prompt what we are counting by
   cout << "What multiples are we adding? ";
   int multiple;
   cin >> multiple;

   // Create necessary variables
   int factor = 1;
   int total = 0;

   // Use a for loop in order to create a total
   for (int factor = 0; (multiple * factor) < 100; factor++)
   {
      total += (multiple * factor);
   }

   // Print the total
   cout << "The sum of multiples of " << multiple
        << " less than 100 are: " << total << endl;
   
   return 0;
}
