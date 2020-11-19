
// 


#include "Sommer_Module1Activity1.h"

using namespace std;

int main()
{
    const int SIZE = 101; // Size of the array
    char input[SIZE];     // To hold user's input
 
    int words = 0;        // To hold the # of words in user's input

    // Prompt user to input a string.
    cout << "Please enter a string with no more than " << (SIZE - 1) << " characters: " << endl;

    // Get user input.
    cin.getline(input, SIZE);
    
    // Pass user input to the function and get the total word count.
    words = getWordCount(input);
    
    // Display the number of words in the string to the user.
    cout << "\nThe string you entered had " << words << " word(s)." << endl;
}
// getWordCount accepts a pointer to a C-string as an arg, and returns the number of words contained in the string.
int getWordCount(char* cString)
{
    int wordCount = 0,          // To hold the word count
        size = strlen(cString); // To get length of array

    // Cycles through array
    for (int index = 0; index < size; index++)
    {
        // If the char at index is a white space or if the char at index + 1 is the null terminator...
        if (cString[index] == ' ' || cString[index + 1] == '\0')
        {
            // ...increment word count.
            wordCount++;
        }
    }
    // Returns the word count back to main().
    return wordCount;
}