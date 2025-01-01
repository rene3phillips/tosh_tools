// unit_converter.c
#include <stdio.h>

void convert_temperature() {
    int choice;
    float value, result;

    printf("\n---Temperature Converter---\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\nEnter the value (in Celcius) to convert: ");
            scanf("%f", &value);
            result = (value * 9/5) + 32;
            printf("%.2f Celsius = %.2f Fahrenheit\n", value, result);
            break;
        case 2:
            printf("\nEnter the value (in Fahrenheit) to convert: ");
            scanf("%f", &value);
            result = (value - 32) * 5/9;
            printf("%.2f Fahrenheit = %.2f Celsius\n", value, result);
            break;
        default:
            printf("Invalid choice.\n");
    }
}
