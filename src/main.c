#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes for various operations
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
void convert_temperature();
void start_timer();
void organize(const char *directory);
void list_files(const char *path);

int main(int argc, char *argv[]) {
    int choice;

    // Display a welcome message and a banner for the application
    printf("\nWelcome to ToshTools!\n");
    printf(" _____         _   _____           _     \n");
    printf("|_   _|__  ___| |_|_   _|__   ___ | |___ \n");
    printf("  | |/ _ \\/ __| '_ \\| |/ _ \\ / _ \\| / __|\n");
    printf("  | | (_) \\__ \\ | | | | (_) | (_) | \\__ \\\n");
    printf("  |_|\\___/|___/_| |_|_|\\___/ \\___/|_|___/\n\n");

    // Display the main menu with options
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
    printf("11. Purple Theme\n");
    printf("12. Light Theme\n");
    printf("13. Dark Theme\n");
    printf("14. Unit Converter\n");
    printf("15. Timer\n");
    printf("16. File Manager\n");
    printf("17. File Finder\n");
    printf("20. Exit\n");

    // Start an infinite loop to keep the program running
    while (1) {
        // Prompt user for an option
        printf("\nPlease choose an option, or select [0] for the list of options:\n");
        scanf("%d", &choice);

        // Process user's choice
        switch (choice) {
            case 0:
                // Display menu again if user selects 0
                printf("\n1.  Alarm Clock\n");
                printf("2.  Calculator\n");
                printf("3.  Currency Converter\n");
                printf("4.  Add Note\n");
                printf("5.  View Notes\n");
                printf("6.  Delete Note\n");
                printf("7.  Add a task\n");
                printf("8.  View tasks\n");
                printf("9.  Delete a task\n");
                printf("10. Mark task as complete\n");
                printf("11. Purple Theme\n");
                printf("12. Light Theme\n");
                printf("13. Dark Theme\n");
                printf("14. Unit Converter\n");
                printf("15. Timer\n");
                printf("16. File Manager\n");
                printf("17. File Finder\n");
                printf("20. Exit\n");
                break;
            case 1:
                // Call function to set an alarm
                setAlarm(); 
                break;
            case 2:
                // Call function to run the calculator
                runCalculator(); 
                break;
            case 3:
                // Call function for currency conversion
                runCurrencyConverter();
                break;
            case 4:
                // Call function to add a note
                add_note();
                break;
            case 5:
                // Call function to view notes
                view_notes();
                break;
            case 6:
                // Call function to delete a note
                delete_note();
                break;  
            case 7:
                // Call function to add a task
                add_task();
                break;
            case 8:
                // Call function to view tasks
                view_tasks();
                break;  
            case 9:
                // Call function to delete a task
                delete_task();
                break;
            case 10:
                // Call function to mark a task as complete
                mark_task_completed();
                break;
            case 11:
                // Call function to apply teal and purple theme
                apply_teal_purple_theme();
                break;
            case 12:
                // Call function to apply light theme
                apply_light_theme();
                break;
            case 13:
                // Call function to apply dark theme
                apply_dark_theme();
                break;
            case 14:
                // Call function to convert temperature
                convert_temperature();
                break;
            case 15:
                // Call function to start a timer
                start_timer();
                break;
            case 16:
                // Function to organize files in a directory
                char directory[1024];

                // Get the directory path from user
                printf("\nEnter the path of the folder you want to organize...");
                printf("\nIt will sort files into categories like Audio, Documents, and Images: ");
                scanf("%s", directory);

                // Organize the files based on their types
                organize(directory);

                // Notify the user that the organization is complete
                printf("\nFile organization complete!\n");
                break;
            
            case 17:
                // Function to list files in a directory
                char path[1024];

                // Get the path for listing files
                printf("\nEnter the location to list files: ");
                scanf("%1023s", path);  // Take input for the location

                // List the files in the specified directory
                list_files(path); 
                break;

            case 20:
                // Exit the program
                printf("\nExiting the program...\n\n");
                return 0; // Exits the program
            default:
                // Handle invalid choices
                printf("\nInvalid option. Please try again.\n");
        }
    }

    return 0;
}




