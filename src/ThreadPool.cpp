#include "ThreadPool.hpp"
#include <iostream>

ThreadPool::ThreadPool(size_t numThreads) : stopFlag(false) {
    for (size_t i = 0; i < numThreads; ++i) {
        workers.emplace_back([this]() { worker(); });
    }
}

ThreadPool::~ThreadPool() {
    {
        std::unique_lock<std::mutex> lock(mutex);
        stopFlag = true;
    }
    cv.notify_all();
    for (std::thread& workerThread : workers) {
        if (workerThread.joinable()) {
            workerThread.join();
        }
    }
}

void ThreadPool::enqueue(std::function<void()> task) {
    {
        std::unique_lock<std::mutex> lock(mutex);
        tasks.push(task);
    }
    cv.notify_one();
}

void ThreadPool::worker() {
    while (true) {
        std::function<void()> task;
        {
            std::unique_lock<std::mutex> lock(mutex);
            cv.wait(lock, [this]() { return stopFlag || !tasks.empty(); });
            if (stopFlag && tasks.empty()) {
                return;
            }
            task = std::move(tasks.front());
            tasks.pop();
        }
        task();
    }
}
