/***********************************************************************
* Program:
*    Assignment 40, Tic Tac Toe
*    Brother Falin, CS124
* Author:
*    Andrew Lundgren
* Summary: 
*    This program asks the user for a file, reads it, loads the tic
*    tac toe board into a 2D array, displays the board, and then saves it.
*
*    Estimated:  2.0 hrs   
*    Actual:     2.0 hrs
*      The hardest part was knowing how to use the 2D array.
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

#define ROWS 3
#define COLS 3

/**********************************************************************
 * Gets filename from user.
 **********************************************************************/
void getFile(char fileName[])
{
   cout << "Enter source filename: ";
   cin >> fileName;
}

/**********************************************************************
 * Loads the file's data into a 2D array.
 **********************************************************************/
bool loadGame(char fileName[], char board[][COLS])
{
   ifstream fin(fileName);

   if (fin.fail())
      return false;

   for (int r = 0; r < ROWS; r++)
   {
      for (int c = 0; c < COLS; c++)
      {
         fin >> board[r][c];
      }
   }

   fin.close();
   return true;
}

/************************************************************************
 * This displays the 2d array
 ************************************************************************/
void displayGame(char board[][COLS])
{
   for (int r = 0; r < ROWS; r++)
   {
      // this will all happen before the row starts
      for (int c = 0; c < COLS; c++)
      {
         // this will happen before the column starts
         if (board[r][c] == '.')
            cout << "   ";
         else
            cout << " " << board[r][c] << " ";
         
         // after column ends
         if (c < (COLS - 1))
            cout << "|";
      }
      // after row ends
      if (r < (ROWS - 1))
      {
         cout << endl;
         cout << "---+---+---" << endl;
      }
   }
   cout << endl;
}

/******************************
 * Get save name.
 ******************************/
void getSaveFilename(char filename[])
{
   cout << "Enter destination filename: ";
   cin >> filename;
}

/******************************************
 * Save the file.
 ******************************************/
bool saveFile(char filename[], char board[][COLS])
{
   ofstream fout(filename);
   if (fout.fail())
      return false;

   for (int r = 0; r < ROWS; r++)
   {
      for (int c = 0; c < COLS; c++)
      {
         fout << board[r][c];

         if (c < (COLS - 1))
            fout << " ";
      }

      if (r < (ROWS - 1))
         fout << endl;
   }

   fout.close();
   cout << "File written\n";
   return true;
}

/**********************************************************************
 * Driver function.
 ***********************************************************************/
int main()
{
   char filename[256];
   getFile(filename);

   char board[ROWS][COLS];
   loadGame(filename, board);
   displayGame(board);
   getSaveFilename(filename);
   saveFile(filename, board);
   return 0;
}
