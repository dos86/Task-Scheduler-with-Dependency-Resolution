#include "TaskScheduler.hpp"
#include <unordered_map>
#include <queue>
#include <iostream>

void TaskScheduler::addTask(const Task& task) {
    tasks[task.id] = task;
}

std::vector<std::string> TaskScheduler::resolveDependencies() {
    std::unordered_map<std::string, int> inDegree;
    std::unordered_map<std::string, std::vector<std::string>> adjList;

    // Initialize in-degree and adjacency list
    for (const auto& [id, task] : tasks) {
        inDegree[id] = 0;
    }
    for (const auto& [id, task] : tasks) {
        for (const auto& dep : task.dependencies) {
            adjList[dep].push_back(id);
            inDegree[id]++;
        }
    }

    // Perform topological sorting using Kahn's algorithm
    std::queue<std::string> zeroInDegree;
    for (const auto& [id, degree] : inDegree) {
        if (degree == 0) {
            zeroInDegree.push(id);
        }
    }

    std::vector<std::string> sortedTasks;
    while (!zeroInDegree.empty()) {
        std::string current = zeroInDegree.front();
        zeroInDegree.pop();
        sortedTasks.push_back(current);

        for (const auto& neighbor : adjList[current]) {
            if (--inDegree[neighbor] == 0) {
                zeroInDegree.push(neighbor);
            }
        }
    }

    // Check for cycles
    if (sortedTasks.size() != tasks.size()) {
        throw std::runtime_error("Cycle detected in task dependencies!");
    }

    return sortedTasks;
}

void TaskScheduler::executeTask(const std::string& taskId) {
    Task& task = tasks[taskId];
    std::cout << "Executing Task ID: " << task.id << ", Description: " << task.description << "\n";
    task.completed = true;
}

void TaskScheduler::executeTasks() {
    try {
        std::vector<std::string> sortedTasks = resolveDependencies();

        for (const auto& taskId : sortedTasks) {
            threadPool.enqueue([this, taskId]() { executeTask(taskId); });
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}
