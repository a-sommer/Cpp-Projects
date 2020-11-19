
// 


// Implementation file for the Odometer class

#include "Odometer.h"   // Necessry for Odometer class
#include "FuelGauge.h"  // Necessary for friend function

// addMileage increments the odometer by 1 mile. If the maximum number of miles
// that can be stored by the odometer is exceeded it resets the odometer to 0.
void Odometer::addMileage()
{
    // Increments the mileage if it is less than or equal to the max
    if (mileage <= ODOMETER_MAX)
    {
        mileage++;
    }

    // If mileage is greater than the max, reset odometer to 0
    if (mileage > ODOMETER_MAX)
    {
        mileage = 0;    // Resets odometer
    }
}

// milesPerGallon is declared a friend by the FuelGauge class. It takes a reference to the FuelGauge class as an argument
// and calls the burnFuel function which decrements the fuel levels by 1 gallon. 
void Odometer::milesPerGallon(FuelGauge & refVar)
{
        refVar.burnFuel();   
}