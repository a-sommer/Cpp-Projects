
// 


// Specification file for the Car class
#ifndef CAR_H
#define CAR_H


#include <string>       // Necessary for the string class
using namespace std;    // Define the scope, so there's no need to prefix with std::

// Car class declaration

class Car
{
    private:
        int yearModel;    // Hold the car's year model
        string make;      // Hold the car's make
        int speed;        // Hold the car's current speed

    public:
        Car();            // Default constructor
        Car(int, string); // Constructor with parameters

        // Accessors
        int getYearModel() const
            { return yearModel; }
        string getMake() const
            { return make; }
        int getSpeed() const
            { return speed; }

        // Member functions
        void accelerate();
        void brake();
};

#endif