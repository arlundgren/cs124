/***********************************************************************
* Program:
*    Assignment 13, Temperature Conversion
*    Brother Falin, CS124
* Author:
*    Andrew Lundgren
* Summary: 
*    This program is going to convert Fahrenheit to Celsius. I don't
*    think it should take too long.
*    
*    
*    
*
*    Estimated:  0.45 hrs   
*    Actual:     1.0 hrs
*      The hardest part was realizing that I accidentally had told the
*      console to always showpoint, so it ruined all my tests. I also
*      didn't have everything set as a float value, although I was
*      still casting as a float in my equation, and the numbers were all
*      in float format.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * This function will convert the number a user inputs from Fahrenheit
 * degrees to Celsius.
 ***********************************************************************/
int main()
{
   cout.setf(ios::fixed);
   cout.precision(0);

   // Variables for Fahrenheit and Celsius
   float fahr;
   
   // User input
   cout << "Please enter Fahrenheit degrees: ";
   cin >> fahr;
   float cel = 5.0 / 9.0 * ( (float) fahr - 32.0 );
   
   // Result
   cout << "Celsius: " << cel << endl;
   
   return 0;
}
