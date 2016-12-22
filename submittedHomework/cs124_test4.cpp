/***********************************************************************
* Program:
*    Test 4, Word Count
*    Brother Falin, CS124
* Author:
*    Andrew Lundgren
* Summary: 
*    
*    This program accepts the user's argument as a filename, then it
*    reads the file into an array while it counts how many words are in
*    the file. It then tells the user how many words there are. 
*
*    Estimated:  0.5 hrs   
*    Actual:     0.15 hrs
*      There wasn't a hard part to the test.
************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void displayCount(int wordCount, string& filename);

/**************************************************************
 * This gets the filename if there was no argument at run time.
 **************************************************************/
string getFilename()
{
   string filename;
   cout << "Please enter the filename: ";
   cin >> filename;

   return filename;
}

/**************************************************************
 * This reads the content of the file into an array and counts
 * how many words there are in the file.
 **************************************************************/
int getWordCount(string& filename)
{
   int wordCount = 0;
   string content;
   
   ifstream fin(filename.c_str());
   
   if (fin.fail())
      return 0;
   
   while (fin >> content)
   {
      wordCount++;
   }
   
   fin.close();
   
   return wordCount;
}

/***********************************************************************
 * The main function is a driver that can accept arguments from the user
 * and then sends the results of getWordCount to displayCount.
 ***********************************************************************/
int main(int argc, char* argv[])
{
   string filename;
   
   if (argc > 1)
   {
      filename = argv[1];
   }
   else
   {
      filename = getFilename();
   }
   
   int wordCount = getWordCount(filename);
   displayCount(wordCount, filename);
   
   return 0;
}

/********************************************
 * Displays the word count.
 ********************************************/
void displayCount(int wordCount, string& filename)
{
   if (wordCount > 1)
   {
      cout << "There are " << wordCount
           << " words in " << filename << "." << endl;
   }
   else if (wordCount == 1)
   {
      cout << "There is 1 word in " << filename << "." << endl;
   }
   else if (wordCount == 0)
   {
      cout << "The file " << filename << " has no words." << endl;
   }
}
