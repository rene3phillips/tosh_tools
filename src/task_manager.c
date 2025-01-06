#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_TASK_LENGTH 100

// Enum to Represent Task Priority
typedef enum { LOW, MEDIUM, HIGH } Priority;

// Structure to Store Task Details
typedef struct {
    char task[MAX_TASK_LENGTH];  // Task Description
    Priority priority;           // Task Priority (Low, Medium, High)
    char due_date[11];           // Task Due Date 
    int completed;               // Status of Task (0 = Pending, 1 = Completed)
} Task;

// Array to Store Tasks
Task tasks[MAX_TASKS];

// Counter to Count Tasks
int task_count = 0;

// Function to Add a Task
void add_task() {

    printf("\n--- Task Manager ---\n");

    // Check if MAX_TASKS Has Been Reached
    if (task_count >= MAX_TASKS) {
        printf("\nMaximum number of tasks reached!\n");
        return;
    }

    // Prompt User to Enter Task 
    printf("\nEnter your task: ");
    getchar();  
    fgets(tasks[task_count].task, MAX_TASK_LENGTH, stdin);  
    tasks[task_count].task[strcspn(tasks[task_count].task, "\n")] = 0;  

    // Prompt the User to Enter Priority
    printf("Enter task priority (0 = Low, 1 = Medium, 2 = High): ");
    int priority;
    scanf("%d", &priority);
    tasks[task_count].priority = (Priority)priority;  // Set the task priority

    // Prompt User to Enter Due Date
    printf("Enter task due date (MM-DD-YYYY): ");
    scanf("%s", tasks[task_count].due_date);  

    tasks[task_count].completed = 0;  // Set Task as "Not Completed"
    task_count++;  // Increment Task Count
    printf("Task added!\n");
}

// Function to View All Tasks
void view_tasks() {

    printf("\n--- Task Manager ---\n");

    // No Tasks Exist
    if (task_count == 0) {
        printf("\nNo tasks available.\n");
        return;
    }

    // Display All Tasks with Details
    printf("\nTasks:\n");
    for (int i = 0; i < task_count; i++) {
        printf("Task %d: %s\n", i + 1, tasks[i].task);
        printf("Priority: %s\n", tasks[i].priority == LOW ? "Low" : (tasks[i].priority == MEDIUM ? "Medium" : "High"));
        printf("Due Date: %s\n", tasks[i].due_date);
        printf("Status: %s\n", tasks[i].completed ? "Completed" : "Pending");
        printf("----------------------------\n");
    }
}

// Function to Delete Task
void delete_task() {

    printf("\n--- Task Manager ---\n");

    // No Tasks Exist
    if (task_count == 0) {
        printf("\nNo tasks to delete.\n");
        return;
    }

    // Prompt User to Enter Task Number to Delete
    int task_index;
    printf("\nEnter task number to delete: ");
    scanf("%d", &task_index);  

    // Check if Entered Task Number is Valid
    if (task_index < 1 || task_index > task_count) {
        printf("Invalid task number!\n");
        return;
    }

    // Shift Tasks After Deleting Task (to fill gap)
    for (int i = task_index - 1; i < task_count - 1; i++) {
        strcpy(tasks[i].task, tasks[i + 1].task);
        tasks[i].priority = tasks[i + 1].priority;
        strcpy(tasks[i].due_date, tasks[i + 1].due_date);
        tasks[i].completed = tasks[i + 1].completed;
    }

    // Decrement Task Count
    task_count--;  
    printf("Task deleted.\n");
}

// Function to Mark Task Comploeted 
void mark_task_completed() {

    printf("\n--- Task Manager ---\n");

    // No Tasks Exist
    if (task_count == 0) {
        printf("\nNo tasks to mark as completed.\n");
        return;
    }

    // Prompt User to Enter Task Number to Complete
    int task_index;
    printf("\nEnter task number to mark as completed: ");
    scanf("%d", &task_index);  // Get the task number to mark as completed

    // Check if Task Number Entered is Valid
    if (task_index < 1 || task_index > task_count) {
        printf("Invalid task number!\n");
        return;
    }

    // Mark Task as Complete
    tasks[task_index - 1].completed = 1;
    printf("Task marked as completed.\n");
}