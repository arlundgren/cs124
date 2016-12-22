/***********************************************************************
* Program:
*    Assignment 14, Matthew 18:21-22
*    Brother Falin, CS124
* Author:
*    Andrew Lundgren
* Summary: 
*    This program will address Peter's question to the Lord in 
*    Matthew 18:21-22
*
*    Estimated:  0.75 hrs   
*    Actual:     0.6 hrs
*      The hardest part was determining what kind of functions question
*      and response should be.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * This first function, questionPeter(), tells the console to first
 * print the first half of his question and then end the line and
 * finish the question. It is a void because it doesn't need to send
 * a value back to the main function, just print the text.
 **********************************************************************/
void questionPeter()
{
   // Peter's question
   cout << "Lord, how oft shall my brother sin against me, "
        << "and I forgive him?\n";
   cout << "Till seven times?\n";

   return;
}

/**********************************************************************
 * The second function, responseLord() makes a variable, answer, and
 * the value of answer is afterwards declared as (7 * 70). At the end,
 * it returns the value of answer back to the main function.
***********************************************************************/
int responseLord()
{
   int answer;
   answer = 7 * 70;

   return answer;
}

/*********************************************************************
 * The main function first calls for questionPeter() to run. Since
 * questionPeter() doesn't return any values, it just runs itself.
 * Afterwards, it runs a cout command to say what Christ said. In
 * the second cout line, it asks for the responseLord() function to
 * run and so the responseLord() function runs and sends its value
 * to be printed in the cout command in the int function.
**********************************************************************/
int main()
{
   // ask Peter's question
   questionPeter();

   // the first part of the Lord's response
   cout << "Jesus saith unto him, I say not unto thee, Until seven\n";
   cout << "times: but, Until " << responseLord() << ".\n";

   return 0;
}
