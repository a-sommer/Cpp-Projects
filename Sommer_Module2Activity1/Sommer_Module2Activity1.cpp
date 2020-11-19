
// 


#include <iostream>
#include <string>
#include <iomanip> // Formatting

using namespace std;

struct MovieData     // Structure declaration
{
    string title,    // Movie title
           director; // Director's name
    int releaseYear, // Year released
        runTime;     // Runtime (in minutes)

};

// Function prototypes
void displayMovieInfo(const MovieData&);  // Arg passed by reference            

int main()
{
    MovieData horror, action;   // Define structure variables

    // Instantiate MovieData variables
    horror = { "A Quiet Place", "John Krasinski", 2018, 90 };   
    action = { "John Wick", "Chad Stahelski", 2014, 101 };

    // Display to user
    cout << "\tMovie Information:\n" << endl;   

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
void displayMovieInfo(const MovieData &movie)
{
    cout << setw(15) << "Title: " << movie.title << endl;
    cout << setw(15) << "Director: " << movie.director << endl;
    cout << setw(14) << "Year Released: " << movie.releaseYear << endl;
    cout << setw(15) << "Runtime: " << movie.runTime << " minutes" << endl;
}
