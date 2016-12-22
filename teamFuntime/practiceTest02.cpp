/***********************************************************************
* Program:
*    Assignment ##, ????          (e.g. Assignment 10, Hello World)
*    Brother {Cook, Comeau, Falin, Lilya, Honeycutt, Unsicker, Peterson, Phair, Ellsworth}, CS124
* Author:
*    your name
* Summary: 
*    Enter a brief description of your program here!  Please note that if
*    you do not take the time to fill out this block, YOU WILL LOSE POINTS.
*    Before you begin working, estimate the time you think it will
*    take you to do the assignment and include it in this header block.
*    Before you submit the assignment include the actual time it took.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

float getCostPerCup();
float getRevenuePerCup();
int getTotalCups();
void displayResults(int cupsSold, float cost, float revenue);

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   cout << "Lemonade Profit Calculator\n" << endl;
   float cost = getCostPerCup();
   float revenue = getRevenuePerCup();
   float cupsSold = getTotalCups();

   displayResults(cupsSold, cost, revenue);
   return 0;
}

float getCostPerCup()
{
   cout << "\tEnter the cost per cup: ";
   float cost;
   cin >> cost;
   return cost;
}

float getRevenuePerCup()
{
   cout << "\tEnter the revenue per cup: ";
   float revenue;
   cin >> revenue;

   cout << endl;
   return revenue;
}

int getTotalCups()
{
   int dailyCups = 0;
   int cupsSold = 0;
   int day = 1;
   do
   {
      
      cout << "\tEnter the cups sold on day " << day << ": ";
      cin >> dailyCups;
      if (dailyCups != -1)
         cupsSold += dailyCups;
      day++;
   }
   while (dailyCups != -1);

   cout << endl;
   return cupsSold;
}
      
void displayResults(int cupsSold, float cost, float revenue)
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   
   cout << "\tTotal cups sold: " << cupsSold << endl << endl;

   cout << "\t" << setw(14) << left << "Total Revenue:"
        << setw(12) << right << (revenue * cupsSold) << endl;
   cout << "\t" << setw(14) << left << "Total Cost:"
        << setw(12) << right << cost * cupsSold << endl;
   cout << "\t==========================\n";
   cout << "\t" << setw(14) << left << "Total Profit:"
        << setw(12) << right << (revenue * cupsSold) -
      (cost * cupsSold) << endl;
}
