/***********************************************************************
* Program:
*    Assignment 32, Counting Letters
*    Brother Falin, CS124
* Author:
*    Andrew Lundgren
* Summary: 
*    This program gets a letter from the user and then a sentence,
*    then it counts how many of that letter are in the sentence.
*
*    Estimated:  0.4 hrs   
*    Actual:     0.05 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <cassert> 
using namespace std;

int countLetters(char text[], char letter[]);
/**********************************************************************
 * The Main function prompts the user for a letter, than a text, runs
 * countLetters and tells the user how many letters are in their text.
 ***********************************************************************/
int main()
{
   char text[256];
   char letter[1];

   cout << "Enter a letter: ";
   cin >> letter;
   cout << "Enter text: ";
   cin.ignore();
   cin.getline(text, 256);

   float numLetters = countLetters(text, letter);

   cout << "Number of '" << letter << "'s: " << numLetters << endl;
   return 0;
}

/**********************************************************
 * countLetters() reads the arrays it receives using a pointer
 * and then counts how many of the specific letter are in it.
 * It then sends an int value back to main.
 **********************************************************/
int countLetters(char text[], char letter[])
{
   int numLetters = 0;
   
   for (char* p = text; *p; p++)
   {
      if (*p == letter[0])
         numLetters++;
   }
   
   return numLetters;
}
   
