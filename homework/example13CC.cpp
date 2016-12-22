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
using namespace std;

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   
   // prompt the user
   cout << "Please enter a positve dollar amount (ex: 4.23): ";
   float dollars;
   cin >> dollars;

   // convert to cents
   int cents = (int)(dollars * 100);

   // Dollars
   cout << "Dollars:  " << cents / 100 << endl;
   cents %= 100;

   // Quarters
   cout << "Quarters:  " << cents / 25  << endl;
   cents %= 25;

   // Dimes
   cout << "Dimes:  " << cents / 10 << endl;
   cents %= 10;
   cout << 23 % 25 << endl;
   
   /* Nickels
   cout << "Nickels:  " << cents /5 << endl;
   cents %= 5;

   // Pennies
   cout << "Pennies:  " << cents << endl;
   */
   
   return 0;
}
