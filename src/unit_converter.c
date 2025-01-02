// unit_converter.c
#include <stdio.h>

// Function to convert temperature
void convert_temperature() {
    int choice;  // Variable to store the user's choice (conversion type)
    float value, result;  // Variables to store the input value and the result of the conversion

    // Displaying the temperature conversion options
    printf("\n---Temperature Converter---\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);  // Taking the user's choice as input

    // Switch case to handle the conversion based on user's choice
    switch(choice) {
        case 1:  // Celsius to Fahrenheit conversion
            // Prompting the user to enter the value in Celsius
            printf("\nEnter the value (in Celsius) to convert: ");
            scanf("%f", &value);  // Taking the input value in Celsius

            // Converting Celsius to Fahrenheit using the formula
            result = (value * 9/5) + 32;

            // Displaying the result of the conversion
            printf("%.2f Celsius = %.2f Fahrenheit\n", value, result);
            break;

        case 2:  // Fahrenheit to Celsius conversion
            // Prompting the user to enter the value in Fahrenheit
            printf("\nEnter the value (in Fahrenheit) to convert: ");
            scanf("%f", &value);  // Taking the input value in Fahrenheit

            // Converting Fahrenheit to Celsius using the formula
            result = (value - 32) * 5/9;

            // Displaying the result of the conversion
            printf("%.2f Fahrenheit = %.2f Celsius\n", value, result);
            break;

        default:  // If the user enters an invalid choice
            printf("Invalid choice.\n");
    }
}
