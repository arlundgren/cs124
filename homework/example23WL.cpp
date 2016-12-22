#include <iostream>
using namespace std;

int main()
{
   char grade;

   cout << "Please enter your letter grade: ";
   cin >> grade;

   while (grade != 'A' && grade != 'B' && grade != 'C' &&
          grade != 'D' && grade != 'F')
   {
      cout << "Invalid grade. Please enter a letter grade {A,B,C,D,F} ";
      cin >> grade;
   }

   return 0;
}
