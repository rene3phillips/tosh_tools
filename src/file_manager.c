#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <direct.h>
#include <errno.h>

// Function to Organize Files in a Directory
void organize() {

    char directory[1024];

    // Program Title
    printf("\n--- File Organizer ---\n");
    printf("\nEnter the path of the folder you want to organize...");
    printf("\nIt will sort files into categories like Audio, Documents, and Images: ");
    scanf("%s", directory);

    // Pointer to Hold Directory Entries
    struct dirent *entry;

    // Open the Directory
    DIR *dp = opendir(directory);

    // Check if the Directory was Opened
    if (dp == NULL) {
        perror("opendir");
        return;
    }

    // Paths for The Subdirectories
    char images_path[1024], documents_path[1024], audio_path[1024];
    snprintf(images_path, sizeof(images_path), "%s/Images", directory);
    snprintf(documents_path, sizeof(documents_path), "%s/Documents", directory);
    snprintf(audio_path, sizeof(audio_path), "%s/Audio", directory);

    // Create Folders for Images, Documents, and Audio 
    if (mkdir(images_path) == -1 && errno != EEXIST) {
        perror("mkdir Images");
    }
    if (mkdir(documents_path) == -1 && errno != EEXIST) {
        perror("mkdir Documents");
    }
    if (mkdir(audio_path) == -1 && errno != EEXIST) {
        perror("mkdir Audio");
    }

    // Loop Through All the Files in the Directory
    while ((entry = readdir(dp))) {

        // Get the Path of the Current File
        char file_path[1024];
        snprintf(file_path, sizeof(file_path), "%s/%s", directory, entry->d_name);

        // Get the File Stat
        struct stat file_stat;
        if (stat(file_path, &file_stat) == -1) {
            perror("stat");
            continue;
        }

        // Skip Folders, Only Sort Files
        if (S_ISDIR(file_stat.st_mode)) {
            continue;
        }

        // Get the File Extension
        char *ext = strrchr(entry->d_name, '.');
        if (ext != NULL) {
            char new_path[1024];  

            // Move File to Appropriate Folder
            if (strcmp(ext, ".jpg") == 0 || strcmp(ext, ".png") == 0) {
                snprintf(new_path, sizeof(new_path), "%s/%s", images_path, entry->d_name);
                if (rename(file_path, new_path) == 0) {
                    printf("\n");
                    printf("Moved %s to Images\n", entry->d_name);
                } else {
                    printf("\n");
                    perror("rename");
                }
            } else if (strcmp(ext, ".txt") == 0 || strcmp(ext, ".pdf") == 0) {
                snprintf(new_path, sizeof(new_path), "%s/%s", documents_path, entry->d_name);
                if (rename(file_path, new_path) == 0) {
                    printf("\n");
                    printf("Moved %s to Documents\n", entry->d_name);
                } else {
                    printf("\n");
                    perror("rename");
                }
            } else if (strcmp(ext, ".mp3") == 0 || strcmp(ext, ".wav") == 0) {
                snprintf(new_path, sizeof(new_path), "%s/%s", audio_path, entry->d_name);
                if (rename(file_path, new_path) == 0) {
                    printf("\n");
                    printf("Moved %s to Audio\n", entry->d_name);
                } else {
                    printf("\n");
                    perror("rename");
                }
            }
        }
    }

    // Close Directory
    closedir(dp);

    printf("\nFile organization complete!\n");
}