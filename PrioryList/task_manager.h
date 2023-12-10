/**
 * @file task_manager.h
 * @brief Header file containing structures and function declarations for task management.
 */

#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <stdbool.h>
#include <time.h>

 /**
  * @brief Maximum number of users the system can handle.
  */
#define MAX_USERS 100

  /**
   * @brief Maximum number of tasks the system can handle.
   */
#define MAX_TASKS 100

   /**
    * @brief Maximum length of a task description.
    */
#define MAX_TASK_LENGTH 50

    /**
     * @brief User structure containing user information.
     */
struct User {
    char username[50];  /**< User's username. */
    char password[50];  /**< User's password. */
    char name[100];     /**< User's full name. */
    int age;            /**< User's age. */
    char job[100];      /**< User's job. */
};

/**
 * @brief Task structure containing task information.
 */
struct Task {
    char description[MAX_TASK_LENGTH]; /**< Task description. */
    int completed;                    /**< Task completion status (0 or 1). */
    bool reminderSet;                 /**< Flag indicating whether a reminder is set. */
    struct tm dueDate;                /**< Due date of the task. */
    char category[50];                /**< Task category. */
    char labels[50];                  /**< Task labels. */
    char notes[200];                  /**< Additional notes for the task. */
};

extern struct User users[MAX_USERS]; /**< Array of user structures. */
extern int userCount;                /**< Number of registered users. */

extern struct Task tasks[MAX_TASKS]; /**< Array of task structures. */
extern int taskCount;                /**< Number of tasks in the system. */

extern int currentUserIndex;         /**< Index of the currently logged-in user. */

/**
 * @brief Check if a user is currently logged in.
 * @return True if a user is logged in, false otherwise.
 */
bool isLoggedIn();

/**
 * @brief Handle the user login process.
 */
void handleLogin();

/**
 * @brief Handle the user logout process.
 */
void handleLogout();

/**
 * @brief Create a new user profile.
 * @param user Pointer to a User structure.
 */
void createProfile(struct User* user);

/**
 * @brief Create a to-do list for the logged-in user.
 */
void createToDoList();

/**
 * @brief Add a task to the system.
 * @param description Task description.
 * @param year Year of the task's due date.
 * @param month Month of the task's due date.
 * @param day Day of the task's due date.
 * @param category Task category.
 * @param labels Task labels.
 * @param notes Additional notes for the task.
 */
void addTask(char description[], int year, int month, int day, char category[], char labels[], char notes[]);

/**
 * @brief Display the list of tasks.
 */
void displayTasks();

/**
 * @brief Set a reminder for a specific task.
 */
void setReminder();

/**
 * @brief Save tasks to a file.
 */
void saveTasksToFile();

/**
 * @brief Load tasks from a file.
 */
void loadTasksFromFile();

#endif // TASK_MANAGER_H