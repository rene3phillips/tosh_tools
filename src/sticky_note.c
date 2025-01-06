#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum Notes and Maximum Note Length
#define MAX_NOTES 10
#define MAX_NOTE_LENGTH 200

// Structure to Store Notes
typedef struct {
    char note[MAX_NOTE_LENGTH];  // Array to Store Note Content
} StickyNote;

// Array to Store the Notes
StickyNote notes[MAX_NOTES];

// Counter to Count Notes
int note_count = 0;

// Function to Add a Note
void add_note() {  


    printf("\n--- Sticky Notes ---\n");

    // Check if MAX_NOTES Has Been Reached
    if (note_count >= MAX_NOTES) {
        printf("\nMaximum number of notes reached!\n");
        return;
    }
    
    // Prompt User to Enter Note
    printf("\nEnter your note: ");
    getchar();  

    // Scan Note
    fgets(notes[note_count].note, MAX_NOTE_LENGTH, stdin);  

    // Remove Newline Character
    notes[note_count].note[strcspn(notes[note_count].note, "\n")] = 0;
    
    // Increment Note Count
    note_count++;
    printf("Note added!\n");
}

// Function to View All Notes
void view_notes() {
    printf("\n--- Sticky Notes ---\n");

    // No Notes Available
    if (note_count == 0) {
        printf("\nNo notes available.\n");
        return;
    }

    // Display Notes
    for (int i = 0; i < note_count; i++) {
        printf("\nNote %d: %s\n", i + 1, notes[i].note);
    }
}

// Function to Delete Note
void delete_note() {
    printf("\n--- Sticky Notes ---\n");

    // No Notes Available
    if (note_count == 0) {
        printf("\nNo notes to delete.\n");
        return;
    }

    // Get Note Number to Delete
    int note_index;
    printf("\nEnter note number to delete: ");
    scanf("%d", &note_index);  

    // Check if Note Number is Valid
    if (note_index < 1 || note_index > note_count) {
        printf("Invalid note number!\n");
        return;
    }

    // Shift Notes After Deleted Note (to fill gap)
    for (int i = note_index - 1; i < note_count - 1; i++) {
        strcpy(notes[i].note, notes[i + 1].note);
    }
    
    // Decrease the note count
    note_count--;
    printf("Note deleted.\n");
}
