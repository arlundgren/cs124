/***********************************************************************
* Program:
*    Test 2, Girl Scout Cookies
*    Brother Falin, CS124
* Author:
*    Andrew Lundgren
* Summary: 
*    This project is a program that receives input from the user,
*    multiplying the number the user inputs by 3.75 to determine how
*    much money they should collect for the amount of boxes of Girl
*    Cookies they sold. It does this using a loop that asks for the
*    amount of boxes until the user inputs 0, and adding the number
*    of boxes times 3.75. It then returns the total and displays it.
*
*    Estimated:  1.0 hrs   
*    Actual:     0.5 hrs
*      The hardest part was that I wrote the whole computer, and then
*      PuTTY crashed without auto-saving, so I had to re-write the code.
************************************************************************/

#include <iostream>
using namespace std;

float getTotalAmount();
void display(float totalAmount);

/**********************************************************************
 * The main function calls getTotalAmount() and saves what it returns
 * as totalAmount. It then calls display() with totalAmount as the
 * parameter.
 ***********************************************************************/
int main()
{
   float totalAmount = getTotalAmount();
   
   display(totalAmount);
   
   return 0;
}

/********************************************************************
 * getTotalAmount() creates a variable to act as a running total
 * for the amount of money that should be collected. A do while loop
 * prompts the user for input, and then stores that value multiplied
 * by 3.75 to the running total, as long as the user does not input
 * 0. Once the user inputs 0, the loop ends and getTotalAmount()
 * returns the totalAmount.
 ********************************************************************/
float getTotalAmount()
{
   float totalAmount = 0.0;
   int userInput = 1;

   do
   {
      cout << "Number of boxes sold: ";
      cin >> userInput;
      if (userInput != 0)
         totalAmount += (userInput * 3.75);
   }
   while (userInput != 0);

   return totalAmount;
}

/******************************************************************
 * display() simply makes sure the console will print the total
 * in standard notation with two decimal places and prints the
 * total amount of money that should be collected.
 ******************************************************************/
void display(float totalAmount)
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   
   cout << "Total amount: $" << totalAmount << endl;
}
