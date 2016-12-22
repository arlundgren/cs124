/***********************************************************************
* Program:
*    Assignment 43, Command Line
*    Brother Falin, CS124
* Author:
*    Andrew Lundgren
* Summary: 
*    This program takes the parameters given by the user and uses a loop
*    to convert their inputted feet into meters.
*
*    Estimated:  0.1 hrs   
*    Actual:     0.1 hrs
*      There wasn't anything difficult about this assignment.
************************************************************************/

#include <cstdlib>
#include <iostream>
using namespace std;

/**********************************************************************
 * Main takes parameters received from the user at runtime and converts
 * them from feet into meters using a for loop.
 ***********************************************************************/
int main(int argc, char** argv)
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(1);
   
   float num = 1.0;
   for (int iArg = 1; iArg < argc; iArg++)
   {
      num = atof(argv[iArg]);
      cout << num << " feet is "
           << num * 0.3048 << " meters";
      cout << endl;
   }
   return 0;
}
