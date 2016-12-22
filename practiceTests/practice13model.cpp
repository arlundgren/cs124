/***********************************************************************
* Program:
*    Practice 1.3, Simple Greeting
*    Brother Helfrich, CS124
* Author:
*    The Key
* Summary: 
*    Simple program to greet the user
*******************************************************************/
#include <iostream>
using namespace std;

/********************************************************************
 * Simple function to greet the user.  Note that we don't know how
 * to pass text to functions yet, so in this case there is no
 * modularization criteria in the grading rubric. 
 *********************************************************************/
int main()
{
   // variables
   char nameProf[256];
   char nameFirst[256];

   // PROMPT for name
   // GET nameProf
   cout << "What is your professor's name: ";
   cin  >> nameProf;

   // PROMPT for name
   // GET nameFirst
   cout << "What is your first name: ";
   cin >> nameFirst;

   // DISPLAY nameFirst, nameProf
   cout << "\t" 
        << nameFirst
        << ", you are taking Br. "
        << nameProf
        << "'s class \"CS124\".\n";

   // make like a tree
   return 0;
}
