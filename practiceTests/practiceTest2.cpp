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

int getGrade(int grade);
void passedTest();
void failedTest();

int main()
{
   int grade = getGrade(grade);
   {
      if (grade > 59)
         passedTest();
      else
         failedTest();
   }
   return 0;
}

int getGrade(int grade)
{
   cout << "What was your grade on the last test? ";
   cin >> grade;
   return grade;
}

void passedTest()
{
   cout << "You passed the test." << endl;
   return;
}

void failedTest()
{
   cout << "You failed the test." << endl;
   return;
}
