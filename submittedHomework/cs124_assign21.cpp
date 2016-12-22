/***********************************************************************
* Program:
*    Assignment 21, Stub Functions
*    Brother Falin, CS124
* Author:
*    Andrew Lundgren
* Summary: 
*    This is a bunch of function stubs!
*
*    Estimated:  0.5 hrs   
*    Actual:     0.5 hrs
*      The most difficult part was remembering to set my display()
*      parameters correctly.
************************************************************************/

#include <iostream>
using namespace std;

float getPeriodicCost();
float promptDevalue();
float promptInsurance();
float promptParking();

float getUsageCost();
float promptMileage();
float promptGas();
float promptRepairs();
float promptTires();

void display(float costUsage, float costPeriodic);
/**********************************************************************
 * These are a lot of fun stubs.
 ***********************************************************************/
int main()
{
   float costUsage = getUsageCost();
   float costPeriodic = getPeriodicCost();
   display(costUsage, costPeriodic);
   return 0;
}

float getPeriodicCost()
{
   return (promptDevalue() + promptInsurance() + promptParking());
}

float promptDevalue()
{
   return 0;
}

float promptInsurance()
{
   return 0;
}

float promptParking()
{
   return 0;
}

float getUsageCost()
{
   return (promptMileage() + promptGas() + promptRepairs()
           + promptTires());
}

float promptMileage()
{
   return 0;
}

float promptGas()
{
   return 0;
}

float promptRepairs()
{
   return 0;
}

float promptTires()
{
   return 0;
}

void display(float costUsage, float costPeriodic)
{
   cout << "Success\n";
}
