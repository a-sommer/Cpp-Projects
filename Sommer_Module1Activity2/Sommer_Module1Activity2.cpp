
// 


#include "Sommer_Module1Activity2.h"

using namespace std;

int main()
{
    const int SIZE = 101;   // To hold size of the array
    char password[SIZE];    // Create an array to hold user's input

    // Describe password requirements to user.
    cout << "The password requirements are as follows:\n"
         << "Passwords should be at least six characters long, have at least one uppercase and lowercase letter, \n"
         << "and at least one digit." << endl;

    // Prompt user for password.
    cout << "Please enter a password with no more than " << (SIZE - 1) << " characters: ";

    // Get user input.
    cin.getline(password, SIZE);

    // Call function to check whether the password entered meets the requirements.
    checkReqs(password);    
}
// checkReqs accepts a pointer to a c-string as an arg, and verifies whether the password
// meets all requirements, and displays the reason(s) if it does not.
void checkReqs(char* password)
{
    bool meetsMinLength = false,    // Flags to mark
               hasLower = false,    // whether or not
               hasUpper = false,    // password requirements
               hasDigit = false;    // have been met

    int length = strlen(password);  // To get length of array

    // If the password entered meets the minimum length requirements...
    if (length >= 6)
    {
        // ...set the corresponding flag to true.
        meetsMinLength = true;  
    }
    // Verify if the password meets the other criteria.
    for (int index = 0; index < length; index++)
    {
        // If the char at the index is a lowercase letter...
        if (islower(password[index]))
        {
            // ...set flag to true to indicate that requirement has been met.
            hasLower = true;
        }
        // If the char at the index is an uppercase letter...
        else if (isupper(password[index]))
        {
            // ...set flag to true to indicate that requirment has been met.
            hasUpper = true;
        }
        // If the char at index is a digit...
        else if (isdigit(password[index]))
        {
            //...set flag to true to indicate that requirment has been met.
            hasDigit = true;
        }

        // If all requirements have been met...
        if (hasLower && hasUpper && hasDigit)
        {
            // ...break out of for loop.
            break;
        }
    }

    // If all password requirements have been met, let the user know.
    if (meetsMinLength && hasDigit && hasLower && hasUpper)
    {
        cout << "\nThe password entered meets all requirements." << endl;
    }
    // The password did not meet requirements for some reason... 
    else 
    {
        //...print general message alerting user.
        cout << "\nThe password entered is invalid for the following reason(s):" << endl;

        /* Nested if blocks provide the specific reason(s) why the password did not meet requirements.*/
        // If the minimum password length was not met...
        if (!meetsMinLength)
        {
            // ...inform user how long passwords must be.
            cout << "Passwords must be at least six characters long." << endl;
        }
        // If no digits were included in the password...
        if (!hasDigit)
        {
            // ...remind user of requirments for digits.
            cout << "Passwords must have at least one digit." << endl;
        }
        // If there are no upper or lowercase letters...
        if (!hasLower || !hasUpper)
        {
            // ...remind user of password requirements.
            cout << "Passwords must have at least one uppercase and one lowercase letter." << endl;
        }
    }   
}

