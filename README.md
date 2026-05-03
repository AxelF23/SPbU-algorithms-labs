
# SPbU Algorithms & Data Structures Labs

This repository contains a collection of laboratory works and projects developed as part of the **Applied Mathematics and Computer Science** curriculum at St. Petersburg State University.

The projects focus on fundamental data structures, graph theory, and system modeling, emphasizing low-level implementation details and algorithmic efficiency.

## Projects Overview

### 1. Mass Service System Simulation (`mass_service_system`)
A discrete-event simulation of a queuing system (MSS) with two service channels and batch request processing.
*   **Key Features:** Implementation of a custom event-driven engine.
*   **Data Structures:** Queues and event lists are implemented from scratch using raw pointers to demonstrate manual memory management and internal logic.
*   **Logic:** Handles batch arrivals and manages service states for multiple units.

### 2. Graph Eulerian Path Finder (`graph_euler_path`)
An interactive tool for graph construction and the search for Eulerian cycles.
*   **Key Features:** Custom object-oriented architecture representing nodes, edges, and graph logic.
*   **Algorithm:** Efficiently finds a cycle that visits every edge of the graph exactly once.
*   **Visualization:** Includes a GUI components (`clCircle`, `clLine`, `clDraw`) for visual representation of the graph structure.

## Technical Stack
*   **Language:** C++
*   **IDE:** Code::Blocks (Project files included as `.cbp`)
*   **Concepts:** OOP, Memory Management, Graph Theory, Event-Driven Programming.

## How to Run
1.  Navigate to the specific project folder.
2.  Open the `.cbp` file using **Code::Blocks**.
3.  Build and Run the project using the IDE's compiler (GCC/MinGW recommended).

