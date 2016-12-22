/***********************************************************************
* Program:
*    Project 03, Monthly Budget
*    Brother Falin, CS124
* Author:
*    Andrew Lundgren
* Summary: 
*    This is the second part of my monthly budget project!
*    I think that it will take me a little over an hour.
*    Estimated:  1.3 hrs   
*    Actual:     1.3 hrs
*      The hardest part was that I had an error where I had too many
*      arguments in my displayAnswers function. I didn't know that the
*      problem was that I didn't set parameters in my prototype function
*      of displayAnswers. That took about 25 minutes to figure out.
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
void displayAnswers(float income, float budgetLiving, float actualTax,
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
 * that the user paid so that it can be stored in the
 * budgetTax variable in DISPLAY. For now, it won't do
 * that, since we haven't learned about it yet.
 **********************************************************/
float computeTax(float income)
{
   float taxes = (income * 0.0);
   return taxes;
}

/**********************************************************
 * This function, computeTithing, will calculate how much
 * tithing that the user ought to be paying, and send that
 * value to the budgetTithing in DISPLAY.
 **********************************************************/
float computeTithing(float income)
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
void displayAnswers(float income, float budgetLiving, float actualTax,
               float actualTithing, float actualLiving,
               float actualOther)
{
   // Make variables for the information from MAIN
   float budgetTax = computeTax(income);
   float budgetTithing = computeTithing(income);
   float budgetOther = (income - budgetTax - budgetTithing -
                        budgetLiving);
   float actualDifference = (income - actualTax - actualTithing -
                             actualLiving - actualOther);
   float budgetDifference = 0.;

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
