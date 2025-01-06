#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>  // For sleep() function

// Function to Set the Alarm 
void setAlarm() {

    int hour, minute;
    
    // Program Title 
    printf("\n--- Alarm Clock ---\n");
    
    // Prompt User to Input Alarm Time
    printf("\nEnter the alarm time (HH MM): ");
    
    // Clear Leftover Characters in the Terminal
    while (getchar() != '\n');  

    // Read User Input
    int result = scanf("%d %d", &hour, &minute);

    // Check if Time Entered is Valid
    if (result != 2 || hour < 0 || hour > 23 || minute < 0 || minute > 59) {
        printf("Invalid time entered. Please enter a valid time (HH MM).\n");
        return;
    }

    // Get Current Time
    time_t now;
    struct tm *timeinfo;
    char alarmTime[9]; 

    time(&now);  
    timeinfo = localtime(&now);  
    timeinfo->tm_hour = hour;  
    timeinfo->tm_min = minute;  
    timeinfo->tm_sec = 0;  

    now = mktime(timeinfo);
    
    // Format the Alarm Time as HH:MM:SS
    strftime(alarmTime, sizeof(alarmTime), "%H:%M:%S", timeinfo);

    // Print the Alarm Time
    printf("Alarm set for: %s\n", alarmTime);

    // Wait for the Alarm to "Trigger"
    while (1) {

        // Check the Current Time 
        time(&now);
        timeinfo = localtime(&now);
        
        // Store the Current Time
        char currentTime[9];  

        // Format the current time as HH:MM:SS
        strftime(currentTime, sizeof(currentTime), "%H:%M:%S", timeinfo);
        
        // Compare the Current Time with Alarm Time
        if (strcmp(currentTime, alarmTime) == 0) {
            printf("\nALARM! It's time to wake up!\n");
            break;  // Exit the Program
        }
        
        // Wait for 1 second before checking the time again
        sleep(1);
    }
}



