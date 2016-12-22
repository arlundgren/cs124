/***********************************************************************
* Program:
*    Project 09, Mad Libs
*    Brother Falin, CS124
* Author:
*    Andrew Lundgren
* Summary: 
*    This part of the Mad Libs project reads a file, stores it in an
*    array, and then prompts the user for input to change the story.
*
*    Estimated:  2.0 hrs   
*    Actual:     1.5 hrs
*      The hardest part was correctly formatting the prompt section. 
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

int readFile(char fileName[], char fileContents[][256]);
void askQuestion(char fileContents[][256], int wordCount);
void getFile(char fileName[]);
/**********************************************************************
 * Main runs other functions to alter the strings in order to create the
 * Mad Libs story.
 ***********************************************************************/
int main()
{
   char fileName[256];
   char fileContents[1024][256];
   
   getFile(fileName);
   int wordCount = readFile(fileName, fileContents);
   askQuestion(fileContents, wordCount);
   cout << "Thank you for playing.\n";
   return 0;
}

/******************************************************
 * Gets the file location and name from the user
 ******************************************************/
void getFile(char fileName[])
{
   cout << "Please enter the filename of the Mad Lib: ";
   cin.getline(fileName, 256);
}

/*********************************************************
 * This function reads the file into an array
 *********************************************************/

int readFile(char fileName[], char fileContents[][256])
{
   ifstream fin(fileName);

   if (fin.fail())
   {
      cout << "Error: cannot read file " << fileName << endl;
      return 0;
   }

   int i = 0;

   while (fin >> fileContents[i])
   {
      i++;
   }
   fin.close();
   return i;
}

/**************************************************************
 * This function traverses the array and prompts the user
 * for input to change the prompts to their desired words.
 **************************************************************/
void askQuestion(char fileContents[][256], int wordCount)
{
   char input[256];
   for (int i = 0; i <= wordCount; i++)
   { // <plural_noun> <#> <.>
      if (fileContents[i][0] == '<' && isalpha(fileContents[i][1]))
         {
            fileContents[i][1] = toupper(fileContents[i][1]);
            
            for (int chara = 0; fileContents[i][chara] != '>'; chara++)
            {
               if (fileContents[i][chara] == '_')
                  cout << " ";
               else if (fileContents[i][chara] == '<')
                  cout << "\t";
               else
                  cout << fileContents[i][chara];
            }
            cout << ": ";

            cin.ignore();
            cin.getline(input, 256);
            *fileContents[i] = *input;
         }
   }
}
