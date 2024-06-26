// This program can be used as a math tutor for a young student. 
// He choose the arithmetic operation, then the program displays 
// two random numbers to operate, pause while the student gives 
// their answer, then it displays the correct answer.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <limits> 
using namespace std;

int getInteger();

int main()
{
    // Constants for the menu choices
    const int ADDITION = 1,
              SUBTRACTION = 2,  
              MULTIPLLICATION =3,
              DIVISION = 4,
              QUIT = 5;

    // Variables
    int choice,    // to hold menu choice
        num1,      // To hold number 1
        num2;      // To hold number 2

    char sign;     // to hold the sign

    do
    {
        // Display the menu
        cout << "\n\tMath Tutor Menu\n"
             << "------------------------------\n"
             << "1. Addition\n"
             << "2. Subtraction\n"
             << "3. Multiplication\n"
             << "4. Division\n"
             << "5. Quit the program\n"
             << "Enter your choice: ";
        choice = getInteger();

        // Validate the menu select 
        while (choice < ADDITION || choice > QUIT)   
        {
            cout << "Please enter a valid choice: ";
            choice = getInteger();
        } 

        // Process the student's choice
        if (choice != QUIT) 
        {
            // Get the system time
            unsigned seed = time(0);

            // Seed the random number generator
            srand(seed);
            num1 = rand();
            num2 = rand();

            if (choice != DIVISION)
            {   // Cases: Addition, Subtraction, and Multiplication
                int result,    // To hold result
                    answer;    // To hold the answer

                switch (choice)
                {
                    case ADDITION:
                        result = num1 + num2;
                        sign = '+';
                        break;
                    case SUBTRACTION:
                        result = num1 - num2;
                        sign = '-';
                        break;
                    case MULTIPLLICATION:
                        result = num1 * num2;
                        sign = 'x';
                        cout << setprecision(0) << fixed;
                        break;               
                }

                // Display the two numbers
                cout << "Solve the problem and enter your answer.\n\n";
                cout  << setw(7) << num1 << endl;
                cout  << sign << setw(6) << num2 << endl;
                cout <<"----------\n";

                // Get the answer
                answer = getInteger();

                // Check if the answer is correct
               if (answer == result)            
                cout << "Congratulations. Your answer is correct.\n\n";
               else
               {
                   cout << "\nIncorrect answer.\nSolution: \n\n"
                        << setw(8) << num1 << endl;
                   cout << sign << setw(7) << num2 << endl;
                   cout <<"----------\n"
                        << "=" << setw(7) << result << endl;
               }
            }
            else  // Case: Division
            {
                int remainder, quotient,        // To hold solutions
                    remainderAns, quotientAns;  // To hold the student's ansewrs

                // Calculate the quotient and remainder of the division
                quotient =  num1 / num2;
                remainder = num1 % num2;

                // Display the two numbers and get answers
                cout << "Solve the problem and enter your answers.\n\n";
                cout  << "\t" << setw(8) << num1 << endl; 
                cout  << "\t/" << setw(7) << num2 << endl;
                cout <<"\t----------\n"
                     << "Quotient : ";
                quotientAns = getInteger(); 
                cout << "Remainder: ";
                remainderAns = getInteger();

                // Check if the answers are corrects
               if (quotient == quotientAns && remainder == remainderAns)
                cout << "Congratulations. Your answer is correct.\n\n"; 
               else
               {
                   cout << "\nIncorrect answer.\nSolution: \n\n"
                        << "\t" << setw(8) << num1 << endl; 
                   cout  << "\t/" << setw(7) << num2 << endl;
                   cout <<"\t----------\n"
                        << "Quotient  = " << quotient
                        << "\nRemainder = " << remainder << endl;
               } 
            }
        }
    } while (choice != QUIT);
    return 0;      
}

int getInteger(){
 int answer;

    do {
        std::cin >> answer;

        // Check if the input is valid ( == integer)
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter an integer: ";
        } else {
            return answer;; // return the answer if the input is valid
        }
    } while (true);
}
