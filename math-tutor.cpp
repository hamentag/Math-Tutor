#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int main()
{
    // Constants for the menu choices
    const int ADDITION = 1,
              SUBTRACTION = 2,  
              MULTIPLLICATION = 3,
              DIVISION = 4,
              QUIT = 5;

    // Variables
    int choice,    // to hold menu choice
        num1,      // To hold number 1
        num2;      // To hold number 2

    // Display the menu
        cout << "\n\tMath Tutor Menu\n"
             << "------------------------------\n"
             << "1. Addition\n"
             << "2. Subtraction\n"
             << "3. Multiplication\n"
             << "4. Division\n"
             << "5. Quit the program\n"
             << "Enter your choice: ";
        cin >> choice;
        if(choice < 1 || choice > 5){
            cout << "Invalid choice!" << endl;
        }
        else if(choice == 5){
            cout << "You quit... ";
        }
        else{
            // Get the system time
            unsigned seed = time(0);

            // Seed the random number generator
            srand(seed);
            num1 = rand();
            num2 = rand();
            cout << "num1 = " << num1 << endl;
            cout << "num2 = " << num2 << endl;
        }
        
    return 0;      
}