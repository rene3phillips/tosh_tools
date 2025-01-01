#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    // Display welcome message
    printf("\nWelcome to ToshTools!\n");
    printf(" _____         _   _____           _     \n");
    printf("|_   _|__  ___| |_|_   _|__   ___ | |___ \n");
    printf("  | |/ _ \\/ __| '_ \\| |/ _ \\ / _ \\| / __|\n");
    printf("  | | (_) \\__ \\ | | | | (_) | (_) | \\__ \\\n");
    printf("  |_|\\___/|___/_| |_|_|\\___/ \\___/|_|___/\n\n");


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
    printf("14. Unit Converter\n");
    printf("15. Timer\n");
    printf("16. File Manager\n");
    printf("17. File Finder\n");
    printf("20. Exit\n"); 

    // Get user choice
    while (1) {
        printf("\nPlease choose an option, or select [0] for the list of options:\n");    
        scanf("%d", &choice);

        // Process the user's choice
        switch (choice) {
            case 0:
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
                printf("11. Teal and Purple Theme\n");
                printf("12. Light Theme\n");
                printf("13. Dark Theme\n");
                printf("14. Unit Converter\n");
                printf("15. Timer\n");
                printf("16. File Manager\n");
                printf("17. File Finder\n");
                printf("20. Exit\n"); 
                break;
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
            case 14:
              convert_temperature();
              break;
            case 15:
              start_timer();
              break;
            case 16:
              char directory[1024];

              // Get the directory to organize
              printf("\nEnter the path of the folder you want to organize...");
              printf("\nIt will sort files into categories like Audio, Documents, and Images: ");
              scanf("%s", directory);

              organize(directory);

              printf("\nFile organization complete!\n");
              break;
            
            case 17:
              char path[1024];  // Variable to store the user input for location

              // Ask the user for the location (path)
              printf("\nEnter the location to list files: ");
              scanf("%1023s", path);  // Take input for the location

              list_files(path); // Call the function to list files
              break;



            case 20:
              printf("\nExiting the program...\n\n");
              return 0; // Exits the program
              break;
            default:
                printf("\nInvalid option. Please try again.\n");
        }
    }

    return 0;
}



