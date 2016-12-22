/***********************************************************************
* Program:
*    Project 13, Sudoku
*    Brother Falin, CS124
* Author:
*    Andrew Lundgren
* Summary: 
*    This is a program to play sudoku! It makes sure when you edit
*    a square that it is a valid value according to the rules. There
*    are several fully usable functions to play the game. It will
*    also allow the user to save the board they are playing so that they
*    can use it later.
*
*    Estimated:  6.0 hrs   
*    Actual:     6.0 hrs
*      The hardest part was making the isValid function and implementing
*      it.
************************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
bool isValid(int board[][9], int rows, int cols, int value);

/*******************************************
 * Get the filename
 *******************************************/
string getFilename()
{
   string filename;
   cout << "Where is your board located? ";
   cin >> filename;

   return filename;
}

/*****************************************
 * Load the board
 *****************************************/
bool loadBoard(string& filename, int board[][9])
{
   ifstream fin(filename.c_str());

   if (fin.fail())
      return false;

   for (int r = 0; r < 9; r++)
      for (int c = 0; c < 9; c++)
         fin >> board[r][c];

   fin.close();
   return true;
}

/****************************************
 * Display the board
 ****************************************/
int displayBoard(int board[][9])
{
   cout << "   A B C D E F G H I\n";
   for (int r = 0; r < 9; r++)
   {
      cout << r + 1 << "  ";
      for (int c = 0; c < 9; c++)
      {
         if (board[r][c] == 0)
            cout << " ";
         else
            cout << board[r][c];
         if (c == 2 || c == 5)
            cout << "|";
         else if (c < 8)
            cout << " ";
      }
      cout << endl;
      if (r == 2 || r == 5)
         cout << "   -----+-----+-----\n";
   }
   cout << endl;
   return 0;
}

/***************************************
 * Display the instructions
 ***************************************/
void displayOptions()
{
   cout << "Options:\n";
   cout << "   ?  Show these instructions\n";
   cout << "   D  Display the board\n";
   cout << "   E  Edit one square\n";
   cout << "   S  Show the possible values for a square\n";
   cout << "   Q  Save and Quit\n";
   cout << endl;
}

/************************************************************
 * Allows the user to edit a square if the value they desire
 * is a valid value.
 ************************************************************/
bool editSquare(int board[][9])
{
   char switcher;
   string coords;
   int value = 0;
   cout << "What are the coordinates of the square: ";
   cin >> coords;
   if (!isalpha(coords[0]))
   {
      switcher = coords[1];
      coords[1] = coords[0];
      coords[0] = switcher;
   }
   coords[0] = toupper(coords[0]);
   int r = coords[1] - 49;
   int c = coords[0] - 65;
   if (board[r][c] != 0)
   {
      cout << "ERROR: Square \'" << coords << "\' is filled\n";
      cout << endl;
      return false;
   }
   else
   {
      cout << "What is the value at \'" << coords << "\': ";
      cin >> value;
      if (!isValid(board, r, c, value))
      {
         cout << "ERROR: Value \'" << value << "\' in square \'"
              << coords << "\' is invalid\n";
         cout << endl;
         return false;
      }
      board[r][c] = value;
      cout << endl;
      return true;
   }
}

/************************************************************
 * Tells the user the valid solutions of the square they
 * specify.
 ************************************************************/
void solutions(int board[][9])
{
   string coords;
   int valids[9];
   int totalNums = 0;

   cout << "What are the coordinates of the square: ";
   cin >> coords;
   
   int r = coords[1] - 49;
   int c = coords[0] - 65;
   
   for (int i = 1; i < 10; i++)
   {
      if (isValid(board, r, c, i))
      {  
         valids[totalNums] = i;
         totalNums++;
      }
   }
   
   cout << "The possible values for \'" << coords << "\' are: ";
   
   for (int j = 0; j < 10; j++)
   {
      if (valids[j] < 10 && valids[j] > 0)
      {
         cout << valids[j];
         if (totalNums > 1 && j != (totalNums - 1))
            cout << ", ";
      }
   }
   cout << endl;
   cout << endl;
}
         
/**************************************
 * Save the board to a specific file
 **************************************/
bool saveBoard(int board[][9])
{
   string filename;
   cout << "What file would you like to write your board to: ";
   cin >> filename;

   ofstream fout(filename.c_str());

   if (fout.fail())
      return false;

   for (int r = 0; r < 9; r++)
   {
      for (int c = 0; c < 9; c++)
      {
         fout << board[r][c] << " ";
      }
      fout << endl;
   }

   fout.close();
   cout << "Board written successfully\n";
   return true;
}

/**********************************************************
 * Checks to see if the value received is valid according
 * to the rules of sudoku.
 **********************************************************/
bool isValid(int board[][9], int rows, int cols, int value)
{
   int y = 0;
   int x = 0;
   for (int r = 0; r < 9; r++)
   {
      if (board[r][cols] == value)
         return false;
   }
   
   for (int c = 0; c < 9; c++)
   {
      if (board[rows][c] == value)
         return false;
   }
   y = ((rows / 3) * 3);
   x = ((cols / 3) * 3);

   
   for (int i = y; i < (y + 3); i++)
      for (int j = x; j < (x + 3); j++)
      {
         if (board[i][j] == value)
            return false;
      }
   return true;
}

/*****************************************************
 * Uses a switch and a loop to allow the user to play
 * the game until they decide to save and quit.
 *****************************************************/
void playGame(int board[][9])
{
   displayOptions();
   displayBoard(board);
   char input = 'o';
   do
   {
      cout << "> ";
      cin >> input;
      switch (input)
      {
         case '?':
            displayOptions();
            cout << endl;
            break;
         case 'D':
         case 'd':
            displayBoard(board);
            break;
         case 'E':
         case 'e':
            editSquare(board);
            break;
         case 'S':
         case 's':
            solutions(board);
            break;
         case 'Q':
         case 'q':
            saveBoard(board);
            break;
         default:
            cout << "ERROR: Invalid command\n";
            break;
      }
   }
   while (input != 'Q' && input != 'q');
}
   
/**********************************************************************
 * The Driver function.
 ***********************************************************************/
int main()
{
   string filename = getFilename();
   int board[9][9];

   loadBoard(filename, board);
   playGame(board);
   return 0;
}
