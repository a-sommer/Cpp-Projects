
// 


#include <iostream>     // Necessary for input/output
#include "Odometer.h"   // Necessary for Odometer class
#include "FuelGauge.h"  // Necessary for FuelGauge class

using namespace std;    // Defines the scope, so there's no need to prefix with std::

// Function prototypes
void fillTank(FuelGauge&);
void travelDistanceOnFullTank(FuelGauge&, Odometer&);

int main()
{
    FuelGauge car_FuelGauge; // Define an instance of the FuelGauge class
    Odometer car_Mileage; // Define an instance of the Odometer class

    // Let user know that the program will fill the tank with fuel 
    cout << "Filling tank with gas..." << endl;

    // Call function to fill tank 
    fillTank(car_FuelGauge);

    // Notify user that the tank is now full and display how many gallons are in the tank.
    cout << "The tank now has " << car_FuelGauge.getFuelLevel() << " gallons in it and is full." << endl;

    // Describe what the program will do to user. 
    cout << "\nLet's see how far the car can travel before running out of gas:\n" << endl;

    // Call function to find how many miles a car can travel on a full tank.
    travelDistanceOnFullTank(car_FuelGauge, car_Mileage);

    // Display how far the car traveled with a full tank to user.
    cout << "\nThe car traveled " << car_Mileage.getMileage() << " miles on " << car_FuelGauge.maxFuel << " gallons of gas." << endl;   
}

// fillTank takes a reference to a FuelGauge object and adds fuel until the tank is full.
void fillTank(FuelGauge& refTank)
{
    // Adds fuel as long as the maximum fuel level is not reached. 
    while (refTank.getFuelLevel() != refTank.maxFuel)
    {
        refTank.addFuel();
    }
}

// travelDistanceOnFullTank takes objects from the FuelGauge and Odometer classes and
// sees how far the car can travel on a full tank. 
void travelDistanceOnFullTank(FuelGauge& refGasTank, Odometer& refMiles)
{
    int distanceTraveled = 0;   // To hold how many miles the car has traveled

    // Increments the odometer until car runs out of fuel
    while (refGasTank.getFuelLevel() > 0)
    {
        // Increment the total miles on odometer by 1
        refMiles.addMileage();

        // Keeps count of how many miles the car has traveled
        distanceTraveled++;

        // If the distance traveled is equal to how many miles per gallon a car can travel...
        if (distanceTraveled == refMiles.MPG)
        {
            // ...call function that decrements the current fuel level by 1 gallon...
            refMiles.milesPerGallon(refGasTank);

            // ... and reset the distance traveled to 0.
            distanceTraveled = 0;
        }

        // Display current mileage to user. 
        cout << "Current mileage: " << refMiles.getMileage();

        // Display fuel level to user. 
        cout << "\tFuel left in tank: " << refGasTank.getFuelLevel() << endl;
    }
}