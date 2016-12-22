#include <iostream>
#include <iomanip>
using namespace std;

/*
 * Pass Nothing: No information is being sent to the function
 */
void passNothing()
{
   cout << "passNothing()\n";
   
   // a different variable than the one in MAIN
   int value;
   value = 0;

}

/*
 * Pass By Value: One-way flow of information from MAIN to the function.
 *                No data is being sent back to MAIN
 */
void passByValue(int value)
{
   // Show the user what value was sent to the function
   cout << "passByValue(" << value << ")\n";

   // this is a copy of the variable in MAIN this will not
   // influence MAIN in any way:
   value = 1;
}

/*
 * Pass By Reference: Two-way flow of data between the function. Changes to
 *                    REFERENCE will also influence the variable in MAIN
 */
void passByReference(int &reference)
{
   // show the user what value was sent to the function
   cout << "passByReference(" << reference << ")\n";

   // this will actually change MAIN because there was the &
   // in the parameter
   reference = 2;
}

int main()
{
   int value = 10;

   // first, pass nothing. There will be no influence on the variables
   // in main.
   cout << "========== passNothing ==========\n";
   cout << "Before: " << value << endl;
   passNothing();
   cout << "After: " << value << endl;

   // next, pass-by-value. We will not be changing Main's copy here
   cout << "========== passByValue ==========\n";
   cout << "Before: " << value << endl;
   passByValue(value);
   cout << "After: " << value << endl;

   // finally, pass-by-reference. MAIN will change here
   cout << "========== passByReference ==========\n";
   cout << "Before: " << value << endl;
   passByReference(value);
   cout << "After: " << value <<  endl;

   return 0;
}
