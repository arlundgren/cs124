#include <iostream>
#include <iomanip>
using namespace std;

void displayTable(int numDays, int offset)
{
   cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";
   int day = 1;
   int position = offset + 2;
   if (offset == 6)
   {
      position = 1;
   }

   for (int i = 1; i < 7; i++)
   {
      cout << setw(4);
      if (i == position)
      {
         cout << day;
         position++;
         day++;
         numDays--;
      }
      else
         cout << " " << setw(4) << " ";
   }

   cout << endl;

   while (numDays > 0)
   {
      cout << setw(4);
      for (int i = 0; i <= 7; i++)
      {
         cout << day << setw(4);
         day++;
         numDays--;
      }
      cout << endl;
   }
}
     
int main()
{
   int numDays = 0;
   int offset = 0;

   cout << "Number of days: ";
   cin >> numDays;

   cout << "Offset: ";
   cin >> offset;

   displayTable(numDays, offset);
   return 0;
}
