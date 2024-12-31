#include <stdio.h>
#include <stdlib.h>

// Teal and Purple Theme
#define TEAL_TEXT "\x1b[36m"
#define PURPLE_BG "\x1b[45m"

// Light Theme
#define LIGHT_TEXT "\x1b[30m"
#define LIGHT_BG "\x1b[47m"

// Dark Theme
#define DARK_TEXT "\x1b[97m"
#define DARK_BG "\x1b[40m"

#define RESET_COLOR "\x1b[0m"

void apply_teal_purple_theme() {
    printf("%s%s", TEAL_TEXT, PURPLE_BG);
    printf("Teal and Purple theme applied!\n");
}

void apply_light_theme() {
    printf("%s%s", LIGHT_TEXT, LIGHT_BG);
    printf("Light theme applied!\n");
}

void apply_dark_theme() {
    printf("%s%s", DARK_TEXT, DARK_BG);
    printf("Dark theme applied!\n");
}

void display_menu() {
    printf("\nTheme Manager\n");
    printf("1. Teal and Purple Theme\n");
    printf("2. Light Theme\n");
    printf("3. Dark Theme\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

