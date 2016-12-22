/***********************************************************************
* Program:
*    Test 3, Average Grades
*    Brother Falin, CS124
* Author:
*    Andrew Lundgren
* Summary: 
*    The test gets the grades from a file and returns the average.
*
*    Estimated:  0.2 hrs   
*    Actual:     1.0 hrs
*      I don't know why the test to see if the file runs never fails,
*      so I forced it to not work if the average is less than zero.
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

/*********************************************************************
 * Reads the file, checks to see if it runs, and then gets the average
 * of the list of grades in the file.
 *********************************************************************/
float readFile(char filename[])
{
   ifstream fin(filename);

   if (fin.fail())
   {
      return -1;
   }
   
   float grades[100] = {};
   int i = 0;
   while (fin >> grades[i])
   {
      i++;
   }

   fin.close();
   
   float total = 0;
   for (int j = 0; grades[j]; j++)
   {
      total += grades[j];
   }
   return (2.5 * total) / i;
}

/***************************************************************
 * Main gets the filename from the user and sends it to the
 * readFile function. It then checks to make sure the average
 * is greater than or equal to zero and prints the average.
 ***************************************************************/
int main()
{
   char filename[256] = {};
   cout << "Please specify the file name: ";
   cin.getline(filename, 256);
   
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(1);

   float averageGrades = readFile(filename);
   if (averageGrades >= 0)
   {
      cout << "The average grade on the midterm is "
           << averageGrades << "%\n";
   }
   else
   {
      cout << "Unable to open or read file " << filename
           << "." << endl;
   }
   
   return 0;
}

