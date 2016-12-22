/***********************************************************************
* Program:
*    Assignment 33
*    Brother Falin, CS124
* Author:
*    Andrew Lundgren
* Summary: 
*    This program uses pointers to determine who shold pay for a date.
*
*    Estimated:  0.15 hrs   
*    Actual:     0.15 hrs
*      Nothing was hard!
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Gets Sam's account balance
 ***********************************************************************/
float getSamBalance()
{
   cout << "What is Sam's balance? ";
   float balance = 0.00;
   cin >> balance;
   return balance;
}

/***********************************************************************
 * Get Sue's account balance! 
 **********************************************************************/
float getSueBalance()
{
   cout << "What is Sue's balance? ";
   float balance = 0.00;
   cin >> balance;
   return balance;
}

/******************************************************
 * Determine cost of date.
 *****************************************************/
float getCost()
{
   float dinner;
   float movie;
   float iceCream;
   
   cout << "Cost of the date:\n";
   cout << "\tDinner:    ";
   cin >> dinner;
   cout << "\tMovie:     ";
   cin >> movie;
   cout << "\tIce cream: ";
   cin >> iceCream;

   return dinner + movie + iceCream;
}

/**************************************************
 * Determine who should pay for the date!
 **************************************************/
int main()
{
   cout.setf(ios::fixed);
   cout.precision(2);
   cout.setf(ios::showpoint);
   
   float sam = getSamBalance();
   float sue = getSueBalance();
   float cost = getCost();

   float* richAccount;
   
   if (sam > sue)
      richAccount = &sam;
   else
      richAccount = &sue;

   *richAccount -= cost;

   cout << "Sam's balance: $" << sam << endl;
   cout << "Sue's balance: $" << sue << endl;
   
   return 0;
}
