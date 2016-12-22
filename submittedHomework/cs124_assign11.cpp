/***********************************************************************
* Program:
*    Assignment 11, Monthly Budget
*    Brother Falin, CS124
* Author:
*    Andrew Lundgren
* Summary: 
*    This program was created to display my hypothetical monthly budget!
*    I think this will take me about an hour.   
*   
*   
*   
*
*    Estimated:  1.0 hrs   
*    Actual:     0.45 hrs
*      I think that the hardest part was lining the spaces up.  
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * Upon running the main function, it will display in the terminal what
 * my hypothetical monthly budget is!
 ***********************************************************************/
int main()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   
   cout << "\tItem           Projected\n";
   cout << "\t=============  ==========\n";
   cout << "\tIncome         $"
        << setw(9)
        << 1000.00
        << endl;

   cout << "\tTaxes          $"
        << setw(9)
        << 100.00
        << endl;

   cout << "\tTithing        $"
        << setw(9)
        << 100.00
        << endl;

   cout << "\tLiving         $"
        << setw(9)
        << 650.00
        << endl;

   cout << "\tOther          $"
        << setw(9)
        << 90.00
        << endl;

   cout << "\t=============  ==========\n";
   cout << "\tDelta          $"
        << setw(9)
        << 60.00
        << endl;
        
   
   return 0;
}
