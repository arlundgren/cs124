/***********************************************************************
* Program:
*    Project 02, Monthly Budget
*    Brother Falin, CS124
* Author:
*    Andrew Lundgren
* Summary: 
*    This is the beginning of my monthly budget project!
*    I think that it will take me a little over an hour.
*    Estimated:  1.3 hrs   
*    Actual:     0.75 hrs
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
   // Needed variables
   float mIncome;
   float budgetLiveXP;
   float actualLiveXP;
   float actualTaxes;
   float actualTithe;
   float actualOther;

   // Fix number parameters
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   // Introduction
   cout << "This program keeps track of your monthly budget\n";
   cout << "Please enter the following:\n";

   // Monthly Income
   cout << "\tYour monthly income: ";
   cin >> mIncome;

   // Budgeted Living
   cout << "\tYour budgeted living expenses: ";
   cin >> budgetLiveXP;

   // Actual Living
   cout << "\tYour actual living expenses: ";
   cin >> actualLiveXP;

   // Actual Taxes
   cout << "\tYour actual taxes withheld: ";
   cin >> actualTaxes;

   // Actual Tithe
   cout << "\tYour actual tithe offerings: ";
   cin >> actualTithe;

   // Actual Other
   cout << "\tYour actual other expenses: ";
   cin >> actualOther;
   cout << endl;
   
   /*Output*/

   cout << "The following is a report on your monthly expenses\n";
   cout << "\tItem" << setw(24) << right << "Budget"
        << setw(17) << right << "Actual\n";
   cout << "\t=============== =============== ===============\n";

   // Income line
   cout << "\tIncome" << setw(11) << right << "$" << setw(11) << right
        << mIncome << setw(5) << "$" << setw(11) << right << mIncome
        << endl;

   // Taxes line
   cout << "\tTaxes" << setw(12) << right << "$" << setw(11) << right
        << 0. << setw(5) << "$" << setw(11) << right << actualTaxes
        << endl;

   // Tithing line
   cout << "\tTithing" << setw(10) << right << "$" << setw(11) << right
        << 0. << setw(5) << "$" << setw(11) << right << actualTithe
        << endl;

   // Living line
   cout << "\tLiving" << setw(11) << right << "$" << setw(11) << right
        << budgetLiveXP << setw(5) << "$" << setw(11) << right << actualLiveXP
        << endl;

   // Other line
   cout << "\tOther" << setw(12) << right << "$" << setw(11) << right
        << 0. << setw(5) << "$" << setw(11) << right << actualOther
        << endl;

   // Separation and Difference
   cout << "\t=============== =============== ===============\n";

   cout << "\tDifference" << setw(7) << right << "$" << setw(11) << right
        << 0. << setw(5) << "$" << setw(11) << right << 0.
        << endl;
   return 0;
}
