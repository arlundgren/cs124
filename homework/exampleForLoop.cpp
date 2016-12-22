#include <iostream>
using namespace std;

int main()
{
   int start;
   int end;
   int counter;

   cout << "What value do you want to start at? ";
   cin >> start;

   cout << "What value do you want to end at? ";
   cin >> end;

   cout << "What will you count by (example: 2s): ";
   cin >> counter;

   for (int count = start; count <= end; count += counter)
      cout << "\t" << count << endl;

   return 0;
}
