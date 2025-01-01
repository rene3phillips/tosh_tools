#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <direct.h>
#include <errno.h>

void organize(const char *directory) {
    struct dirent *entry;
    DIR *dp = opendir(directory);

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    // Create subdirectories
    char images_path[1024], documents_path[1024], audio_path[1024];
    snprintf(images_path, sizeof(images_path), "%s/Images", directory);
    snprintf(documents_path, sizeof(documents_path), "%s/Documents", directory);
    snprintf(audio_path, sizeof(audio_path), "%s/Audio", directory);

    if (mkdir(images_path) == -1 && errno != EEXIST) {
        perror("mkdir Images");
    }
    if (mkdir(documents_path) == -1 && errno != EEXIST) {
        perror("mkdir Documents");
    }
    if (mkdir(audio_path) == -1 && errno != EEXIST) {
        perror("mkdir Audio");
    }

    // Loop through files
    while ((entry = readdir(dp))) {
        char file_path[1024];
        snprintf(file_path, sizeof(file_path), "%s/%s", directory, entry->d_name);

        struct stat file_stat;
        if (stat(file_path, &file_stat) == -1) {
            perror("stat");
            continue;
        }

        // Skip directories
        if (S_ISDIR(file_stat.st_mode)) {
            continue;
        }

        // Get file extension
        char *ext = strrchr(entry->d_name, '.');
        if (ext != NULL) {
            char new_path[1024];
            if (strcmp(ext, ".jpg") == 0 || strcmp(ext, ".png") == 0) {
                snprintf(new_path, sizeof(new_path), "%s/%s", images_path, entry->d_name);
                rename(file_path, new_path);
                printf("Moved %s to Images\n", entry->d_name);
            } else if (strcmp(ext, ".txt") == 0 || strcmp(ext, ".pdf") == 0) {
                snprintf(new_path, sizeof(new_path), "%s/%s", documents_path, entry->d_name);
                rename(file_path, new_path);
                printf("Moved %s to Documents\n", entry->d_name);
            } else if (strcmp(ext, ".mp3") == 0 || strcmp(ext, ".wav") == 0) {
                snprintf(new_path, sizeof(new_path), "%s/%s", audio_path, entry->d_name);
                rename(file_path, new_path);
                printf("Moved %s to Audio\n", entry->d_name);
            }
        }
    }

    closedir(dp);
}