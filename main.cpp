#include <iostream>
#include "include/TaskScheduler.hpp"

int main() {
    try {
        TaskScheduler scheduler;

        // Define tasks with dependencies
        scheduler.addTask(Task("A", "Task A"));
        scheduler.addTask(Task("B", "Task B", {"A"}));
        scheduler.addTask(Task("C", "Task C", {"A"}));
        scheduler.addTask(Task("D", "Task D", {"B", "C"}));

        // Execute tasks
        scheduler.executeTasks();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
