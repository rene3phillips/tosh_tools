#include <stdio.h>

// Function to run the calculator
void runCalculator() {
    int num1, num2, result;
    char operator;
    char exitChoice;

    while (1) {
        // Display the calculator menu
        printf("\n--- Calculator ---\n");
        printf("Enter a simple calculation (e.g., 3 + 4) or 'q' to quit: ");
        int validInput = scanf("%d %c %d", &num1, &operator, &num2);

        if (validInput != 3) {
            // If input is invalid (i.e., user types 'q' or something non-numeric), check if it's exit command
            scanf("%c", &exitChoice); // to consume the leftover newline character
            if (exitChoice == 'q' || exitChoice == 'Q') {
                printf("Exiting calculator...\n");
                return; // Control returns back to main.c
            } 
            else {
                printf("Invalid input. Please try again.\n");
                continue;
            }
        }

        // Perform the calculation based on the operator
        switch (operator) {
            case '+':
                result = num1 + num2;
                printf("Result: %d\n", result);
                break;
            case '-':
                result = num1 - num2;
                printf("Result: %d\n", result);
                break;
            case '*':
                result = num1 * num2;
                printf("Result: %d\n", result);
                break;
            case '/':
                if (num2 != 0) {
                    result = num1 / num2;
                    printf("Result: %d\n", result);
                } else {
                    printf("Error: Division by zero!\n");
                }
                break;
            default:
                printf("Error: Invalid operator!\n");
                break;
        }

        // Ask user if they want to perform another calculation or quit
        printf("\nWould you like to perform another calculation? (y/n): ");
        scanf(" %c", &exitChoice); // space before %c is to consume any leftover newline character

        if (exitChoice == 'n' || exitChoice == 'N') {
            printf("Exiting calculator...\n");
            return; // Return control back to main menu
        }
    }
}
