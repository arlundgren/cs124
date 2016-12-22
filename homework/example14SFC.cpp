#include <iostream>
#include <iomanip>
using namespace std;

/*
 * Return Nothing. This function will not return anything
 * Its only purpose is to display test on the screen.
 */

void returnNothing()
{
   // display question
   cout << "What is the meaning of life, the universe, and everything?\n";

   // send no information back to main()
   return;
}

int returnAValue()
{
   // make a value to return
   return 42;
}

int main()
{
   // call the function asking the question
   returnNothing();

   //display answer
   cout << "The answer is: "
        << returnAValue()
        << endl;

   return 0;

}
