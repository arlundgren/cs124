/***********************************************************************
* Program:
*    Assignment 11, Monthly Budget
*    Brother Falin, CS124
* Author:
*    Andrew Lundgren
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
using namespace std;

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   // Configuration of numbers to display money
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   // Display the columns of numbers
   cout << "$"
        << setw(7)
        << 124.45;
   cout << "\t";
   cout << "$"
        << setw(7)
        << 321.31;
   cout << endl;

   cout << "$"
        << setw(7)
        << 1.74;
   cout << "\t";
   cout << "$"
        << setw(7)
        << 4.21;
   cout << endl;

   cout << "$"
        << setw(7)
        << 7439.123;
   cout << "\t"
        << "$"
        << setw(7)
        << 54.92;
   cout << endl;
   
   return 0;
}
