#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants for maximum tasks and task length
#define MAX_TASKS 10
#define MAX_TASK_LENGTH 100

// Enum to represent task priority
typedef enum { LOW, MEDIUM, HIGH } Priority;

// Struct to store task details
typedef struct {
    char task[MAX_TASK_LENGTH];  // Task description
    Priority priority;           // Task priority (Low, Medium, High)
    char due_date[11];           // Task due date in YYYY-MM-DD format
    int completed;               // Status of the task (0 = Pending, 1 = Completed)
} Task;

// Array to store tasks and a counter for the number of tasks
Task tasks[MAX_TASKS];
int task_count = 0;

// Function to add a new task
void add_task() {
    printf("\n--- Task Manager ---\n");

    // Check if the maximum number of tasks has been reached
    if (task_count >= MAX_TASKS) {
        printf("Maximum number of tasks reached!\n");
        return;
    }

    // Prompt the user to enter a task description
    printf("Enter your task: ");
    getchar();  // To consume any leftover newline character from previous input
    fgets(tasks[task_count].task, MAX_TASK_LENGTH, stdin);  // Get task description
    tasks[task_count].task[strcspn(tasks[task_count].task, "\n")] = 0;  // Remove the newline character

    // Prompt the user to enter the priority of the task
    printf("Enter task priority (0 = Low, 1 = Medium, 2 = High): ");
    int priority;
    scanf("%d", &priority);
    tasks[task_count].priority = (Priority)priority;  // Set the task priority

    // Prompt the user to enter the task due date
    printf("Enter task due date (MM-DD-YYYY): ");
    scanf("%s", tasks[task_count].due_date);  // Get the task due date

    tasks[task_count].completed = 0;  // Set the task status as not completed initially
    task_count++;  // Increment the task count
    printf("Task added!\n");
}

// Function to view all tasks
void view_tasks() {
    printf("\n--- Task Manager ---\n");

    // If no tasks exist, inform the user
    if (task_count == 0) {
        printf("No tasks available.\n");
        return;
    }

    // Display all the tasks with details
    printf("\nTasks:\n");
    for (int i = 0; i < task_count; i++) {
        printf("Task %d: %s\n", i + 1, tasks[i].task);
        printf("Priority: %s\n", tasks[i].priority == LOW ? "Low" : (tasks[i].priority == MEDIUM ? "Medium" : "High"));
        printf("Due Date: %s\n", tasks[i].due_date);
        printf("Status: %s\n", tasks[i].completed ? "Completed" : "Pending");
        printf("----------------------------\n");
    }
}

// Function to delete a specific task
void delete_task() {
    printf("\n--- Task Manager ---\n");

    // If there are no tasks, inform the user
    if (task_count == 0) {
        printf("No tasks to delete.\n");
        return;
    }

    int task_index;
    printf("Enter task number to delete: ");
    scanf("%d", &task_index);  // Get the task number to delete

    // Check if the entered task number is valid
    if (task_index < 1 || task_index > task_count) {
        printf("Invalid task number!\n");
        return;
    }

    // Shift tasks after the deleted task to fill the gap
    for (int i = task_index - 1; i < task_count - 1; i++) {
        strcpy(tasks[i].task, tasks[i + 1].task);
        tasks[i].priority = tasks[i + 1].priority;
        strcpy(tasks[i].due_date, tasks[i + 1].due_date);
        tasks[i].completed = tasks[i + 1].completed;
    }
    task_count--;  // Decrease the task count
    printf("Task deleted.\n");
}

// Function to mark a specific task as completed
void mark_task_completed() {
    printf("\n--- Task Manager ---\n");

    // If there are no tasks, inform the user
    if (task_count == 0) {
        printf("No tasks to mark as completed.\n");
        return;
    }

    int task_index;
    printf("Enter task number to mark as completed: ");
    scanf("%d", &task_index);  // Get the task number to mark as completed

    // Check if the entered task number is valid
    if (task_index < 1 || task_index > task_count) {
        printf("Invalid task number!\n");
        return;
    }

    // Mark the selected task as completed
    tasks[task_index - 1].completed = 1;
    printf("Task marked as completed.\n");
}
