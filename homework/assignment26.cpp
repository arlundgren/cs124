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
using namespace std;

void getFileName(char fileName[]);
float readFile(char fileName[]);
void displayAverage(float sum);

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   char fileName[256];
   getFileName(fileName);
   float sum = readFile(fileName);

   if (sum != -1)
      displayAverage(sum);
   else
      cout << "Error reading file \"" << fileName << "\""
           << endl;
   return 0;
}

void getFileName(char fileName[])
{  
   cout << "Please enter the filename: ";
   cin >> fileName;
}

float readFile(char fileName[])
{
   ifstream fin(fileName);
   if (fin.fail())
   {
      return -1;
   }

   float data[10];
   float sum = 0;
   int count = 0;
   
   while (fin >> data[count])
   {
      sum += data;
      count++;
   }

   if (count != 10)
   {
      fin.close();
      return -1;
   }

   fin.close();

   cout.precision(0);
   cout.setf(ios::fixed);
   
   return sum / 10;
}

void displayAverage(float sum)
{
   cout << "Average Grade: " << sum << "%\n";
}
