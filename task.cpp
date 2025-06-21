#include "task.h"

Task::Task(std::string desc) : description(desc), isDone(false) {}

void Task::markDone() {
    isDone = true;
}

std::string Task::getDescription() const {
    return description;
}

bool Task::getStatus() const {
    return isDone;
}