#include <iostream>
using namespace std;

int main()
{
   cout << "Please enter a collection of integer values. When\n"
        << "\tyou are done, enter zero (0).\n";

   int sum = 0;
   int value;

   do
   {
      cout << "> ";
      cin >> value;

      sum += value;
   }
   while (value != 0);

   cout << "The sum is: " << sum << endl;
   return 0;
}
