/* 
maze.cpp

Author:

Short description of this file:
*/

#include <iostream>
#include "mazeio.h"

using namespace std;

// Prototype for maze_search, which you will fill in below.
int maze_search(char**, int, int);

// main function to read, solve maze, and print result
int main()
{
    int rows, cols, result;
    char** mymaze;
    rols = 3;
    colms = 4;
    mymaze = read_maze(&rows,&cols);
    
    if (mymaze == NULL)
    {
        cout << "Error, input format incorrect" << endl;
        return 1;
    }
    

    // when working on Checkpoint 3, you will call maze_search here.
    // here. but for Checkpoint 1, just assume we found the path.
    result = maze_search(mymaze, rols, cols); // TO BE CHANGED

    // examine value returned by maze_search and print appropriate output
    if (result == 1) { // path found!
    print_maze(mymaze, rows, cols);
    }
    else if (result == 0) { // no path :(
    cout << "No path could be found!" << endl;
    }
    else { // result == -1
    cout << "Invalid maze." << endl;
    }

    // ADD CODE HERE to delete all memory
    // that read_maze allocated


    return 0;
}

/**************************************************
 * Attempt to find shortest path and return:
 *  1 if successful
 *  0 if no path exists
 * -1 if invalid maze (not exactly one S and one F)
 *
 * If path is found fill it in with '*' characters
 *  but don't overwrite the 'S' and 'F' cells
 *************************************************/
int maze_search(char** maze, int rows, int cols) {
    char** pred = new char[rows];
    for(int i = 0; i < rows; i++)
    {
        pred[i] = new char[cols];
    }
    // Find stating point
    Location *start = NULL;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (maze[i][j] == 'S') {
                start
            }
        }
    }
    return 0; // DELETE this stub, it's just for Checkpoint 1 to compile.
}
