#include <stdio.h>
#include <dirent.h>
#include <string.h>

// Function to list files in the given location
void list_files(const char *path) {
    struct dirent *entry;
    DIR *dp = opendir(path);

    if (dp == NULL) {
        perror("Error opening the location");
        return;
    }

    printf("Listing files in the location: %s\n\n", path);

    while ((entry = readdir(dp))) {
        // Skip hidden files and the parent directory (.) and the current directory (..)
        if (entry->d_name[0] == '.') {
            continue;
        }

        printf("%s\n", entry->d_name); // Print the file name
    }

    closedir(dp);
}
