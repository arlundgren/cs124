/***********************************************************************
* Program:
*    Assignment ##, ????          (e.g. Assignment 10, Hello World)
*    Brother {Cook, Comeau, Falin, Lilya, Honeycutt, Unsicker, Peterson, Phair, Ellsworth}, CS124
* Author:
*    your name
* Summary: 
*    Enter a brief description of your program here!  Please note that if
*    you do not take the time to fill out this block, YOU WILL LOSE POINTS.
*    Before you begin working, estimate the time you think it will
*    take you to do the assignment and include it in this header block.
*    Before you submit the assignment include the actual time it took.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;
bool isValid(int board[][9], int rows, int cols, int value);

string getFilename()
{
   string filename;
   cout << "Where is your board located? ";
   cin >> filename;

   return filename;
}

bool loadBoard(string& filename, int board[][9], int firstBoard[][9])
{
   int r = 0;
   int c = 0;
   int i = 0;
   string myFile = "myFile.txt.";
   string contents;
   int myBoard[9][9];
   ofstream fout;
   ifstream fin(filename.c_str());

   if (fin.fail())
      return false;

   for (r = 0; r < 9; r++)
      for (c = 0; c < 9; c++)
         fin >> board[r][c];

   fin.close();

/*   fin.open(myFile.c_str());

   if (fin.fail())
      return false;
   
   fin >> contents;
   
   fin.close();*/

   fin.open(filename.c_str());

   for (r = 0; r < 9; r++)
      for (c = 0; c < 9; c++)
         fin >> firstBoard[r][c];

   fin.close();

   /*if (contents.empty())
   {
      fout.open(myFile.c_str());
      for (r = 0; r < 9; r++)
         for (c = 0; c < 9; c++)
            fout << firstBoard[r][c] << " ";
      fout.close();
   }
   else if (!contents.empty())
   {
      for (r = 0; r < 9; r++)
      {
         for (c = 0; c < 9; c++)
         {
            firstBoard[r][c] = contents[i];
            i++;
         }
      }
      }*/
   return true;
}

int displayBoard(int board[][9], int firstBoard[][9])
{
   cout << "   A B C D E F G H I\n";
   for (int r = 0; r < 9; r++)
   {
      cout << r + 1 << "  ";
      for (int c = 0; c < 9; c++)
      {
         if (board[r][c] == 0)
            cout << " ";
         else if (abs(board[r][c]) == firstBoard[r][c])
            cout << "\E[22;32m" << firstBoard[r][c] << "\E[0m";
         else
            cout << abs(board[r][c]);
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

bool editSquare(int board[][9])
{
   char switcher;
   string coords;
   int value = 0;
   bool passed = true;
   int c = 0; 
   int r = 0;
   do
   {
      cout << "What are the coordinates of the square: ";
      cin >> coords;
      
      if (!isalpha(coords[0]))
      {
         switcher = coords[1];
         coords[1] = coords[0];
         coords[0] = switcher;
      }
      
      r = coords[1] - 49;
      c = coords[0] - 65;
      if (isalpha(coords[0]) && isalpha(coords[1]))
      {
           cout << "ERROR: Square \'" << coords << "\' is invalid\n";
           passed = false;
      }
      else if (board[r][c] != 0)
      {
         coords[0] = toupper(coords[0]);
         cout << "ERROR: Square \'" << coords << "\' is filled\n";
         cout << endl;
         passed = false;
      }
      else
         passed = true;
   }
   while (passed == false);
  
   cout << "What is the value at \'" << coords << "\': ";
   cin >> value;
   if (value > 9 || value < 1 || !isValid(board, r, c, value))
   {
      cout << "ERROR: Value \'" << value << "\' in square \'"
           << coords << "\' is invalid\n";
      cout << endl;
      return false;
   }
   board[r][c] = -value;
   cout << endl;
   return true;
}


void solutions(int board[][9])
{
   string coords;
   int valids[9];
   int totalNums = 0;
   string switcher;
   int number = 0;
   cout << "What are the coordinates of the square: ";
   cin >> coords;
   if (isalpha(coords[1]))
   {
      switcher[0] = coords[1];
      number = coords[0];
      coords[0] = coords[1];
      coords[1] = number;
   }
   coords[0] = (toupper(coords[0]));
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
         
      
bool saveBoard(int board[][9], int firstBoard[][9])
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

bool isValid(int board[][9], int rows, int cols, int value)
{
   // 0 1 2 3 4 5 6 7 8
   int y = 0;
   int x = 0;
   for (int r = 0; r < 9; r++)
   {
      if (abs(board[r][cols]) == value)
         return false;
   }
   
   for (int c = 0; c < 9; c++)
   {
      if (abs(board[rows][c]) == value)
         return false;
   }
   y = ((rows / 3) * 3);
   x = ((cols / 3) * 3);

   for (int i = y; i < (y + 3); i++)
      for (int j = x; j < (x + 3); j++)
      {
         if (abs(board[i][j]) == value)
            return false;
      }
   return true;
}

bool validBoard(int board[][9])
{
   int i = 1;
   int dups = 0;
   int r = 0;
   int c = 0;
   do
   {
      for (int rows = 0; r < 9; r += 3)
      {
         for (int cols = 0; c < 9; c += 3)
         {  
            for (r = rows; r < (rows + 3); r++)
            {
               for (c = cols; c < (cols + 3); c++)
               {
                  if (abs(board[r][c]) == i)
                     dups++;
               }
            }            
         }
      }
      if (dups < 2);
      {
         i++;
         dups = 0;
      }
   }
   while (dups < 2 || i < 10);
   if (dups == 2)
   {
      char coord = r + 65;
      cout << "ERROR: duplicate value \'" << i << "\' in "
           << "inside square represented by \'"
           << c << coord << "\'\n";
         
      
}
         
bool playGame(int board[][9], int firstBoard[][9])
{
   bool validBoard = true;
   int r = 0;
   int c = 0;
   int val = 1;
   for (r = 0; r < 9; r++)
   {
      for (c = 0; c < 9; c++)
      {
         val = board[r][c];
         if (!isValid(board, r, c, val))
         {
            char row = r + 65;
            char col = c + 49;
            //validBoard = false;
            cout << "ERROR: Duplicate value \'" << val
                 << "\' in inside square represented by \'"
                 << row << col << "\'\n";
            return false;
         }
      }
   }
   displayOptions();
   displayBoard(board, firstBoard);
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
            displayBoard(board, firstBoard);
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
            saveBoard(board, firstBoard);
            break;
         default:
            cout << "ERROR: Invalid command\n" << endl;
            break;
      }
   }
   while (input != 'Q' && input != 'q');
   return false;
}
   
/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   string filename = getFilename();
   int board[9][9];
   int firstBoard[9][9];

   loadBoard(filename, board, firstBoard);
   playGame(board, firstBoard);
   return 0;
}
