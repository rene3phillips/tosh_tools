#include <stdio.h>

// Function to Run Calculator 
void runCalculator() {
    int num1, num2, result;  
    char operator;          
    char exitChoice;         

    // Keep Calculator Running
    while (1) {

        // Program Title and Prompt User to Input Math Expression
        printf("\n--- Calculator ---\n");
        printf("\nEnter a simple calculation (e.g., 3 + 4) or 'q' to quit: ");
        
        // Read User Input
        int validInput = scanf("%d %c %d", &num1, &operator, &num2);

        // Invalid Input
        if (validInput != 3) {
        
            scanf("%c", &exitChoice); 

            // Check if the User wants to Quit
            if (exitChoice == 'q' || exitChoice == 'Q') {
                printf("Exiting calculator...\n");
                return; // Exit Program
            } else {
                printf("Invalid input. Please try again.\n");
                continue; // Continue Program
            }
        }

        // Perform Calculation
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
                if (num2 != 0) {
                    result = num1 / num2;  // Division
                    printf("Result: %d\n", result);
                } else {
                    printf("Error: Division by zero!\n");  // Dividing by Zero Error
                }
                break;
            default:
                printf("Error: Invalid operator!\n");  // Invalid Operator Error
                break;
        }

        // Prompt User for Another Calculation
        printf("\nWould you like to perform another calculation? (y/n): ");
        scanf(" %c", &exitChoice);  // space before %c to consume any leftover newline character

        // Check if the User wants to Quit
        if (exitChoice == 'n' || exitChoice == 'N') {
            return;  // End Program
        }
    }
}