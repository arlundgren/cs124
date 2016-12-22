#include <iostream>
#include <iomanip>
using namespace std;

// Get age is prompting the user for his age. Ask the user for age, receive input,
// return input to the main function

int getAge()
{
   int age;
   cout << "What is your age? ";
   cin >> age;
   return age;
}

// The Main function tests the getAge() function.

int main()
{
   // get the user input
   int age = getAge();

   //display the results
   cout << "Your age is "
        << age
        << " years old.\n";
   return 0;
}
