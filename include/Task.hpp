#ifndef TASK_HPP
#define TASK_HPP

#include <string>
#include <vector>

struct Task {
    std::string id;               // Unique identifier for the task
    std::string description;      // Description of the task
    std::vector<std::string> dependencies; // List of task IDs this task depends on
    bool completed;               // Flag to indicate if the task is completed

    // Constructor
    Task(const std::string& taskId, const std::string& desc,
         const std::vector<std::string>& deps = {})
        : id(taskId), description(desc), dependencies(deps), completed(false) {}
};

#endif // TASK_HPP
