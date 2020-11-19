
// 


// Specification file for the Odometer class
#ifndef ODOMETER_H
#define ODOMETER_H

class FuelGauge;     // Forward declaration of FuelGauge class

using namespace std; // Defines the scope, so there's no need to prefix with std::

// Odometer class declaration

class Odometer
{
    private:
        int mileage = 0;                 // To hold the car's current mileage
        const int ODOMETER_MAX = 999999; // To hold the maximum amount of miles the odometer can store
        
    public:
        const int MPG = 24; // To hold the car's fuel economy (miles per gallon)

        // Accessor
        int getMileage() const
        {
            return mileage;
        }

        // Member functions:
        void addMileage(); 
        void milesPerGallon(FuelGauge&);       
};

#endif