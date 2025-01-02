#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for maximum notes and note length
#define MAX_NOTES 10
#define MAX_NOTE_LENGTH 200

// Define a struct to store sticky notes
typedef struct {
    char note[MAX_NOTE_LENGTH];  // Array to store the content of a note
} StickyNote;

// Array to store the notes and a counter to keep track of the number of notes
StickyNote notes[MAX_NOTES];
int note_count = 0;

// Function to add a note
void add_note() {  // Correct function name with underscore
    printf("\n--- Sticky Notes ---\n");

    // Check if the maximum number of notes has been reached
    if (note_count >= MAX_NOTES) {
        printf("Maximum number of notes reached!\n");
        return;
    }
    
    // Prompt the user to enter a note
    printf("Enter your note: ");
    getchar();  // To consume any leftover newline character from previous input
    fgets(notes[note_count].note, MAX_NOTE_LENGTH, stdin);  // Get the note input from the user

    // Remove the newline character that fgets adds at the end of the string
    notes[note_count].note[strcspn(notes[note_count].note, "\n")] = 0;
    
    // Increment the note count and confirm that the note was added
    note_count++;
    printf("Note added!\n");
}

// Function to view all notes
void view_notes() {
    printf("\n--- Sticky Notes ---\n");

    // If there are no notes, inform the user
    if (note_count == 0) {
        printf("No notes available.\n");
        return;
    }

    // Display each note with its number
    for (int i = 0; i < note_count; i++) {
        printf("Note %d: %s\n", i + 1, notes[i].note);
    }
}

// Function to delete a specific note
void delete_note() {
    printf("\n--- Sticky Notes ---\n");

    // If there are no notes, inform the user
    if (note_count == 0) {
        printf("No notes to delete.\n");
        return;
    }

    int note_index;
    printf("Enter note number to delete: ");
    scanf("%d", &note_index);  // Get the note number to delete

    // Check if the entered note number is valid
    if (note_index < 1 || note_index > note_count) {
        printf("Invalid note number!\n");
        return;
    }

    // Shift the notes after the deleted note to fill the gap
    for (int i = note_index - 1; i < note_count - 1; i++) {
        strcpy(notes[i].note, notes[i + 1].note);
    }
    
    // Decrease the note count as one note is deleted
    note_count--;
    printf("Note deleted.\n");
}
