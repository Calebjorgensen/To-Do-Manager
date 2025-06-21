#include <iostream>
#include <vector>
#include <string>
#include "task.h"

void displayTasks(const std::vector<Task>& tasks) {
    std::cout << "\n--- To-Do List ---\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i].getDescription()
                  << " [" << (tasks[i].getStatus() ? "Done" : "Pending") << "]\n";
    }
}

int main() {
    std::vector<Task> tasks;
    int choice;
    std::string input;

    while (true) {
        std::cout << "\n1. Add Task\n2. View Tasks\n3. Mark Task Done\n4. Exit\nChoose an option: ";
        std::cin >> choice;
        std::cin.ignore(); // clear newline character from buffer

        if (choice == 1) {
            std::cout << "Enter task description: ";
            std::getline(std::cin, input);
            tasks.emplace_back(input);
        } else if (choice == 2) {
            displayTasks(tasks);
        } else if (choice == 3) {
            displayTasks(tasks);
            std::cout << "Enter task number to mark done: ";
            size_t num;
            std::cin >> num;
            if (num > 0 && num <= tasks.size()) {
                tasks[num - 1].markDone();
            } else {
                std::cout << "Invalid task number.\n";
            }
        } else if (choice == 4) {
            std::cout << "Goodbye!\n";
            break;
        } else {
            std::cout << "Invalid choice.\n";
        }
    }

    return 0;
}
