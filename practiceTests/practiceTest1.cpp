/**************************************************
* Program:
*    Test 1,
*    Brother Falin, CS124
* Author:
*    Andrew Lundgren
* Summary: 
*    Enter a brief description of your program here!  Please note that if
*    you do not take the time to fill out this block, YOU WILL LOSE POINTS
************************************************************/
#include <iostream>
using namespace std;

float getGPA(float gpa);
void display(float gpa);

int main()
{
   float gpa =  getGPA(gpa);
   display(gpa);

   return 0;
}

float getGPA(float gpa)
{
   // Prompt the user for their GPA
   cout << "What is your GPA? ";
   cin >> gpa;
   return gpa;
}

void display(float receivedGPA)
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(1);
   cout << "Your GPA is " << receivedGPA << endl;
   return;
}
