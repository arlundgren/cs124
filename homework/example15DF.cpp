#include <iostream>
using namespace std;

double getIncome();
int getNumChildren();
bool qualify(double);

/*
 * Does the user qualify for the tax credit?
 * This will return a BOOL because either you
 * Qualify or you don't!
 */

int main()
{
   // get the income
   double income = getIncome();

   // get the number of children
   int numChildren = getNumChildren();

   // display the message
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   cout << "Child tax credit: $";
   if (qualify(income))
      cout << 1000.00 * (float)numChildren << endl;
   else
      cout << 0.00 << endl;

   return 0;
}

/*
 * Get Income
 *   Get the user's income. Note that we need to use a
 *   double here because the float only has 7 digits
 *   of accuracy.
 */
double getIncome()
{
   // prompt
   cout << "What is your income: ";

   // get the value
   double income;
   cin >> income;
   return income;
}

/*
 * Get NUM CHULD
 * must be an int, no one has 3.1 children
 */
int getNumChildren()
{
   // prompt
   cout << "How many children? ";

   // get the value
   int num;
   cin >> num;
   return num;
}

/*
 * Qualify
 */
bool qualify(double income)
{
   return (income <= 110000.00);
}
