#include <stdio.h>
#include <windows.h> // For Sleep function

void start_timer() {
    int seconds;
    printf("\n---Timer---\n");
    printf("Enter time in seconds: ");
    scanf("%d", &seconds);

    printf("Timer started for %d seconds.\n", seconds);

    // Countdown loop
    for (int i = seconds; i > 0; i--) {
        printf("%d...\n", i);
        fflush(stdout);
        Sleep(1000); // Sleep for 1 second (1000 milliseconds)
    }

    printf("Time's up!\n");
    return;
}
