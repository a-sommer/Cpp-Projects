
// 


// Implementation file for the Car class.

#include <string>    // Necessary for the string class
#include "Car.h"	 // Necessary for the Car class
using namespace std; // Define the scope, so there's no need to prefix with std::

// The constructor accepts arguments for the car's year model and make.
Car::Car(int year, string brand)
{
    yearModel = year;
    make = brand;
    speed = 0;
}

// accelerate takes the speed of a car as an argument and adds 5 to it.
void Car::accelerate()
{
    speed += 5;
}

// brake takes the speed of a car as an argument and subtracts 5 from it.
void Car::brake()
{
    speed -= 5;
}