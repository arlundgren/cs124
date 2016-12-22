/***********************************************************************
* Program:
*    Project 12, Sudoku Part 1
*    Brother Falin, CS124
* Author:
*    Andrew Lundgren
* Summary: 
*    This is the first part of the sudoku program, you may enter values
*    into squares and save the board into another file.
*
*    Estimated:  2.0 hrs   
*    Actual:     2.0 hrs
*      The hardest part was saving user input to the board.
************************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

/******************************************
 * Gets the name of the file from the user
 ******************************************/
string getFilename()
{
   string filename;
   cout << "Where is your board located? ";
   cin >> filename;

   return filename;
}

/**************************************************
 * This takes the received filename and uses it to
 * Open the file and read it into a 2D array
 **************************************************/
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

/*************************************************
 * This will display the board whenever called.
 ************************************************/
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

/*************************************************
 * This displays the instruction to the user when
 * called.
 *************************************************/
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

/**************************************************
 * This allows the user to edit any square based on
 * it's coordinates.
 **************************************************/
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
      board[r][c] = value;
      cout << endl;
      return true;
   }
}

//void solutions(int board[][9]);

/***************************************************
 * This allows the user to save the board to a file
 * of their choice.
 **************************************************/
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

/******************************************************
 * This is a function that allows the user to play the
 * game until they decide to save and quit.
 ******************************************************/
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
            //          solutions(board);
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
 * Main is the driver function.
 ***********************************************************************/
int main()
{
   string filename = getFilename();
   int board[9][9];

   loadBoard(filename, board);
   playGame(board);
   return 0;
}
