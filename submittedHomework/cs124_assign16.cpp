/***********************************************************************
* Program:
*    Assignment 16, Compute Tax
*    Brother Falin, CS124
* Author:
*    Andrew Lundgren
* Summary: 
*    This program will determine what the user's tax bracket is depending
*    on what their income is. It first collects their income and stores it
*    as a double variable. It then will print what the tax bracket is, and
*    before it tells the user what their bracket is, it will call the
*    computeTax function in order to determine their bracket. computeTax
*    will then send its result back to MAIN, and the MAIN will finish.
*    Estimated:  0.5 hrs   
*    Actual:     0.16 hrs
*      There wasn't a part of this assignment that was difficult.
************************************************************************/

#include <iostream>
using namespace std;

double computeTax(double income);

/***********************************************************************
 * MAIN will first create a variable, INCOME, and will then store what
 * the user inputs as the INCOME variable. It will then begin to tell
 * the user what bracket they fit in for taxes, and call for the
 * computeTax function to run. It will then print the result and finish
 * by printing a % symbol and ending the line.
 ***********************************************************************/
int main()
{
   double income;

   cout << "Income: ";
   cin >> income;
   cout << "Your tax bracket is " << computeTax(income) << "%\n";
   return 0;
}

/**********************************************************************
 * The computeTax function will receive a variable from MAIN and name
 * it INCOME. computeTax() will then run a series of boolean tests on
 * the INCOME variable. The value of INCOME will then be stored as
 * BRACKET. BRACKET will be returned to MAIN at the end of the
 * function.
 **********************************************************************/
double computeTax(double income)
{
   int bracket;

   {
      if (0 <= income && income < 15100.00)
         bracket = 10;
      else if (15100.00 <= income && income < 61300.00)
         bracket = 15;
      else if (61300.00 <= income && income < 123700.00)
         bracket = 25;
      else if (123700 <= income && income < 188450.00)
         bracket = 28;
      else if (188450.00 <= income && income < 336550.00)
         bracket = 33;
      else
         bracket = 35;
   }
   return bracket;
}
