#include <stdio.h>

// Function to Run Currency Converter
void runCurrencyConverter() {
    float amount, convertedAmount;  
    int choice;  

    // Keep Currency Converter Running
    while (1) {

        // Program Title and Menu
        printf("\n--- Currency Converter ---\n");
        printf("\n1. USD to EUR\n");
        printf("2. EUR to USD\n");
        printf("3. Exit to Main Menu\n");
        printf("\nEnter your choice (1, 2, or 3): \n");
        
        // Read the User's Input
        scanf("%d", &choice);

        // USD to EUR 
        if (choice == 1) {

            // Input and Scan USD Amount
            printf("Enter amount in USD: $");
            scanf("%f", &amount);

            // Convert Amount to EUR
            convertedAmount = amount * 0.85; 
            printf("Converted amount: %.2f EUR\n", convertedAmount);
        } 

        // EUR to USD
        else if (choice == 2) {

            // Input and Scan EUR Amount
            printf("Enter amount in EUR: ");
            scanf("%f", &amount);

            // Convert Amount to USD
            convertedAmount = amount * 1.18; 
            printf("Converted amount: %.2f USD\n", convertedAmount);
        } 

        // Exit Program
        else if (choice == 3) {
            printf("Exiting to Main Menu...\n");
            return; 
        } 

        // Invalid Choice
        else {
            printf("Invalid choice. Please enter 1, 2, or 3.\n");
        }
    }
}