#include <stdio.h>
#include <stdlib.h>

// Purple Theme 
#define PURPLE_TEXT "\x1b[97m"  
#define PURPLE_BG "\x1b[45m"   

// Light Theme
#define LIGHT_TEXT "\x1b[30m"  
#define LIGHT_BG "\x1b[47m"    

// Dark Theme 
#define DARK_TEXT "\x1b[97m"   
#define DARK_BG "\x1b[40m"     

// Reset Theme
#define RESET_COLOR "\x1b[0m"

// Function to Apply Purple Theme
void apply_purple_theme() {
    printf("%s%s", PURPLE_TEXT, PURPLE_BG);
    printf("\nPurple theme applied!\n");
}

// Function to Apply Light Theme
void apply_light_theme() {
    printf("%s%s", LIGHT_TEXT, LIGHT_BG);
    printf("\nLight theme applied!\n");
}

// Function to Apply Dark Theme
void apply_dark_theme() {
    printf("%s%s", DARK_TEXT, DARK_BG);
    printf("\nDark theme applied!\n");
}

// Function to Reset Theme
void reset_theme() {
    printf("%s%s", RESET_COLOR);
    printf("\n\nTheme Reset!\n");
}
