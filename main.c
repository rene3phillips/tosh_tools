#include <stdio.h>
#include <stdlib.h>

// Function prototypes for the calculator and alarm clock
void setAlarm();
void runCalculator();
void runCurrencyConverter();
void add_note();
void view_notes();
void delete_note();
void add_task();
void view_tasks();
void delete_task();
void mark_task_completed();
void apply_teal_purple_theme();
void apply_light_theme();
void apply_dark_theme();

int main(int argc, char *argv[]) {
    int choice;

    // Display welcome message
    printf("Welcome to ToshTools!\n");

    // Get user choice
    while (1) {
        printf("Please choose an option:\n");
        printf("1.  Alarm Clock\n");
        printf("2.  Calculator\n");
        printf("3.  Currency Converter\n");
        printf("4.  Add Note\n");
        printf("5.  View Notes\n");
        printf("6.  Delete Note\n");
        printf("7.  Add a task\n");
        printf("8.  View tasks\n");
        printf("9.  Delete a task\n");
        printf("10. Mark task as complete\n");
        printf("11. Teal and Purple Theme\n");
        printf("12. Light Theme\n");
        printf("13. Dark Theme\n");
        printf("20. Exit\n");        
        scanf("%d", &choice);

        // Process the user's choice
        switch (choice) {
            case 1:
                setAlarm(); 
                break;
            case 2:
                runCalculator(); 
                break;
            case 3:
              runCurrencyConverter();
              break;
            case 4:
              add_note();
              break;
            case 5:
              view_notes();
              break;
            case 6:
              delete_note();
              break;  
            case 7:
              add_task();
              break;
            case 8:
              view_tasks();
              break;  
            case 9:
              delete_task();
              break;
            case 10:
              mark_task_completed();
              break;
            case 11:
              apply_teal_purple_theme();
              break;
            case 12:
              apply_light_theme();
              break;
            case 13:
              apply_dark_theme();
              break;
            
            case 20:
                printf("Exiting the program. Goodbye!\n");
                return 0; // Exit the program
            default:
                printf("Invalid choice. Please enter 1, 2, or 3.\n");
                break;
        }
    }

    return 0;
}



