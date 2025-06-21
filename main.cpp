#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

// Task class definition
class Task {
private:
    std::string description;
    bool isDone;

public:
    Task(std::string desc) : description(desc), isDone(false) {}

    void markDone() {
        isDone = true;
    }

    std::string getDescription() const {
        return description;
    }

    bool getStatus() const {
        return isDone;
    }
};

// Display all tasks
void displayTasks(const std::vector<Task>& tasks) {
    std::cout << "\n--- To-Do List ---\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i].getDescription()
                  << " [" << (tasks[i].getStatus() ? "Done" : "Pending") << "]\n";
    }
}

// Load tasks from file
void loadTasksFromFile(std::vector<Task>& tasks, const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cout << "No existing task file found. Starting fresh.\n";
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        std::string statusStr, desc;
        if (std::getline(iss, statusStr, '|') && std::getline(iss, desc)) {
            Task task(desc);
            if (statusStr == "1") {
                task.markDone();
            }
            tasks.push_back(task);
        }
    }

    inFile.close();
}

// Save tasks to file
void saveTasksToFile(const std::vector<Task>& tasks, const std::string& filename) {
    std::ofstream outFile(filename);
    for (const Task& task : tasks) {
        outFile << (task.getStatus() ? "1" : "0") << "|" << task.getDescription() << "\n";
    }
    outFile.close();
}

// Main program loop
int main() {
    std::vector<Task> tasks;
    std::string filename = "tasks.txt";
    loadTasksFromFile(tasks, filename);

    int choice;
    std::string input;

    while (true) {
        std::cout << "\n1. Add Task\n2. View Tasks\n3. Mark Task Done\n4. Exit\nChoose an option: ";
        std::cin >> choice;
        std::cin.ignore(); // clear newline

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
            saveTasksToFile(tasks, filename);
            std::cout << "Tasks saved. Goodbye!\n";
            break;
        } else {
            std::cout << "Invalid choice.\n";
        }
    }

    return 0;
}