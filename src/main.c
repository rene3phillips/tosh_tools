#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Prototypes
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
void apply_purple_theme();
void apply_light_theme();
void apply_dark_theme();
void reset_theme();
void convert_temperature();
void start_timer();
void organize();
void list_files(const char *path);

int main(int argc, char *argv[]) {
    int choice;

    // Welcome Message 
    printf("\nWelcome to ToshTools!\n");
    printf(" _____         _   _____           _     \n");
    printf("|_   _|__  ___| |_|_   _|__   ___ | |___ \n");
    printf("  | |/ _ \\/ __| '_ \\| |/ _ \\ / _ \\| / __|\n");
    printf("  | | (_) \\__ \\ | | | | (_) | (_) | \\__ \\\n");
    printf("  |_|\\___/|___/_| |_|_|\\___/ \\___/|_|___/\n\n");

    // Main Menu
    printf("1.  Alarm Clock\n");
    printf("2.  Calculator\n");
    printf("3.  Currency Converter\n");
    printf("4.  File Finder\n");
    printf("5.  File Manager\n");
    printf("6.  Add Note\n");
    printf("7.  View Notes\n");
    printf("8.  Delete Note\n");
    printf("9.  Add a task\n");
    printf("10. View tasks\n");
    printf("11. Delete a task\n");
    printf("12. Mark task as complete\n");
    printf("13. Dark Theme\n");
    printf("14. Light Theme\n");
    printf("15. Purple Theme\n");
    printf("16. Reset Theme\n");
    printf("17. Timer\n");
    printf("20. Exit\n");

    // Keep the Program Running
    while (1) {

        // Prompt User for Option
        printf("\nPlease choose an option, or select [0] for the list of options:\n");
        scanf("%d", &choice);

        // Process User's Choice
        switch (choice) {
            case 0:
                // Display Menu
                printf("1.  Alarm Clock\n");
                printf("2.  Calculator\n");
                printf("3.  Currency Converter\n");
                printf("4.  File Finder\n");
                printf("5.  File Manager\n");
                printf("6.  Add Note\n");
                printf("7.  View Notes\n");
                printf("8.  Delete Note\n");
                printf("9.  Add a task\n");
                printf("10. View tasks\n");
                printf("11. Delete a task\n");
                printf("12. Mark task as complete\n");
                printf("13. Dark Theme\n");
                printf("14. Light Theme\n");
                printf("15. Purple Theme\n");
                printf("16. Reset Theme\n");
                printf("17. Timer\n");
                printf("20. Exit\n");
                break;
            case 1:
                // Call Function to Set Alarm
                setAlarm(); 
                break;
            case 2:
                // Call Function to Run the Calculator
                runCalculator(); 
                break;
            case 3:
                // Call Function to Run Currency Converter
                runCurrencyConverter();
                break;
            case 4:
                char path[1024];
                
                // Project Title
                printf("\n--- File Finder ---\n");

                // Prompt User for File Path
                printf("\nEnter the location to list files: ");
                scanf("%1023s", path);  

                // Call Function to List Files
                list_files(path); 

                break;
            case 5:
                // Call Function to Organize Files
                organize();
                break;
            case 6:
                // Call Function to Add Note
                add_note();
                break;  
            case 7:
                // Call Function to View Notes
                view_notes();
                break;
            case 8:
                // Call Function to Delete Note
                delete_note();
                break;  
            case 9:
                // Call Function to Add Task
                add_task();
                break;
            case 10:
                // Call Function to View Tasks
                view_tasks();
                break;
            case 11:
                // Call Function to Delete Task
                delete_task();
                break;
            case 12:
                // Call Funciton to Mark Task as Complete
                mark_task_completed();
                break;
            case 13:
                // Call Function to Apply Dark Theme
                apply_dark_theme();
                break;
            case 14:
                // Call Function to Apply Light Theme
                apply_light_theme();
                break;
            case 15:
                // Call Function to Apply Purple Theme
                apply_purple_theme();
                break;
            case 16:
                // Call Function to Reset Theme
                reset_theme();
                break;
            case 17:
                // Call Function to Set Timer
                start_timer(); 
                break;
                
            case 20:
                // Exit Program
                printf("\nExiting the program...\n\n");
                return 0; 

            default:
                // Invalid Choice
                printf("\nInvalid option. Please try again.\n");
        }
    }

    return 0;
}




