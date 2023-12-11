Task Manager Readme
This repository contains a simple task management system implemented in C. The system allows users to perform various tasks such as logging in, creating profiles, managing to-do lists, adding tasks, setting reminders, and more. Below is an overview of the files and functionalities:

Files:
main.c
This file contains the main program logic. It provides a menu-driven interface for users to interact with the task management system. Users can perform actions such as logging in, creating profiles, managing to-do lists, adding tasks, and saving/loading tasks to/from a file.

task_manager.c
This file contains the implementation of functions related to user and task management. It includes functions for handling login and logout, creating user profiles, managing to-do lists, adding tasks, setting reminders, displaying tasks, and saving/loading tasks to/from a file.

task_manager.h
This header file defines structures and function declarations used in the task management system. It includes structures for users and tasks, as well as declarations for functions related to user and task management.

Functionalities:
User Management:
Login and Logout: Users can log in and out of the system. Only one user can be logged in at a time.

Profile Creation: Users can create profiles by providing a username, password, name, age, and job.

Task Management:
To-Do List: Users can create a to-do list, although the specific implementation is marked as a placeholder and can be extended further.

Add Task: Logged-in users can add tasks with a description, due date, category, labels, and additional notes.

Display Tasks: Users can view a list of tasks, including their description, category, labels, due date, completion status, and reminder status.

Set Reminder: Users can set a reminder for a specific task.

File I/O:
Save and Load Tasks: Users can save tasks to a file (tasks.txt) and load tasks from a file. The file format is a simple text-based format, with one line per task.
