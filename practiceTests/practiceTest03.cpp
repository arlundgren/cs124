/**************************************************
* Program:
*    Test 1,
*    Brother {Cook, Comeau, Falin, Lilya, Unsicker, Phair}, CS124
* Author:
*    your name
* Summary: 
*    Enter a brief description of your program here!  Please note that if
*    you do not take the time to fill out this block, YOU WILL LOSE POINTS
************************************************************/
#include <iostream>
using namespace std;

int main()
{
   char nameProf[256];
   char nameFirst[256];
   // Prompt the user for their teacher's name
   cout << "What is your professor's name: ";
   cin >> nameProf;

   // Prompt the user for their first name
   cout << "What is your first name: ";
   cin >> nameFirst;

   // Display those names, boy!
   cout << nameFirst;
   cout << ", you are taking Br. ";
   cout << nameProf;
   cout << "'s class \"CS124\". \n";

   return 0;
}
