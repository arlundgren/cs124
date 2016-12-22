 /***********************************************************************
* Program:
*    Assignment 14, Allocating Memory
*    Brother Falin, CS124
* Author:
*    Andrew Lundgren
* Summary: 
*    This program uses user input to allocate an array, uses input to
*    fill it, then displays it.
*
*    Estimated:  0.5 hrs   
*    Actual:     0.5 hrs
*      The hardest part was understanding the allocation syntax.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Main asks the user for how many characters the array should be,
 * allocates it, asks for input, and displays the input.
 ***********************************************************************/
int main()
{
   int size = 0;
   do
   {
      cout << "Number of characters: ";
      cin >> size;
      if (size <= 0)
      {
         cout << "Allocation failure!\n";
         return 0;
      }
   }
   while (size <= 0);
   cin.ignore();

   char * pChar = new(nothrow) char [size + 1];
   if (!pChar)
   {
      cout << "No memory!\n";
      return 0;
   }
   
   cout << "Enter Text: ";
   cin.getline(pChar, size + 1);

   cout << "Text: " << pChar << endl;

   delete [] pChar;
   
   return 0;
}
