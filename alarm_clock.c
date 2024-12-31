#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>  // For sleep() function

// Function to set the alarm time
void setAlarm() {
    int hour, minute;
    
    // Ask the user to input the alarm time
    printf("Enter the alarm time (HH MM): ");
    
    // Clear the input buffer before taking user input
    while (getchar() != '\n');  // This clears any leftover characters in the buffer

    // Now read the input
    int result = scanf("%d %d", &hour, &minute);

    // Check if input is valid
    if (result != 2 || hour < 0 || hour > 23 || minute < 0 || minute > 59) {
        printf("Invalid time entered. Please enter a valid time (HH MM).\n");
        return;
    }

    time_t now;
    struct tm *timeinfo;
    char alarmTime[9]; // HH:MM:SS format

    time(&now);
    timeinfo = localtime(&now);
    timeinfo->tm_hour = hour;
    timeinfo->tm_min = minute;
    timeinfo->tm_sec = 0;

    // Convert tm struct back to time_t
    now = mktime(timeinfo);
    strftime(alarmTime, sizeof(alarmTime), "%H:%M:%S", timeinfo);

    printf("Alarm set for: %s\n", alarmTime);

    // Wait for the alarm time to trigger
    while (1) {
        // Check current time
        time(&now);
        timeinfo = localtime(&now);
        
        char currentTime[9];
        strftime(currentTime, sizeof(currentTime), "%H:%M:%S", timeinfo);
        
        // Check if current time matches the alarm time
        if (strcmp(currentTime, alarmTime) == 0) {
            printf("\nALARM! It's time to wake up!\n");
            break;  // Break the loop once alarm time is reached
        }
        
        // Wait for 1 second before checking again
        sleep(1);
    }
}



