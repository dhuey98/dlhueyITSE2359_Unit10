#include <iostream>
using namespace std;

// Constants for the maze dimensions
const int WIDTH = 5;
const int HEIGHT = 5;

// Maze representation
// 0 - Open path
// 1 - Wall
// 2 - Part of the solution path
int maze[HEIGHT][WIDTH] = {
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 1, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0}
};

// Function: printMaze
// Purpose: Display the current state of the maze, showing walls, open paths, and the solution path
void printMaze() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (maze[i][j] == 1) {
                cout << "# ";  // Wall
            } else if (maze[i][j] == 2) {
                cout << ". ";  // Solution path
            } else {
                cout << "  ";  // Open path
            }
        }
        cout << endl;
    }
}

// Function: solveMaze
// Purpose: Recursively finds a solution to the maze using backtracking
// Parameters: (x, y) - starting coordinates within the maze
// Returns: true if a path is found from the start to the goal; otherwise, false
bool solveMaze(int x, int y) {
    // Print current cell for debugging purposes
    cout << "Trying cell (" << x << ", " << y << ")" << endl;

    // Base case: Check if (x, y) is out of bounds or a wall
    if (x < 0 || x >= HEIGHT || y < 0 || y >= WIDTH || maze[x][y] == 1) {
        return false;
    }
    
    // Check if the goal is reached (bottom-right corner)
    if (x == HEIGHT - 1 && y == WIDTH - 1) {
        maze[x][y] = 2; // Mark as part of the solution path
        return true;
    }
    
    // Check if the cell is already part of the solution path to prevent revisiting
    if (maze[x][y] == 2) {
        return false;
    }
    
    // Mark the cell as part of the solution path
    maze[x][y] = 2;

    // Recursive calls: Move in each direction (right, down, left, up)
    if (solveMaze(x, y + 1)) return true; // Move right
    if (solveMaze(x + 1, y)) return true; // Move down
    if (solveMaze(x, y - 1)) return true; // Move left
    if (solveMaze(x - 1, y)) return true; // Move up

    // Backtrack: If no path is found, reset the cell to its original state
    maze[x][y] = 0;
    return false;
}

// Function: main
// Purpose: Initialize the maze solver and display results
int main() {
    // Start the maze solver from the top-left corner
    if (solveMaze(0, 0)) {
        cout << "Path found:\n";
    } else {
        cout << "No path found.\n";
    }
    printMaze();  // Display the maze with the solution path
    return 0;
}