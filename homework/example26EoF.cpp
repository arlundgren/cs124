#include <iostream>
#include <fstream>

main usingEoF(const char filename[])
{
   ifstream fin(filename);
   if (fin.fail())
   {
      cout << "Unable to open file " << filename endl;
      return;
   }

   // get the data and display it on the screen
   char test[256];
   // keep reading as long as not at the end of file
   while (!fin.eof())
   {
      fin >. text;
      cout << "'" << text << "' ";
   }

   fin.close();
}
