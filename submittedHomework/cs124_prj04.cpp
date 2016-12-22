/***********************************************************************
* Program:
*    Project 04, Monthly Budget
*    Brother Falin, CS124
* Author:
*    Andrew Lundgren
* Summary: 
*    This is the last part of my monthly budget project!
*    I think that it will take me a little over an hour.
*    Estimated:  1.0 hrs   
*    Actual:     0.5 hrs
*      This step wasn't actually that hard! I understood it fine.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * These are my prototype functions for the program!
 ***********************************************************************/
float getIncome();
float getBudgetLiving();
float getActualLiving();
float getActualTax();
float getActualTithing();
float getActualOther();
void displayAnswers(double income, float budgetLiving, float actualTax,
                    float actualTithing, float actualLiving,
                    float actualOther);

/******************************************************************
 * The MAIN function will tell the user what the purpose of the
 * program is, and then gather the necessary data for DISPLAY
 * by calling various functions and storing what they return as
 * variables. It will then call the DISPLAY function to display
 * those results.
 ******************************************************************/
int main()
{
   // Greet the user
   cout << "This program keeps track of your monthly budget\n";
   cout << "Please enter the following:\n";
   
   // Call functions for the needed variables
   float income = getIncome();
   float budgetLiving = getBudgetLiving();
   float actualLiving = getActualLiving();
   float actualTax = getActualTax();
   float actualTithing = getActualTithing();
   float actualOther = getActualOther();

   // Display the results
   displayAnswers(income, budgetLiving, actualTax, actualTithing,
           actualLiving, actualOther);
   return 0;
}

/****************************************
 * This gets income and sends it to main.
 ****************************************/
float getIncome()
{
   float mIncome;
   // Prompt for income
   cout << "\tYour monthly income: ";
   cin >> mIncome;
   return mIncome;
}

/****************************************
 * This sends the user's budget to main.
 ****************************************/
float getBudgetLiving()
{
   float budgetLiveExp;
   // Get the budgeted living expenses
   cout << "\tYour budgeted living expenses: ";
   cin >> budgetLiveExp;
   return budgetLiveExp;
}

/************************************************
 * This sends the user's actual expenses to MAIN
 ************************************************/
float getActualLiving()
{
   float actualLiveXP;
   // Get the information from the user
   cout << "\tYour actual living expenses: ";
   cin >> actualLiveXP;
   return actualLiveXP;
}

/***********************************************
 * This sends the tax information to MAIN
 ***********************************************/
float getActualTax()
{
   float actualTaxes;
   // Actual Taxes
   cout << "\tYour actual taxes withheld: ";
   cin >> actualTaxes;
   return actualTaxes;
}

/***********************************************
 * The user input is sent back to actualTithing
 ***********************************************/
float getActualTithing()
{
   float actualTithe;
   // Actual Tithe
   cout << "\tYour actual tithe offerings: ";
   cin >> actualTithe;
   return actualTithe;
}

/**********************************************************
 * This will send the user's actual other expenses to MAIN
 **********************************************************/
float getActualOther()
{
   float actualOther;
   // Actual Other
   cout << "\tYour actual other expenses: ";
   cin >> actualOther;
   return actualOther;
}

/**********************************************************
 * This function, computeTax, will calculate the taxes
 * that the user should pay, according to their income.
 * This value, monthlyTax, will be sent to DISPLAY.
 **********************************************************/
double computeTax(double income)
{
   double annualIncome = income * 12.0;
   double annualTax;
   float zero = 0.0;

   if (zero <= annualIncome && annualIncome < 15100.00)
      annualTax = (annualIncome * .10);
   
   if (15100.00 <= annualIncome && annualIncome < 61300.00)
      annualTax = (1510.00 + (.15 * (annualIncome - 15100.00)));
   
   if (61300.00 <= annualIncome && annualIncome < 123700.00)
      annualTax = (8440.00 + (.25 * (annualIncome - 61300.00)));
   
   if (123700.00 <= annualIncome && annualIncome < 188450.00)
      annualTax = (24040.00 + (.28 * (annualIncome - 123700.00)));
   
   if (188450.00 <= annualIncome && annualIncome < 336550.00)
      annualTax = (42170.00 + (.33 * (annualIncome - 188450.00)));
   
   if (336550.00 <= annualIncome)
      annualTax = (91043.00 + (.35 * (annualIncome - 336550.00)));

   double monthlyTax = (annualTax / 12.00);
   return monthlyTax;
}

/**********************************************************
 * This function, computeTithing, will calculate how much
 * tithing that the user ought to be paying, and send that
 * value to the budgetTithing in DISPLAY.
 **********************************************************/
double computeTithing(double income)
{
   // Take the income value sent from DISPLAY and
   // calculate how much tithing ought to be paid
   float fullTithe = (income * .1);
   return fullTithe;
}

/**********************************************************
 * DISPLAY receives the variables from MAIN and then runs
 * calculations to determine the taxes and tithing, and
 * stores the information from MAIN into new variables
 **********************************************************/
void displayAnswers(double income, float budgetLiving, float actualTax,
               float actualTithing, float actualLiving,
               float actualOther)
{
   // Make variables for the information from MAIN
   double budgetTax = computeTax(income);
   double budgetTithing = computeTithing(income);
   double budgetOther = (income - budgetTax - budgetTithing -
                        budgetLiving);
   double actualDifference = (income - actualTax - actualTithing -
                             actualLiving - actualOther);
   double budgetDifference = 0.;

   cout.setf(ios::showpoint);
   cout.setf(ios::fixed);
   cout.precision(2);
   
   /*Output*/
   // Start the chart!
   cout << "\n";
   cout << "The following is a report on your monthly expenses\n";
   cout << "\tItem" << setw(24) << right << "Budget"
        << setw(17) << right << "Actual\n";
   cout << "\t=============== =============== ===============\n";

   // Income line
   cout << "\tIncome" << setw(11) << right << "$" << setw(11) << right
        << income << setw(5) << "$" << setw(11) << right << income
        << endl;

   // Taxes line
   cout << "\tTaxes" << setw(12) << right << "$" << setw(11) << right
        << budgetTax << setw(5) << "$" << setw(11) << right << actualTax
        << endl;

   // Tithing line
   cout << "\tTithing" << setw(10) << right << "$" << setw(11) << right
        << budgetTithing << setw(5) << "$" << setw(11) << right
        << actualTithing << endl;

   // Living line
   cout << "\tLiving" << setw(11) << right << "$" << setw(11) << right
        << budgetLiving << setw(5) << "$" << setw(11) << right << actualLiving
        << endl;

   // Other line
   cout << "\tOther" << setw(12) << right << "$" << setw(11) << right
        << budgetOther << setw(5) << "$" << setw(11) << right << actualOther
        << endl;

   // Separation and Difference
   cout << "\t=============== =============== ===============\n";

   cout << "\tDifference" << setw(7) << right << "$" << setw(11) << right
        << budgetDifference << setw(5) << "$" << setw(11)
        << right << actualDifference
        << endl;
   return;
}
