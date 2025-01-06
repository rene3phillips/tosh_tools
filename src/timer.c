#include <stdio.h>
#include <windows.h> // For Sleep Function

// Function to Start Timer
void start_timer() {
    int seconds;  

    // Program Title
    printf("\n---Timer---\n");
    
    // Prompt User to Enter Time (in seconds)
    printf("\nEnter time in seconds: ");
    scanf("%d", &seconds);

    // Inform User the Timer has Started
    printf("Timer started for %d seconds.\n", seconds);

    // Countdown Loop
    for (int i = seconds; i > 0; i--) {

        // Print the Remaining Time
        printf("%d...\n", i);

        // Flush Output Buffer (to ensure the output is immediately printed)
        fflush(stdout);

        // Sleep for 1 Second
        Sleep(1000); 
    }

    // Inform User The Time is Up
    printf("Time's up!\n");
    return;
}