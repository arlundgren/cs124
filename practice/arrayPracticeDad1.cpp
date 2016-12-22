#include <iostream>
#include <string>
using namespace std;

void getProfName(string& name);
void getName(string& name);
const void display(const string& profName, const string& name);

int main()
{
   string profName;
   getProfName(profName);
   string name;
   getName(name);
   display(profName, name);
   return 0;
}

void getProfName(string& profName)
{
   cout << "What is your professor's name? ";
   cin >> profName;
}

void getName(string& name)
{
   cout << "What is your first name? ";
   cin >> name;
}

const void display(const string& profName, const string& name)
{
   cout << name << ", you are taking Br. "
        << profName << "'s class, \"CS124\". "
        << endl;
}
