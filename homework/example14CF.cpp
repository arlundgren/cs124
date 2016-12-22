#include <iostream>
#include <iomanip>
using namespace std;

/*
 * For a given amount of earned income, compute the amount to be saved
 */

int computeSavings(int centsIncome)
{
   //first take care of the tithing
   int centsTithing = centsIncome / 10;
   centsIncome -= centsTithing;

   // next compute the savings
   int centsSavings = centsIncome / 2;
   return centsSavings;
}

/*
 * Prompt the user for his allowance and display the savings component
 */

int main()
{
   // prompt the user for his allowance
   float dollarsAllowance;
   cout << "What is your allowance? ";
   cin >> dollarsAllowance;
   int centsAllowance = (int)dollarsAllowance * 100;

   cout.setf(ios::showpoint);
   cout.setf(ios::fixed);
   cout.precision(2);
   
   //display how much is to be deposited
   int centsDeposit = computeSavings(centsAllowance);
   cout << "You need to deposit $"
        << (float)centsDeposit / 100.0
        << endl;
   return 0;
}
