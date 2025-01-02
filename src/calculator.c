#include <stdio.h>

// Function to run the calculator
void runCalculator() {
    int num1, num2, result;  // Variables to store the two numbers and the result
    char operator;           // Variable to store the operator (+, -, *, /)
    char exitChoice;         // Variable to store user choice for quitting or continuing

    // Infinite loop to keep running the calculator until the user chooses to quit
    while (1) {
        // Display the calculator menu
        printf("\n--- Calculator ---\n");
        printf("Enter a simple calculation (e.g., 3 + 4) or 'q' to quit: ");
        
        // Read user input: two integers and an operator
        int validInput = scanf("%d %c %d", &num1, &operator, &num2);

        // If the input is invalid (e.g., the user types 'q' or something non-numeric)
        if (validInput != 3) {
            // Consume any leftover newline character from previous input
            scanf("%c", &exitChoice); 

            // Check if the user wants to quit the calculator
            if (exitChoice == 'q' || exitChoice == 'Q') {
                printf("Exiting calculator...\n");
                return; // Exit the calculator and return to main menu
            } else {
                printf("Invalid input. Please try again.\n");
                continue; // Continue asking for a valid calculation input
            }
        }

        // Perform the calculation based on the entered operator
        switch (operator) {
            case '+':
                result = num1 + num2;  // Addition
                printf("Result: %d\n", result);
                break;
            case '-':
                result = num1 - num2;  // Subtraction
                printf("Result: %d\n", result);
                break;
            case '*':
                result = num1 * num2;  // Multiplication
                printf("Result: %d\n", result);
                break;
            case '/':
                // Handle division, check for division by zero
                if (num2 != 0) {
                    result = num1 / num2;  // Division
                    printf("Result: %d\n", result);
                } else {
                    printf("Error: Division by zero!\n");  // Error if dividing by zero
                }
                break;
            default:
                printf("Error: Invalid operator!\n");  // Error if an invalid operator is entered
                break;
        }

        // Ask the user if they want to perform another calculation or quit
        printf("\nWould you like to perform another calculation? (y/n): ");
        scanf(" %c", &exitChoice);  // space before %c to consume any leftover newline character

        // If the user chooses to quit, exit the calculator
        if (exitChoice == 'n' || exitChoice == 'N') {
            return;  // Return control back to the main menu
        }
    }
}

