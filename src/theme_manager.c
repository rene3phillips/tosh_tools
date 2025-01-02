#include <stdio.h>
#include <stdlib.h>

// Teal and Purple Theme - ANSI escape codes for colors
#define TEAL_TEXT "\x1b[36m"   // Teal text color
#define PURPLE_BG "\x1b[45m"   // Purple background color

// Light Theme - ANSI escape codes for light theme
#define LIGHT_TEXT "\x1b[30m"  // Light text color (black)
#define LIGHT_BG "\x1b[47m"    // Light background color (white)

// Dark Theme - ANSI escape codes for dark theme
#define DARK_TEXT "\x1b[97m"   // Light text color (white)
#define DARK_BG "\x1b[40m"     // Dark background color (black)

// Reset color to default (reset the applied color changes)
#define RESET_COLOR "\x1b[0m"

// Function to apply the Purple theme
void apply_teal_purple_theme() {
    // Set the text color to teal and the background color to purple
    printf("%s%s", TEAL_TEXT, PURPLE_BG);
    printf("\nPurple theme applied!\n");
}

// Function to apply the Light theme
void apply_light_theme() {
    // Set the text color to black and the background color to white
    printf("%s%s", LIGHT_TEXT, LIGHT_BG);
    printf("\nLight theme applied!\n");
}

// Function to apply the Dark theme
void apply_dark_theme() {
    // Set the text color to white and the background color to black
    printf("%s%s", DARK_TEXT, DARK_BG);
    printf("\nDark theme applied!\n");
}

// Function to display the menu of theme options
void display_menu() {
    // Display available theme options for the user
    printf("\nTheme Manager\n");
    printf("1. Teal and Purple Theme\n");
    printf("2. Light Theme\n");
    printf("3. Dark Theme\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

