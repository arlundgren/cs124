/***********************************************************************
* Program:
*    Assignment 12, Input and Variables
*    Brother Falin, CS124
* Author:
*    Andrew Lundgren
* Summary: 
*    This program will prompt the user for his income, and afterwards
*    will display the said income.
*    Estimated:  0.75 hrs   
*    Actual:     0.15 hrs
*      The hardest part was when I made a mistake of sending cin to
*      float, and not income.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * This function asks the user for his income, after which it tells the
 * user what their previously stated income is.
 ***********************************************************************/
int main()
{
   float income;

   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   // Prompt the user for their income
   cout << "\tYour monthly income: ";
   cin >> income;

   // Report to the user what their income is
   cout << "Your income is: $" << setw(9) << income;
   cout << endl;
   
   return 0;
}
