#ifndef TASKSCHEDULER_HPP
#define TASKSCHEDULER_HPP

#include <unordered_map>
#include <vector>
#include <queue>
#include <mutex>
#include "Task.hpp"
#include "ThreadPool.hpp"

class TaskScheduler {
public:
    // Add a task to the scheduler
    void addTask(const Task& task);

    // Execute tasks respecting dependencies
    void executeTasks();

private:
    std::unordered_map<std::string, Task> tasks; // All tasks
    ThreadPool threadPool;                      // Thread pool for concurrent execution

    // Perform topological sorting to resolve dependencies
    std::vector<std::string> resolveDependencies();

    // Execute a single task
    void executeTask(const std::string& taskId);
};

#endif // TASKSCHEDULER_HPP
