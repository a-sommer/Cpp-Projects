
// 


#include <iostream>
#include <fstream>
#include <iomanip>  // Formatting output
#include <locale>   // Formatting financial information

using namespace std;

// Set constants
const int QUARTERS = 4, NAME_SIZE = 6, NUM_OF_DIV = 4;

struct DivisionInfo             // Structure declaration
{
    char name[NAME_SIZE];       // Name of the region
    int quarter[QUARTERS];      // Quarter of the year
    double sales[QUARTERS];     // Quarterly sales
};

struct SalesInfo                                         // Structure declaration
{
    string regions[NUM_OF_DIV];                          // Region names
    double totalCorporateSales_PerQuarter[QUARTERS];     // Total sales per quarter
    double totalYearlySales_PerDivision[NUM_OF_DIV];     // Total yearly sales per division
    double totalYearlySales_Corporate;                   // Total yearly corporate sales
    double avgQuarterlySales_PerDivision[NUM_OF_DIV];    // Average quarterly sales per division
    int highestSalesQuarter;                             // Quarter with the highest corporate sales
    int lowestSalesQuarter;                              // Quarter with the lowest corporate sales 
};

// Function prototypes
SalesInfo calculateTotals(DivisionInfo[]);
void calculateAvgQuarterlySales(SalesInfo&);
void displaySalesInfo(const SalesInfo&);
void findHighestLowest(SalesInfo&);


int main()
{
    DivisionInfo divisions[NUM_OF_DIV]; // Declare an array of structs
    
    SalesInfo lastYear; // Declare a struct

    // Create file stream object
    // Use ifstream because only reading from file, so it'll be faster than using fstream
    ifstream records; 

    // Open the file for input in binary mode
    records.open("DivisionRecords.dat", ios::in | ios::binary);

    // Aborts program if file cannot be opened.
    if (records.fail())
    {
        // Display to user.
        cout << "Error: File could not be opened. Aborting program." << endl;
        
        return 0; // Terminate program
    }

    // Read file
    records.read(reinterpret_cast<char*>(&divisions), sizeof(divisions));

    // Call function to calculate the totals for the previous year
    lastYear = calculateTotals(divisions);

    // Call function to calculate the average quarterly sales
    calculateAvgQuarterlySales(lastYear);

    // Call function to find the quarters with the highest and lowest corporate sales
    findHighestLowest(lastYear);

    // Display the year's sales information to the user
    displaySalesInfo(lastYear);

    // Close the file
    records.close();
}
// calculateTotals takes a struct as an argument, and calculates the total corporate sales per quarter,
// yearly sales for each division, and yearly corporate sales.
SalesInfo calculateTotals(DivisionInfo divisions[])
{
    // Initialize a temporary struct
    // Must initialize to allocate memory for the struct
    // If not, results don't display properly
    // https://stackoverflow.com/questions/5914422/proper-way-to-initialize-c-structs
    SalesInfo tempInfo = SalesInfo(); 

    // For each division...  
    for (int i = 0; i < NUM_OF_DIV; i++)
    {
        // ...set region name in temp struct to the division's name from DivisionInfo struct
        tempInfo.regions[i] = divisions[i].name;

        // ...and for each quarter...
        for (int j = 0; j < QUARTERS; j++)
        {
            // ...add divisions' sales numbers to totals.
            tempInfo.totalYearlySales_Corporate += divisions[i].sales[j];
            tempInfo.totalYearlySales_PerDivision[i] += divisions[i].sales[j];
            tempInfo.totalCorporateSales_PerQuarter[j] += divisions[i].sales[j];
        }
    }
    return tempInfo;    // Return the struct to caller
}

// calculateAvgQuarterlySales takes a SalesInfo struct (passed by reference), and
// calculates the average quarterly sales for each division.
void calculateAvgQuarterlySales(SalesInfo& refSales)   
{
    // For each division...
    for (int i = 0; i < NUM_OF_DIV; i++)
    {
        //...calculate average quarterly sales.
        refSales.avgQuarterlySales_PerDivision[i] = (refSales.totalYearlySales_PerDivision[i] / QUARTERS);
    }    
}
// findHighestLowest finds the quarters with the highest and lowest corporate sales
// and saves them to the reference parameter refSales.
void findHighestLowest(SalesInfo& refSales)
{
    // Initially set highest and lowest sales quarter to index 0
    refSales.highestSalesQuarter = 0;
    refSales.lowestSalesQuarter = 0;

    // For each quarter...
    for (int i = 1; i < QUARTERS; i++)
    {
        // ...if the value at the index is less than the current lowest...
        if (refSales.totalCorporateSales_PerQuarter[i] < refSales.totalCorporateSales_PerQuarter[refSales.lowestSalesQuarter])
        {
            // ...set lowest index to current index.
            refSales.lowestSalesQuarter = i;
        }
        // ...or if the value at the index is greater than the current highest...
        if (refSales.totalCorporateSales_PerQuarter[i] > refSales.totalCorporateSales_PerQuarter[refSales.highestSalesQuarter])
        {
            // ...set highest index to current index.
            refSales.highestSalesQuarter = i;
        }    
    }
}
// displaySalesInfo takes a SalesInfo struct and displays the relevant information to the user.
// Set as a constant so data cannot be manipulated.
void displaySalesInfo(const SalesInfo& year)
{
    // Display to user
    cout << "\t\tDisplaying Sales Information for the Year:\n" << endl;

    // Adds comma to sales' figures as appropriate
    cout.imbue(locale("en_US.utf8"));

    // Display monetary amounts with 2 decimal places
    cout << setprecision(2) << fixed;

    // Display total sales to user, highest/lowest quarters
    // Add 1 to highest/lowest quarters to convert from index to the corresponding quarter
    cout << "Total sales: " << "$" << year.totalYearlySales_Corporate 
         << "\tHighest Quarter: " << (year.highestSalesQuarter + 1) 
         << "\tLowest Quarter: " << (year.lowestSalesQuarter + 1) << endl;

    // Display to user
    cout << "\nTotal sales per quarter:" << endl;

    // Cycles through the quarters and displays total sales
    for (int i = 0; i < QUARTERS; i++)
    {
        // Add 1 to the index to convert to the corresponding quarter
        cout << "Quarter " << (i + 1) << ": " << "$" << year.totalCorporateSales_PerQuarter[i] << "\n";
    }

    // Display total sales per division to user
    cout << setw(42) << "\n\nTotal sales per division: " << endl;
    // Cycles through and prints the region and yearly sales for that region
    for (int i = 0; i < NUM_OF_DIV; i++)
    {
        cout << left << setw(NAME_SIZE) << year.regions[i] << ": " << "$" << year.totalYearlySales_PerDivision[i] << "\n";
    }
   
    // Display the average quarterly sales per division
    cout << setw(42) << "\n\nAverage quarterly sales per division: " << endl;

    // For each division... 
    for (int i = 0; i < NUM_OF_DIV; i++)
    {
        // ...print the division's name and it's average quarterly sales.
        cout << left << setw(NAME_SIZE) << year.regions[i] << ": " << "$" << year.avgQuarterlySales_PerDivision[i] << "\n";
    }   

    // Add spacing for legibility
    cout << endl;
}