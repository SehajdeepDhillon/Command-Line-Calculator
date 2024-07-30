#include <stdio.h>
#include <math.h>
#include <ctype.h>
//clc.c
int main() {
    char Option;
    float Memory[5] = {0.00, 0.00, 0.00, 0.00, 0.00};  // Array to store memory slots 'a', 'b', 'c', 'd', 'e'.

    // Display welcome message and version information.
    printf("Welcome to my Command-Line Calculator (CLC)\n");
    printf("Version: Assignment 2\n");
    printf("Date: NOV-26-2023\n");

    // Enter a loop to continue until the user selects 'E'.
    while (Option != 'E') {
        // Display the menu for user selection.
        printf("Select one of the following items:\n");
        printf("B) - Binary Mathematical Operations, such as addition and subtraction.\n");
        printf("U) - Unary Mathematical Operations, such as square root and log.\n");
        printf("A) - Advanced Mathematical Operations, using variables, arrays.\n");
        printf("V) - Define variables and assign them values.\n");
        printf("E) - Exit\n");

        // Read the user's option.
        printf("Enter your choice (B/U/A/V/E): ");
        scanf(" %c", &Option);

        // Check if the entered option is a valid character.
        if ((Option >= 'A' && Option <= 'Z') || (Option >= 'a' && Option <= 'z')) {
            // Switch to the selected option.
            switch (Option) {
                case 'B':
                    // Create a loop for binary operations.
                    while (1) {
                        float FirstNumber, SecondNumber, Result; //Initalize variables
                        char Operation;

                        // Prompt the user for input.
                        printf("Please enter the first number: ");
                        scanf("%f", &FirstNumber);
                        printf("Please enter the operation (+, -, *, /, %%, P, X, I): ");
                        scanf(" %c", &Operation);
                        printf("Please enter the second number: ");
                        scanf("%f", &SecondNumber);

                        // Check if the operation is valid and perform the calculation.
                        switch (Operation) {
                            case '+':
                                Result = FirstNumber + SecondNumber;
                                break;
                            case '-':
                                Result = FirstNumber - SecondNumber;
                                break;
                            case '*':
                                Result = FirstNumber * SecondNumber;
                                break;
                            case '/':
                                // Check for division by zero.
                                if (SecondNumber != 0) {
                                    Result = FirstNumber / SecondNumber;
                                } else {
                                    // Handle division by zero by printing error statment.
                                    printf("Error: Division by zero is undefined.\n");
                                    continue;  // Repeat the loop.
                                }
                                break;
                            case '%':
                                Result = fmod(FirstNumber, SecondNumber);
                                break;
                            case 'P':
                                Result = pow(FirstNumber, SecondNumber);
                                break;
                            case 'X':
                                Result = fmax(FirstNumber, SecondNumber);
                                break;
                            case 'I':
                                Result = fmin(FirstNumber, SecondNumber);
                                break;
                            default:
                                // Print message for invalid operation.
                                printf("Invalid operation. Please try again.\n");
                                continue;  // Repeat the loop.
                        }

                        // Display the result.
                        printf("The result is %f\n", Result);
                        break;  // Exit the inner loop.
                    }  // End of inner loop
                    break;

                case 'U':
                    // Create a loop for unary operations.
                    while (1) {
                        float Num, Result; //Inatialize variables
                        char Operation;

                        // Prompt the user for input.
                        printf("Please enter the operation (S, L, E, C, F): ");
                        scanf(" %c", &Operation);
                        printf("Please enter the number: ");
                        scanf("%f", &Num);

                        // Check if the operation is valid and perform the calculation.
                        switch (Operation) {
                            case 'S':
                                Result = sqrt(Num);
                                break;
                            case 'L':
                                if (Num > 0) {
                                    Result = log(Num);
                                } else {
                                    // Handle invalid input for logarithm by printing error statment.
                                    printf("Error: Logarithm is undefined for non-positive numbers.\n");
                                    continue;  // Repeat the loop.
                                }
                                break;
                            case 'E':
                                Result = exp(Num);
                                break;
                            case 'C':
                                Result = ceil(Num);
                                break;
                            case 'F':
                                Result = floor(Num);
                                break;
                            default:
                                // Print message for invalid operation.
                                printf("Invalid operation. Please try again.\n");
                                continue;  // Repeat the loop.
                        }

                        // Display the result.
                        printf("The result is %f\n", Result);
                        break;  // Exit the inner loop.
                    }  // End of inner loop
                    break;

                case 'A':
                    // Create loop for advanced operations
                    char SubOption;
                    while (SubOption != 'E') {
                    // Display submenu for advanced operations.
                        printf("Select one of the following advanced items:\n");
                        printf("B) - Binary Operations with Variables\n");
                        printf("U) - Unary Operations with Variables\n");
                        printf("E) - Exit to Main Menu\n");

                     // Read the user's option.
                        printf("Enter your choice (B/U/E): ");
                        scanf(" %c", &SubOption);

                    // Check if the entered option is a valid character.
                        if ((SubOption >= 'A' && SubOption <= 'Z') || (SubOption >= 'a' && SubOption <= 'z')) {
                        // Switch to the selected advanced option.
                            switch (SubOption) {
                                case 'B':
                                    while (1) { // Create loop to within B.
                                        float FirstNumber, SecondNumber, Result;
                                        char Operation;
                                        char input;
                                        char inputSec;  // Variable to determine if the input is a variable or a number.

                                        // Prompt the user for input.
                                        printf("Please enter the first number or variable (memory slot): ");

                                        if (scanf("%f", &FirstNumber) == 1){  // Cheking if input was a numerical value

                                            }
                                        else if (scanf(" %c", &input) == 1) { // Checking if input was a charcter
                                            switch (input) { //Asigning variable to memory slots
                                                case 'A':
                                                case 'a':
                                                    FirstNumber = Memory[0];
                                                    break;
                                                case 'B':
                                                case 'b':
                                                    FirstNumber = Memory[1];
                                                    break;
                                                case 'C':
                                                case 'c':
                                                    FirstNumber = Memory[2];
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    FirstNumber = Memory[3];
                                                    break;
                                                case 'E':
                                                case 'e':
                                                    FirstNumber = Memory[4];
                                                    break;
                                                default: 
                                                    printf("Invalid operation. Please try again.\n");
                                                    continue;
                                            }getchar();  // Removing buffer
                                        } else {
                                        printf("Invalid input. Try again\n");  //Invalid input statment
                                        continue;
                                        }

                                        printf("Please enter the operation (+, -, *, /, %%, P, X, I): ");
                                        scanf(" %c", &Operation);  //geting operation selection from user
                                        getchar(); //Removing buffer

                                        printf("Please enter the second number or variable (memory slot): "); //Prompting user 
                        
                                        if (scanf("%f", &SecondNumber) == 1){ // Checking if second number is a numerical value
                    
                                        }
                                        else if (scanf(" %c", &inputSec) == 1) { // checking if second number is a character
                                            //if (inputSec >= 'a' && inputSec <= 'e')
                                            //else break;
                                            //Memory[tolower(inputSec) - 'a']
                                            switch(inputSec){  // Assigning second number to memory slots
                                                case 'A':
                                                case 'a':
                                                    SecondNumber = Memory[0];
                                                    break;
                                                case 'B':
                                                case 'b':
                                                    SecondNumber = Memory[1];
                                                    break;
                                                case 'C':
                                                case 'c':
                                                    SecondNumber = Memory[2];
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    SecondNumber = Memory[3];
                                                    break;
                                                case 'E':
                                                case 'e':
                                                    SecondNumber = Memory[4];
                                                    break;
                                                default: 
                                                    printf("Invalid operation. Please try again.\n");
                                                    continue;
                                            }getchar(); // Removing buffer
                                        }
                                        else {
                                        printf("Invalid input. Try again\n"); //Invalid statement
                                        continue; //Repeat loop
                                        }

                                        switch (Operation) { //Switching to operation and performing calculations.
                                        case '+':
                                            Result = FirstNumber + SecondNumber;
                                            break;
                                        case '-':
                                            Result = FirstNumber - SecondNumber;
                                            break;
                                        case '*':
                                            Result = FirstNumber * SecondNumber;
                                            break;
                                        case '/':
                                            // Check for division by zero.
                                            if (SecondNumber != 0) {
                                                    Result = FirstNumber / SecondNumber;
                                                } 
                                            else {
                                                // Handle division by zero buy outputing error.
                                                printf("Error: Division by zero is undefined.\n");
                                                continue;  // Repeat the loop.
                                                }
                                            break;
                                        case '%':
                                            Result = fmod(FirstNumber, SecondNumber);
                                            break;
                                        case 'P':
                                            Result = pow(FirstNumber, SecondNumber);
                                            break;
                                        case 'X':
                                            Result = fmax(FirstNumber, SecondNumber);
                                            break;
                                        case 'I':
                                            Result = fmin(FirstNumber, SecondNumber);
                                            break;
                                        default:
                                            // Print message for invalid operation.
                                            printf("Invalid operation. Please try again.\n");
                                            continue;  // Repeat the loop.
                                        }

                                        // Display the result.
                                        printf("The result is %f\n", Result);
                                        break;  // Exit the inner loop.
                                    }  // End of inner loop
                                    break;

                                case 'U':
                                    while (1) { // Create loop for U
                                        float Num, Result; //Inatialize variables
                                        char Operation;
                                        char inputthe;

                                        // Prompt the user for input.
                                        printf("Please enter the operation (S, L, E, C, F): ");
                                        scanf(" %c", &Operation);
                                        getchar(); // Remove buffer
                                        printf("Please enter the number or variable (memory slot):: "); //Prompting user for value
                                        if (scanf("%f", &Num) == 1){ // Checking if user inputed a numerical value

                                            }
                                        else if (scanf(" %c", &inputthe) == 1) { //checking if user inputer a charcter value
                                            switch(inputthe){ // assigning Num to memory slots
                                                case 'A':
                                                case 'a':
                                                    Num = Memory[0];
                                                    break;
                                                case 'B':
                                                case 'b':
                                                    Num = Memory[1];
                                                    break;
                                                case 'C':
                                                case 'c':
                                                    Num = Memory[2];
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    Num = Memory[3];
                                                    break;
                                                case 'E':
                                                case 'e':
                                                    Num = Memory[4];
                                                    break;
                                                default: 
                                                    printf("Invalid operation. Please try again.\n");
                                                    continue;
                                            }getchar(); // Removing buffer
                                        }
                                     

                                        // Check if the operation is valid and perform the calculation.
                                        switch (Operation) {
                                            case 'S':
                                                Result = sqrt(Num);
                                                break;
                                            case 'L':
                                                if (Num > 0) {
                                                    Result = log(Num);
                                                }
                                                else {
                                                    // Handle invalid input for logarithm by outputing error.
                                                    printf("Error: Logarithm is undefined for non-positive numbers.\n");
                                                    continue;  // Repeat the loop.
                                                }
                                                break;
                                            case 'E':
                                                Result = exp(Num);
                                                break;
                                            case 'C':
                                                Result = ceil(Num);
                                                break;
                                            case 'F':
                                                Result = floor(Num);
                                                break;
                                            default:
                                                // Print message for invalid operation.
                                                printf("Invalid operation. Please try again.\n");
                                                continue;  // Repeat the loop.
                                        }

                                        // Display the result.
                                        printf("The result is %f\n", Result);
                                        break;  // Exit the inner loop.
                                    }  // End of inner loop
                                
                                case 'E':
                                    break; //empty but then this will case outer loop to exit and display print statment

                                default:
                                    // Print message for invalid option.
                                    printf("Invalid option. Please select a valid option (B, U, E).\n");
                                    continue; //break?
                            }
                        } 
                        else {
                            // Print message for invalid input (not a character).
                            printf("Invalid input. Please enter a valid option (B, U, E).\n");
                            // Consume the invalid input to avoid an infinite loop.
                            while (getchar() != '\n');
                        }
                    }  // End of outer loop
                    break;

                case 'V':
                    // Create a loop for variable memory.
                    while (1) { 
                        char MemorySlot; // Inatalize variables
                        float Value;

                        // Prompt the user for input.
                        printf("Please enter the memory slot (a/b/c/d/e): ");
                        scanf(" %c", &MemorySlot);

                        // Check if the entered memory slot is valid.
                        if ((MemorySlot >= 'a' && MemorySlot <= 'e') || (MemorySlot >= 'A' && MemorySlot <= 'E')) {
                            printf("Please enter the floating-point value to save in memory slot %c: ", MemorySlot);
                            
                            // Check if the value entered is a number.
                            if (scanf("%f", &Value) != 1) {
                                // Print message for invalid input (number not entered).
                                printf("Invalid input. Please enter a valid floating-point value.\n");
                                // Consume the invalid input to avoid an infinite loop.
                                while (getchar() != '\n');
                                continue;  // Repeat the loop.
                            }

                            // Save the value in the selected memory slot.
                            if (MemorySlot >= 'a' && MemorySlot <= 'e') {
                                Memory[MemorySlot - 'a'] = Value;
                            } else {
                                Memory[MemorySlot - 'A'] = Value;
                            }

                            printf("Value %f saved in memory slot %c\n", Value, MemorySlot); // confirmation statment
                            break;  // Exit the inner loop.
                        } else {
                            // Print message for invalid memory slot.
                            printf("Invalid memory slot. Please try again.\n");
                            continue;  // Repeat the loop.
                        }
                    }  // End of inner loop
                    break;

                case 'E':
                    break; //empty but then this will case outer loop to exit and display print statment

                default:
                    // Print message for invalid option.
                    printf("Invalid option. Please select a valid option (B, U, A, V, E).\n");
                    break;
            }  // End of switch
        } else {
            // Print message for invalid input (not a character).
            printf("Invalid input. Please enter a valid option (B, U, A, V, E).\n");
            // Consume the invalid input to avoid an infinite loop.
            while (getchar() != '\n');
        }
    }  // End of loop

    // Display a thank you message.
    printf("Thanks for using my Simple Calculator. Hope to see you soon again, Goodbye!\n");

    return 0;
}  // End