
// 


// Implementation file for the FuelGauge class

#include <iostream>    // Necessary for input/output operations
#include "FuelGauge.h" // Necessary for the FuelGauge class


using namespace std;   // Defines the scope, so there's no need to prefix with std::

// addFuel increments the fuel level by one gallon, as long as the tank is not full. 
void FuelGauge::addFuel()
{
    if (fuel < maxFuel)
    {
        fuel++;
    }       
}

// burnFuel decrements the fuel by 1 gallon as long as the tank is not empty.
void FuelGauge::burnFuel()
{
    if (fuel > 0)
    {
        fuel--;
    }
}