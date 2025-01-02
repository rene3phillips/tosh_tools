#include <stdio.h>

// Function to run the currency converter
void runCurrencyConverter() {
    float amount, convertedAmount;  // Variables to store the input amount and the converted amount
    int choice;  // Variable to store the user's menu choice

    // Infinite loop to keep running the currency converter until the user chooses to exit
    while (1) {
        // Display the currency conversion options
        printf("\n--- Currency Converter ---\n");
        printf("1. USD to EUR\n");
        printf("2. EUR to USD\n");
        printf("3. Exit to Main Menu\n");
        printf("\nEnter your choice (1, 2, or 3): \n");
        
        // Read the user's choice
        scanf("%d", &choice);

        // If user chooses USD to EUR conversion
        if (choice == 1) {
            // Ask the user for the amount in USD
            printf("Enter amount in USD: $");
            scanf("%f", &amount);

            // Convert the amount to EUR using the conversion rate (example rate: 1 USD = 0.85 EUR)
            convertedAmount = amount * 0.85; 
            printf("Converted amount: %.2f EUR\n", convertedAmount);
        } 
        // If user chooses EUR to USD conversion
        else if (choice == 2) {
            // Ask the user for the amount in EUR
            printf("Enter amount in EUR: ");
            scanf("%f", &amount);

            // Convert the amount to USD using the conversion rate (example rate: 1 EUR = 1.18 USD)
            convertedAmount = amount * 1.18; 
            printf("Converted amount: %.2f USD\n", convertedAmount);
        } 
        // If user chooses to exit to the main menu
        else if (choice == 3) {
            printf("Exiting to Main Menu...\n");
            return; // Return control back to the main program
        } 
        // If the user enters an invalid choice
        else {
            printf("Invalid choice. Please enter 1, 2, or 3.\n");
        }
    }
}
