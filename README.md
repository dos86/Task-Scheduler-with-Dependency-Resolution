# Task-Scheduler-with-Dependency-Resolution

#### Overview:
This project simulates a **task scheduler** that executes tasks based on their dependencies. Tasks are represented as nodes in a directed acyclic graph (DAG), where edges represent dependencies between tasks. The scheduler ensures that tasks are executed in the correct order, respecting their dependencies. Additionally, the system supports concurrent execution of independent tasks using multithreading.

---

### Key Features:
1. **Task Representation**:
   - Each task has a unique ID, a description, and a list of dependencies (other task IDs it depends on).
   - Tasks are stored in a dependency graph.

2. **Dependency Resolution**:
   - The scheduler resolves task dependencies using **topological sorting** to determine the correct execution order.
   - If a cycle is detected in the dependency graph, the scheduler reports an error.

3. **Concurrent Execution**:
   - Independent tasks (tasks with no unresolved dependencies) are executed concurrently using a thread pool.
   - A thread-safe task queue ensures safe access to shared resources.

4. **STL Usage**:
   - Use `std::unordered_map` to store tasks and their dependencies.
   - Use `std::vector` and `std::queue` for topological sorting and task scheduling.

5. **OOP Design**:
   - Encapsulate tasks and the scheduler in separate classes (`Task` and `TaskScheduler`).
   - Use polymorphism to allow different types of tasks (e.g., computational tasks, I/O tasks).

6. **Error Handling**:
   - Handle invalid inputs, such as duplicate task IDs or cyclic dependencies.
   - Provide meaningful error messages for debugging.

7. **Optional SQL Integration**:
   - Store task definitions and execution logs in a Microsoft SQL Server database for persistence.

---

### Folder Structure:
```
TaskScheduler/
├── include/
│   ├── Task.hpp          // Task class definition
│   ├── TaskScheduler.hpp // Task scheduler class definition
│   └── ThreadPool.hpp    // Thread pool for concurrent task execution
├── src/
│   ├── Task.cpp
│   ├── TaskScheduler.cpp
│   └── ThreadPool.cpp
├── main.cpp              // Main entry point
├── CMakeLists.txt        // Build configuration
└── README.md             // Project documentation
```

---

### Workflow:
1. **Task Definition**:
   - Users define tasks and their dependencies in a configuration file or via the command line.
   - Example:
     ```
     Task A: No dependencies
     Task B: Depends on A
     Task C: Depends on A
     Task D: Depends on B, C
     ```

2. **Dependency Resolution**:
   - The scheduler builds a dependency graph and performs topological sorting to determine the execution order.

3. **Task Execution**:
   - The scheduler executes tasks in the correct order.
   - Independent tasks are executed concurrently using a thread pool.

4. **Logging**:
   - Execution logs are printed to the console or stored in a database for later analysis.

---

### Example Use Case:
- A user defines four tasks:
  - Task A: No dependencies.
  - Task B: Depends on A.
  - Task C: Depends on A.
  - Task D: Depends on B and C.
- The scheduler determines the execution order: A → (B, C) → D.
- Tasks B and C are executed concurrently since they are independent of each other.
- Task D is executed only after both B and C are completed.

---

### Technologies Used:
1. **STL**: `std::unordered_map`, `std::vector`, `std::queue`, `std::thread`, `std::mutex`.
2. **OOP**: Encapsulation and modularity in designing `Task` and `TaskScheduler` classes.
3. **Multithreading**: Concurrent execution of independent tasks using a thread pool.
4. **Graph Algorithms**: Topological sorting for dependency resolution.
5. **SQL (Optional)**: Interaction with Microsoft SQL Server using ODBC for storing task definitions and logs.

---
