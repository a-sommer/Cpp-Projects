
// 


#include <iostream>
#include <string>
#include <iomanip>  // Formatting
#include <locale>   // Formatting

using namespace std;

struct MovieData     // Structure declaration
{
    string title,    // Movie title
        director;    // Director's name
    int releaseYear, // Year released
        runTime,     // Runtime (in minutes)
        costs,       // Production costs
        revenue;     // First year's revenue
 
};

// Function prototypes
void displayMovieInfo(const MovieData&);  // Arg passed by reference            

int main()
{
    MovieData horror, action;   // Define structure variables

    // Instantiate MovieData variables
    horror = { "A Quiet Place", "John Krasinski", 2018, 90, 17000000, 340949169 };
    action = { "John Wick", "Chad Stahelski", 2014, 101, 20000000, 86081711 };

    // Display to user
    cout << "\t\tMovie Information:\n" << endl;

    // Call function to display movie details
    displayMovieInfo(horror);

    // Prints out empty line for better legibility
    cout << endl;

    // Call function to display movie details
    displayMovieInfo(action);
}

/* displayMovieInfo accepts a MovieData structure type as an argument. The
 contents of the structure is displayed.*/
 // Since parameter is passed by reference, used const so that the argument
 // cannot be altered. Passing by value can make the program run more slowly.
void displayMovieInfo(const MovieData& movie)
{
    // Display movie info to user
    cout << setw(21) << "Title: " << movie.title << endl;
    cout << setw(21) << "Director: " << movie.director << endl;
    cout << setw(21) << "Year Released: " << movie.releaseYear << endl;
    cout << setw(21) << "Runtime: " << movie.runTime << " minutes" << endl;

    // Format output to include commas
    // https://www.cplusplus.com/forum/beginner/112656/
    cout.imbue(locale("en_US.utf8"));
    cout << setw(22) << "Production Costs: $" << movie.costs << " (estimated)" << endl;
    cout << setw(22) << "First-year revenue: $" << movie.revenue << endl;
}
