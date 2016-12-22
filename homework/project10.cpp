/***********************************************************************
* Program:
*    Project 10, Mad Libs
*    Brother Falin, CS124
* Author:
*    Andrew Lundgren
* Summary: 
*    This program asks the user for the name of a file. It then
*    find the file, opens it, reads it into an array, and then
*    reads the array to determine what to prompt the user.
*    It stores the user's answers in the file contents, and then
*    displays the story.
*
*    Estimated:  4.0 hrs   
*    Actual:     6.0 hrs
*      The hardest part by far was determining the spacing in display.
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

int readFile(char fileName[], char fileContents[][32]);
void askQuestion(char fileContents[][32], int wordCount);
void getFile(char fileName[]);
int displayStory(char fileContents[][32], int wordCount);

/**********************************************************************
 * Main has a loop that drives the functions as long as the user input
 * is 'y'.
 ***********************************************************************/
int main()
{
   char fileName[256];
   char fileContents[256][32];
   char answer = 'y';
   while (answer != 'n')
   {
      getFile(fileName);
      int wordCount = readFile(fileName, fileContents);
   
      askQuestion( fileContents, wordCount);
      displayStory(fileContents, wordCount);
      cout << endl;
      
      cout << "Do you want to play again (y/n)? ";
      cin >> answer;
      cin.ignore();
      if (answer == 'n')
         cout << "Thank you for playing.\n";
   }
   return 0;
}

/***********************************************************
 * This gets the name of the user's file.
 ***********************************************************/
void getFile(char fileName[])
{
   cout << "Please enter the filename of the Mad Lib: ";
   cin.getline(fileName, 256);
}

/***********************************************************
 * This opens the user's file and reads it into an array. it
 * also returns the word count to main.
 ***********************************************************/
int readFile(char fileName[], char fileContents[][32])
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

/******************************************************************
 * This function prompts the user for new words to use in the story.
 * Their responses are replace the prompts in the array.
 ******************************************************************/
void askQuestion(char fileContents[][32], int wordCount)
{
   for (int i = 0; i <= wordCount; i++)
   {
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
         cin.getline(fileContents[i], 32);
      }
   }
   cout << endl;
}

/**************************************************************
 * This function reads each word and prints spaces according to
 * certain parameters. It then prints words and special
 * punctuation.
 **************************************************************/
int displayStory(char fileContents[][32], int wordCount)
{
   for (int i = 0; i < wordCount; i++)
   {
      if (i != 0
          && (isalpha(fileContents[i][0])
              || fileContents[i][1] == '{'
              || fileContents[i][1] == '[')
          && fileContents[i - 1][1] != '#'
          && fileContents[i - 1][1] != '['
          && fileContents[i - 1][1] != '{')
         cout << " ";
      
      if (fileContents[i - 1][0] == '.' && isalpha(fileContents[i][0]))
         fileContents[i][0] = toupper(fileContents[i][0]);
      
      if (isalpha(fileContents[i][0]))
         cout << fileContents[i];
      else if (fileContents[i][0] == '.')
         cout << fileContents[i];
      else if (fileContents[i][0] == '?')
         cout << fileContents[i];
      else if (fileContents[i][0] == '!')
         cout << fileContents[i];
      else if (fileContents[i][0] == ',')
         cout << fileContents[i]; 
      else if (fileContents[i][1] == '{')
         cout << "\"";
      else if (fileContents[i][1] == '}')
         cout << "\"";
      else if (fileContents[i][1] == '[')
         cout << "\'";
      else if (fileContents[i][1] == ']')
         cout << "\'";
      else if (fileContents[i][1] == '#')
         cout << endl;
   }
   return 0;
}
