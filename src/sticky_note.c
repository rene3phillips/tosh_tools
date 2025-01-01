#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOTES 10
#define MAX_NOTE_LENGTH 200

typedef struct {
    char note[MAX_NOTE_LENGTH];
} StickyNote;

StickyNote notes[MAX_NOTES];
int note_count = 0;

void add_note() {  // Correct function name with underscore
    printf("\n--- Sticky Notes ---\n");

    if (note_count >= MAX_NOTES) {
        printf("Maximum number of notes reached!\n");
        return;
    }
    printf("Enter your note: ");
    getchar();  // To consume any leftover newline character
    fgets(notes[note_count].note, MAX_NOTE_LENGTH, stdin);
    // Remove the newline character from fgets
    notes[note_count].note[strcspn(notes[note_count].note, "\n")] = 0;
    note_count++;
    printf("Note added!\n");
}

void view_notes() {
    printf("\n--- Sticky Notes ---\n");

    if (note_count == 0) {
        printf("No notes available.\n");
        return;
    }

    for (int i = 0; i < note_count; i++) {
        printf("Note %d: %s\n", i + 1, notes[i].note);
    }
}

void delete_note() {
    printf("\n--- Sticky Notes ---\n");

    if (note_count == 0) {
        printf("No notes to delete.\n");
        return;
    }

    int note_index;
    printf("Enter note number to delete: ");
    scanf("%d", &note_index);

    if (note_index < 1 || note_index > note_count) {
        printf("Invalid note number!\n");
        return;
    }

    // Shift the notes after the deleted note to fill the gap
    for (int i = note_index - 1; i < note_count - 1; i++) {
        strcpy(notes[i].note, notes[i + 1].note);
    }
    note_count--;
    printf("Note deleted.\n");
}
