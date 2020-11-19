
// 


// Specification file for the FuelGauge class
#ifndef FUELGAUGE_H
#define FUELGAUGE_H


#include <iostream>
#include "Odometer.h"   // Necessary for friend function
using namespace std;	// Defines the scope, so there's no need to prefix with std::


// FuelGauge class declaration

class FuelGauge
{
    private:
        int fuel = 0;             // To hold the current amount of fuel, in gallons
        
    public:
        const int maxFuel = 15;   // To hold the maximum amount of fuel the tank can hold

        // Accessors:
        int getFuelLevel() const  
        {
            return fuel;
        }

        // Member Functions:
        void addFuel();       
        void burnFuel();      

        // Friend function 
        friend void Odometer::milesPerGallon(FuelGauge &);
};

#endif