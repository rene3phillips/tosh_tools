#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>  // For sleep() function

// Function to set the alarm time
void setAlarm() {
    int hour, minute;
    
    printf("\n--- Alarm Clock ---\n");
    
    // Ask the user to input the alarm time (in HH MM format)
    printf("Enter the alarm time (HH MM): ");
    
    // Clear the input buffer to avoid leftover characters from previous inputs
    while (getchar() != '\n');  // This clears any leftover characters in the buffer

    // Read the user input for hour and minute
    int result = scanf("%d %d", &hour, &minute);

    // Check if the input is valid (hour between 0-23, minute between 0-59)
    if (result != 2 || hour < 0 || hour > 23 || minute < 0 || minute > 59) {
        printf("Invalid time entered. Please enter a valid time (HH MM).\n");
        return;
    }

    // Get the current time and store it in a time_t structure
    time_t now;
    struct tm *timeinfo;
    char alarmTime[9]; // HH:MM:SS format (to store alarm time)

    time(&now);  // Get the current time in seconds
    timeinfo = localtime(&now);  // Convert to local time format
    timeinfo->tm_hour = hour;  // Set the alarm hour
    timeinfo->tm_min = minute;  // Set the alarm minute
    timeinfo->tm_sec = 0;  // Set seconds to 0 for the alarm

    // Convert the modified tm structure back to time_t (for comparison)
    now = mktime(timeinfo);
    
    // Format the alarm time as HH:MM:SS
    strftime(alarmTime, sizeof(alarmTime), "%H:%M:%S", timeinfo);

    // Print the alarm time
    printf("Alarm set for: %s\n", alarmTime);

    // Wait for the alarm time to trigger
    while (1) {
        // Check the current time again
        time(&now);
        timeinfo = localtime(&now);
        
        char currentTime[9];  // Store current time as HH:MM:SS

        // Format the current time as HH:MM:SS
        strftime(currentTime, sizeof(currentTime), "%H:%M:%S", timeinfo);
        
        // Compare the current time with the alarm time
        if (strcmp(currentTime, alarmTime) == 0) {
            printf("\nALARM! It's time to wake up!\n");
            break;  // Exit the loop once alarm time is reached
        }
        
        // Wait for 1 second before checking the time again
        sleep(1);
    }
}



