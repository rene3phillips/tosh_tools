#include <stdio.h>
#include <dirent.h>
#include <string.h>

// Function to list files in the given directory path
void list_files(const char *path) {
    struct dirent *entry;  // Pointer to store directory entries
    DIR *dp = opendir(path);  // Open the directory specified by path

    // If the directory cannot be opened, print an error message and return
    if (dp == NULL) {
        perror("Error opening the location");
        return;
    }

    // Print the location being listed
    printf("Listing files in the location: %s\n\n", path);

    // Loop through the directory entries
    while ((entry = readdir(dp))) {
        // Skip hidden files and directories (those starting with '.')
        // Also skip the parent (..) and current (.) directory entries
        if (entry->d_name[0] == '.') {
            continue;
        }

        // Print the name of the file/directory
        printf("%s\n", entry->d_name);
    }

    // Close the directory stream
    closedir(dp);
}
