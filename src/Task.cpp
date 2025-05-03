#include "Task.hpp"
#include <iostream>

// Print task details (for debugging/logging)
void printTask(const Task& task) {
    std::cout << "Task ID: " << task.id << ", Description: " << task.description
              << ", Dependencies: ";
    for (const auto& dep : task.dependencies) {
        std::cout << dep << " ";
    }
    std::cout << "\n";
}
