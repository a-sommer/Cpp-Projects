
// 


// This program uses the Car class, which is declared in the Car.h file. The Car class's member 
// functions are defined in the Car.cpp file. This program must be compiled with those files in a project.

#include <iostream>     // Necessary for input/output operations
#include <string>       // Necessary for the string class
#include "Car.h"        // Necessary for car class
using namespace std;    // Define the scope, so there's no need to prefix with std::

int main()
{
    int carYear = 2017;             // Local variable for car's year model
    string carMake = "Honda";       // Local variable for car's make
    Car newCar(carYear, carMake);   // Instantiate an object of the car class

    cout << "Car object created.\n" << endl;  // Let user know a car object has been created
       
    cout << "Accelerating car..." << endl;    // Inform user that car will be accelerating     

    // Increase the speed of the car five times
    for (int count = 0; count < 5; count++)
    {
        newCar.accelerate();    // Call the accelerate funcion

        // Display the current speed to user after each speed change
        cout << newCar.getSpeed() << endl;
    }

    cout << "\nDecelerating car..." << endl;  // Inform user that car will be decelerating

    // Decrease the speed of the car five times
    for (int count = 0; count < 5; count++)
    {
        newCar.brake();   // Call the brake function
        
        // Display the current speed to the user after each speed change
        cout << newCar.getSpeed() << endl;
    }
}


