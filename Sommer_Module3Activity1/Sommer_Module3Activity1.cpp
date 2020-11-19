
// 


#include <iostream>
#include <fstream>
#include <string.h> // For strcpy_s

using namespace std;

// Set constants
const int QUARTERS = 4, NAME_SIZE = 6;

struct DivisionInfo         // Structure declaration
{
    char name[NAME_SIZE];   // Name of the region
    int quarter[QUARTERS];  // Quarter of the year
    double sales[QUARTERS]; // Quarterly sales
};

// Function prototypes
void getSalesFigures(DivisionInfo&);
void storeRecords(ofstream&, DivisionInfo&); 
bool openFile(ofstream&, string);

int main()
{
    DivisionInfo div_1, div_2, div_3, div_4;        // Define structure variable
    const string fileName = "DivisionRecords.dat";  // Hold file name
    ofstream records;                               // Create a file stream object

    // https://www.cplusplus.com/reference/cstring/strcpy/?kw=strcpy
    // https://en.cppreference.com/w/c/string/byte/strcpy
    // Since structures containing strings cannot be written to file because of
    // implicit pointers, must use character arrays with defined length.
    // strcpy_s writes the contents of a string into a character array
    strcpy_s(div_1.name, "East");
    strcpy_s(div_2.name, "West");
    strcpy_s(div_3.name, "North");
    strcpy_s(div_4.name, "South");

    // Verify and inform user if file opens successfully.
    if (openFile(records, fileName))
    {
        cout << "File opened successfully.\n" << endl;
    }
    // Inform user and terminate program if file could not be opened.
    else
    {
        cout << "File could not be opened. Aborting program.";
        return 0;   // Terminate program
    }
    
    // Call function to get sales' figures for each division.
    getSalesFigures(div_1);
    getSalesFigures(div_2);
    getSalesFigures(div_3);
    getSalesFigures(div_4);

    // Call function to write the contents of the division structures to the file.
    storeRecords(records, div_1);
    storeRecords(records, div_2);
    storeRecords(records, div_3);
    storeRecords(records, div_4);

    // Close the file
    records.close();
}
// getSalesFigures prompts user to enter the sales' figures for the specified division, 
// structure is passed by reference so changes are saved. 
void getSalesFigures(DivisionInfo &division)
{
    // Prompt user to enter the sales figure for the specified division.
    cout << "Enter the sales' figures for the " << division.name << " division. " << endl;
    
    double tempInput = 0;   // Initialize a temporary variable for user input

    // For each quarter...
    for (int index = 0; index < QUARTERS; index++)
    {
        // ...display which quarter to enter the sales' figures for...
        cout << "Quarter " << (index + 1) << ": ";

        // ... and validate user input.
        while (!(cin >> tempInput) || tempInput < 0)
        {
            // Display the error message to the user.
            cout << "\nError: Please enter a valid positive number for quarter " << (index + 1) << ": ";

            cin.clear();    // Clear the input buffer

            cin.ignore();   // Ignore last input. 
        }

        // Set the sales at index to user input. 
        division.sales[index] = tempInput; 

        // Set the quarter number for the current index.
        division.quarter[index] = (index + 1);
    }
}
// storeRecords uses a reference to a file stream object and a structure as arguments,
// and writes the data of the structure to the file. 
void storeRecords(ofstream& records, DivisionInfo& divInfo)
{
    // Write the data to the file, convert the address to a char pointer.
    records.write(reinterpret_cast<char*>(&divInfo), sizeof(divInfo));
}

// openFile takes a reference to a file stream object, and the file name and
// attempts to open the file. Returns true if file is opened successfully,
// or false if the file could not be opened. 
bool openFile(ofstream& file, string name)
{   
    // Open a file
    // Because structures can have mixed data types, use binary mode. 
    file.open(name, ios::out | ios:: binary);

    if (file.is_open()) // File opened successfully, return true
    {
        return true;
    }
    else                // File not opened, return false
    {
        return false;
    }
}
