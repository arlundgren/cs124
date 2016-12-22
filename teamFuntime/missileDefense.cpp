#include <iostream>
using namespace std;

int main();
float getMissileDistance();
float convertKilometersToMiles(float km);
bool shouldFireMissile(float distance);
bool shouldFireSF(float distance);
bool shouldTakeCover(float distance);

int main()
{
   cout << "Super Secret Missile Defense Program\n";
   cout << "\n";
   
   float distanceKm;
   distanceKm = getMissileDistance();
   float distanceM;
   distanceM = convertKilometersToMiles(distanceKm);
   
   cout.setf(ios::showpoint);
   cout.setf(ios::fixed);
   cout.precision(2);
   
   {
   if (shouldFireMissile(distanceM))
      cout << "\tDistance is " << distanceM << " miles, fire standard missile!\n";
   else if (shouldFireSF(distanceM))
      cout << "\tDistance is " << distanceM << " miles, fire ultra missile!\n";
   else if (shouldTakeCover(distanceM))
      cout << "\tDistance is " << distanceM << " miles, take cover!\n";
   else
      cout << "\tDistance is " << distanceM << " miles, hold your fire.\n";
   
   }
   
   return 0;
}

float getMissileDistance()
{
   float distance;
   cout << "\tEnter the distance of the missile: ";
   cin >> distance;
   return distance;
}

float convertKilometersToMiles(float km)
{
   float miles = km * .62137;
   return miles;
}

bool shouldFireMissile(float distance)
{
   int range = 30;
   {
   if (distance > 30 || distance < 10)
      return false;
   else
      if (distance < 30 && distance > 10)
         return true;
   }
}
   
bool shouldTakeCover(float distance)
{
   if (distance < 3)
      return true;
   else
      return false;
}

bool shouldFireSF(float distance)
{
   if (distance < 10 && distance > 3)
      return true;
   else
      return false;
}