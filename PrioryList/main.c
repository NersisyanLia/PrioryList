// main.c

#include "task_manager.h"

int main() {
    int choice;

    do {
        printf("1. Login\n2. Create Profile\n3. Create To-Do List\n4. Add Task\n5. Display Tasks\n6. Set Reminder\n7. Save Tasks to File\n8. Load Tasks from File\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (!isLoggedIn()) {
                handleLogin();
            }
            else {
                handleLogout();
                printf("Logout successful!\n");
            }
            break;
        case 2:
            struct User newUser;
            createProfile(&newUser);
            users[userCount] = newUser;
            userCount++;
            break;
        case 3:
            createToDoList();
            break;
        case 4:
            if (isLoggedIn()) {
                addTask("Sample Task", 2023, 12, 31, "Work", "Important", "Finish the coding part.");
            }
            else {
                printf("You need to log in first.\n");
            }
            break;
        case 5:
            displayTasks();
            break;
        case 6:
            setReminder();
            break;
        case 7:
            saveTasksToFile();
            break;
        case 8:
            loadTasksFromFile();
            break;
        case 9:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 9);

    return 0;
}