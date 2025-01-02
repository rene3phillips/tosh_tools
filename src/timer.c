#include <stdio.h>
#include <windows.h> // For Sleep function (to create a delay)

// Function to start a timer
void start_timer() {
    int seconds;  // Variable to store the number of seconds for the timer

    printf("\n---Timer---\n");
    
    // Prompt the user to enter the time in seconds
    printf("Enter time in seconds: ");
    scanf("%d", &seconds);

    // Inform the user the timer has started
    printf("Timer started for %d seconds.\n", seconds);

    // Countdown loop
    for (int i = seconds; i > 0; i--) {
        // Print the remaining time
        printf("%d...\n", i);

        // Flush the output buffer to ensure the output is immediately printed
        fflush(stdout);

        // Sleep for 1 second (1000 milliseconds)
        Sleep(1000); // The Sleep function is from the windows.h library
    }

    // Inform the user the time is up
    printf("Time's up!\n");
    return;
}
