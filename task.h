#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
private:
    std::string description;
    bool isDone;

public:
    Task(std::string desc);
    void markDone();
    std::string getDescription() const;
    bool getStatus() const;
};

#endif