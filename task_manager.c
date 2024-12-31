#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_TASK_LENGTH 100

typedef enum { LOW, MEDIUM, HIGH } Priority;

typedef struct {
    char task[MAX_TASK_LENGTH];
    Priority priority;
    char due_date[11];  // Format: YYYY-MM-DD
    int completed;
} Task;

Task tasks[MAX_TASKS];
int task_count = 0;

void add_task() {
    if (task_count >= MAX_TASKS) {
        printf("Maximum number of tasks reached!\n");
        return;
    }

    printf("Enter your task: ");
    getchar();  // To consume any leftover newline character
    fgets(tasks[task_count].task, MAX_TASK_LENGTH, stdin);
    tasks[task_count].task[strcspn(tasks[task_count].task, "\n")] = 0;

    printf("Enter task priority (0 = Low, 1 = Medium, 2 = High): ");
    int priority;
    scanf("%d", &priority);
    tasks[task_count].priority = (Priority)priority;

    printf("Enter task due date (YYYY-MM-DD): ");
    scanf("%s", tasks[task_count].due_date);

    tasks[task_count].completed = 0;  // Task is not completed by default
    task_count++;
    printf("Task added!\n");
}

void view_tasks() {
    if (task_count == 0) {
        printf("No tasks available.\n");
        return;
    }

    printf("\nTasks:\n");
    for (int i = 0; i < task_count; i++) {
        printf("Task %d: %s\n", i + 1, tasks[i].task);
        printf("Priority: %s\n", tasks[i].priority == LOW ? "Low" : (tasks[i].priority == MEDIUM ? "Medium" : "High"));
        printf("Due Date: %s\n", tasks[i].due_date);
        printf("Status: %s\n", tasks[i].completed ? "Completed" : "Pending");
        printf("----------------------------\n");
    }
}

void delete_task() {
    if (task_count == 0) {
        printf("No tasks to delete.\n");
        return;
    }

    int task_index;
    printf("Enter task number to delete: ");
    scanf("%d", &task_index);

    if (task_index < 1 || task_index > task_count) {
        printf("Invalid task number!\n");
        return;
    }

    for (int i = task_index - 1; i < task_count - 1; i++) {
        strcpy(tasks[i].task, tasks[i + 1].task);
        tasks[i].priority = tasks[i + 1].priority;
        strcpy(tasks[i].due_date, tasks[i + 1].due_date);
        tasks[i].completed = tasks[i + 1].completed;
    }
    task_count--;
    printf("Task deleted.\n");
}

void mark_task_completed() {
    if (task_count == 0) {
        printf("No tasks to mark as completed.\n");
        return;
    }

    int task_index;
    printf("Enter task number to mark as completed: ");
    scanf("%d", &task_index);

    if (task_index < 1 || task_index > task_count) {
        printf("Invalid task number!\n");
        return;
    }

    tasks[task_index - 1].completed = 1;
    printf("Task marked as completed.\n");
}


