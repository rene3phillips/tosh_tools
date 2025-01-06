#include <stdio.h>
#include <dirent.h> // Working with File Systems
#include <string.h>

// Function to List Files in Directory
void list_files(const char *path) {

    // Pointer to Hold Directory Entries
    struct dirent *entry;  

    // Open the Directory
    DIR *dp = opendir(path);  

    // Check if the Directory was Opened
    if (dp == NULL) {
        perror("Error opening the location");
        return;
    }

    // Print Directory Location
    printf("Listing files in the location: %s\n\n", path);

    // Loop Through Directory Entries
    while ((entry = readdir(dp))) {
        // Skip Hidden Entries (those starting with '.')
        if (entry->d_name[0] == '.') {
            continue;
        }

        // Print Entries
        printf("%s\n", entry->d_name);
    }

    // Close the Directory
    closedir(dp);
}