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
using namespace std;

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   char name[256];
   int age;
   float gpa;
   char letterGrade;

   // Prompt the user for his first name
   cout << "What is your first name: ";
   cin >> name;

   // Prompt the user for his age
   cout << "What is your age: ";
   cin >> age;

   // Prompt the user for his GPA
   cout << "What is your GPA: ";
   cin >> gpa;

   // Ask the user what grade they hope to get
   cout << "What grade to you hope to get in CS 124: ";
   cin >> letterGrade;

   // configure the display to show GPAs: one digit of accuracy
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(1);

   // Display the results!
   cout << "\t" << name
        << ", you are " << age
        << " with a " << gpa
        << "GPA. You will get an " << letterGrade
        << ". \n";
   
   return 0;
}
