// task_manager.c

#include "task_manager.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User users[MAX_USERS];
int userCount = 0;

struct Task tasks[MAX_TASKS];
int taskCount = 0;

int currentUserIndex = -1;

bool isLoggedIn() {
    return currentUserIndex != -1;
}

void handleLogin() {
    if (userCount == 0) {
        printf("No profiles found. Please create a profile first.\n");
        return;
    }

    char enteredUsername[50];
    char enteredPassword[50];

    printf("Enter username: ");
    scanf("%s", enteredUsername);
    printf("Enter password: ");
    scanf("%s", enteredPassword);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(enteredUsername, users[i].username) == 0 && strcmp(enteredPassword, users[i].password) == 0) {
            currentUserIndex = i;
            printf("Login successful!\n");
            return;
        }
    }

    printf("Invalid username or password. Please try again.\n");
}

void handleLogout() {
    currentUserIndex = -1;
}

void createProfile(struct User* user) {
    if (isLoggedIn()) {
        printf("You are already logged in. Logout first to create a new profile.\n");
        return;
    }

    printf("Enter username: ");
    scanf("%s", user->username);
    printf("Enter password: ");
    scanf("%s", user->password);
    printf("Enter name: ");
    scanf("%s", user->name);
    printf("Enter age: ");
    scanf("%d", &user->age);
    printf("Enter job: ");
    scanf("%s", user->job);

    users[userCount] = *user;
    userCount++;
}

void createToDoList() {
    if (isLoggedIn()) {
        printf("Creating a to-do list for user: %s\n", users[currentUserIndex].username);
        // Add code to allow the user to create a to-do list.
    }
    else {
        printf("You need to log in first.\n");
    }
}

void addTask(char description[], int year, int month, int day, char category[], char labels[], char notes[]) {
    if (taskCount < MAX_TASKS) {
        strcpy(tasks[taskCount].description, description);
        tasks[taskCount].completed = 0;
        tasks[taskCount].reminderSet = false;
        tasks[taskCount].dueDate.tm_year = year - 1900;
        tasks[taskCount].dueDate.tm_mon = month - 1;
        tasks[taskCount].dueDate.tm_mday = day;
        strcpy(tasks[taskCount].category, category);
        strcpy(tasks[taskCount].labels, labels);
        strcpy(tasks[taskCount].notes, notes);
        taskCount++;
    }
    else {
        printf("Task limit reached.\n");
    }
}

void displayTasks() {
    printf("Tasks:\n");
    for (int i = 0; i < taskCount; ++i) {
        printf("Description: %s\n", tasks[i].description);
        printf("Category: %s\n", tasks[i].category);
        printf("Labels: %s\n", tasks[i].labels);
        printf("Due Date: %d-%02d-%02d\n", tasks[i].dueDate.tm_year + 1900, tasks[i].dueDate.tm_mon + 1, tasks[i].dueDate.tm_mday);
        printf("Notes: %s\n", tasks[i].notes);
        printf("Completed: %s\n", tasks[i].completed ? "Yes" : "No");
        printf("Reminder Set: %s\n\n", tasks[i].reminderSet ? "Yes" : "No");
    }
}

void setReminder() {
    if (isLoggedIn()) {
        // Display the list of tasks
        printf("Tasks:\n");
        for (int i = 0; i < taskCount; ++i) {
            printf("%d. %s\n", i + 1, tasks[i].description);
        }

        int taskIndex;
        printf("Enter the index of the task to set a reminder for: ");
        scanf("%d", &taskIndex);

        if (taskIndex >= 1 && taskIndex <= taskCount) {
            // Set the reminder flag for the selected task
            tasks[taskIndex - 1].reminderSet = true;
            printf("Reminder set for the task: %s\n", tasks[taskIndex - 1].description);
        }
        else {
            printf("Invalid task index.\n");
        }
    }
    else {
        printf("You need to log in first.\n");
    }
}

void saveTasksToFile() {
    FILE* file = fopen("tasks.txt", "w");
    if (file != NULL) {
        for (int i = 0; i < taskCount; ++i) {
            fprintf(file, "%s|%d|%d|%d-%d-%d|%s|%s|%s|%d\n",
                tasks[i].description, tasks[i].completed, tasks[i].reminderSet,
                tasks[i].dueDate.tm_year + 1900, tasks[i].dueDate.tm_mon + 1, tasks[i].dueDate.tm_mday,
                tasks[i].category, tasks[i].labels, tasks[i].notes);
        }
        fclose(file);
    }
    else {
        printf("Error: Could not open file for writing.\n");
    }
}

void loadTasksFromFile() {
    FILE* file = fopen("tasks.txt", "r");
    if (file != NULL) {
        while (fscanf(file, "%[^|]|%d|%d|%d-%d-%d|%[^|]|%[^|]|%[^\n]\n",
            tasks[taskCount].description, &tasks[taskCount].completed, &tasks[taskCount].reminderSet,
            &tasks[taskCount].dueDate.tm_year, &tasks[taskCount].dueDate.tm_mon, &tasks[taskCount].dueDate.tm_mday,
            tasks[taskCount].category, tasks[taskCount].labels, tasks[taskCount].notes) == 9) {
            taskCount++;
        }
        fclose(file);
    }
}