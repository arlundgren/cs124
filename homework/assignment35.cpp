/***********************************************************************
* Program:
*    Assignment 35, Advanced Conditionals
*    Brother Falin, CS124
* Author:
*    Andrew Lundgren
* Summary: 
*   This program takes a percentage that the user inputs and determines
*   what the letter grade and sign should be.
*
*    Estimated:  1.0 hrs   
*    Actual:     1.0 hrs
*      It wasn't a difficult assignment.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * This function determines what the letter grade should be based on
 * what the swtich returns
 **********************************************************************/
void computeLetterGrade(int grade, char &letterGrade)
{
   switch (grade / 10)
   {
      case 10:
      case 9:
         letterGrade = 'A';
         break;
      case 8:
         letterGrade = 'B';
         break;
      case 7:
         letterGrade = 'C';
         break;
      case 6:
         letterGrade = 'D';
         break;
      default:
         letterGrade = 'F';
   }
}

/**********************************************************************
 * This function determines what the grade sign should be based on
 * the switch.
 **********************************************************************/
void computeGradeSign(int grade, char &sign)
{
   switch (grade % 10)
   {
      case 9:
      case 8:
      case 7:
         if (grade < 90 && grade > 60)
            sign = '+';
         break;
      case 2:
      case 1:
      case 0:
         if (grade < 90 && grade > 60)
            sign = '-';
         break;
      default:
         sign = '*';
         break;

         
   switch (grade)
   {
      case 92:
      case 91:
      case 90:
         sign = '-';
         break;
      case 89:
      case 88:
      case 87:
         sign = '+';
         break;
      case 82:
      case 81:
      case 80:
         sign = '-';
         break;
      case 79:
      case 78:
      case 77:
         sign = '+';
         break;
      case 72:
      case 71:
      case 70:
         sign = '-';
         break;
      case 69:
      case 68:
      case 67:
         sign = '+';
         break;
      case 62:
      case 61:
      case 60:
         sign = '-';
         break;
      default:
         sign = '*';
         break;
   }
}

/**********************************************************************
 * This function runs the other functions, as well as prompts the user
 * for the percentage they would like to use.
 ***********************************************************************/
int main()
{
   int grade = 0;
   char letterGrade;
   char sign;

   cout << "Enter number grade: ";
   cin >> grade;

   computeLetterGrade(grade, letterGrade);
   computeGradeSign(grade, sign);

   cout << grade << "% is " << letterGrade;
   if (sign != '*')
      cout << sign;
   cout << endl;
   return 0;
}
