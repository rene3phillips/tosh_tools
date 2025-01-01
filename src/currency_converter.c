#include <stdio.h>

// Function to run the currency converter
void runCurrencyConverter() {
    float amount, convertedAmount;
    int choice;

    while (1) {
        // Display the currency conversion options
        printf("\n--- Currency Converter ---\n");
        printf("1. USD to EUR\n");
        printf("2. EUR to USD\n");
        printf("3. Exit to Main Menu\n");
        printf("\nEnter your choice (1, 2, or 3): \n");
        scanf("%d", &choice);

        if (choice == 1) {
            // USD to EUR conversion
            printf("Enter amount in USD: $");
            scanf("%f", &amount);
            convertedAmount = amount * 0.85; // Conversion rate (example)
            printf("Converted amount: %.2f EUR\n", convertedAmount);
        } 
        else if (choice == 2) {
            // EUR to USD conversion
            printf("Enter amount in EUR: ");
            scanf("%f", &amount);
            convertedAmount = amount * 1.18; // Conversion rate (example)
            printf("Converted amount: %.2f USD\n", convertedAmount);
        } 
        else if (choice == 3) {
            // Exit to Main Menu
            return; // Return control back to main.c
        } 
        else {
            printf("Invalid choice. Please enter 1, 2, or 3.\n");
        }
    }
}
