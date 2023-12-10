# Task Manager

This is a simple task management system written in C. It allows users to create profiles, manage to-do lists, add tasks, set reminders, and more.

## Getting Started

1. Clone the repository: `git clone https://github.com/your-username/your-repository.git`
2. Compile the program: `gcc main.c task_manager.c -o task_manager`
3. Run the program: `./task_manager`

## Features

- **User Authentication:** Users can log in, log out, and create profiles.
- **Task Management:** Users can create to-do lists, add tasks, set reminders, and view tasks.
- **File I/O:** Tasks can be saved to and loaded from a file (`tasks.txt`).

## Usage

- Upon running the program, users are presented with a menu to perform various actions.
- Users can log in, create profiles, manage tasks, and save/load tasks from a file.

## Structure

- `main.c`: Contains the main program logic and the menu interface.
- `task_manager.c`: Implements functions for user authentication, task management, and file I/O.
- `task_manager.h`: Header file containing structures and function declarations.
