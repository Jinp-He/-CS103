/* 
maze.cpp

Author:

Short description of this file:
*/

#include <iostream>
#include "mazeio.h"
#include "queue.h"

using namespace std;

// Prototype for maze_search, which you will fill in below.
int maze_search(char**, int, int);
bool contains(Location*, int, Location);
void changematrix(char**,Location**,int,int);

// main function to read, solve maze, and print result
int main()
{
    int rows, cols, result;
    char** mymaze;
    rows = 5;
    cols = 5;
    mymaze = read_maze(&rows,&cols);
    
    if (mymaze == NULL)
    {
        cout << "Error, input format incorrect" << endl;
        return 1;
    }
    // when working on Checkpoint 3, you will call maze_search here.
    // here. but for Checkpoint 1, just assume we found the path.
    result = maze_search(mymaze, rows, cols); // TO BE CHANGED

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
    for (int i = 0; i < rows; i++)
    {
        delete [] mymaze[i];
    }
    delete [] mymaze;
    // delete pred[][] and mymaze[][] after all finished and visited 傻逼！
    return 0;
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

int maze_search(char** maze, int rows, int cols)
{
    Location** pred = new Location*[rows];
    Location* visited = new Location[rows * cols];
    int visitHead = 0;
    bool foundit;
    for(int i = 0; i < rows; i++)
    {
        pred[i] = new Location[cols];
    }
    // Find starting point
    Location start;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (maze[i][j] == 'S')
            {
                start.row = i;
                start.col = j;
                break;
            }
        }
    }
    Queue que = rows * cols;
    que.add_to_back(start);
    
    while(!(que.is_empty()))
    {
        visited[visitHead] = que.remove_from_front();
        Location target = visited[visitHead];
        visitHead++;
        if (target.row - 1 > 0)
        {
            Location targetW;
            targetW.row = target.row - 1;
            targetW.col = target.col;
            if (maze[targetW.row][targetW.col] == 'F')
            {
                cout << "Found it!" << targetW.row << " " << targetW.col << endl;
                pred[targetW.row][targetW.col].col = target.col;
                pred[targetW.row][targetW.col].row = target.row;
                changematrix(maze, pred, targetW.row, targetW.col);
                break;
            }
            if ((maze[targetW.row][targetW.col] == '.')&&(!(contains(visited,visitHead, targetW))))
            {
                que.add_to_back(targetW);
                pred[targetW.row][targetW.col].col = target.col;
                pred[targetW.row][targetW.col].row = target.row;
            }
        }
        if (target.row + 1 < rows)
        {
            Location targetE;
            targetE.row = target.row + 1;
            targetE.col = target.col;
            if (maze[targetE.row][targetE.col] == 'F')
            {
                cout << "Found it!" << targetE.row << " " << targetE.col << endl;
                pred[targetE.row][targetE.col].col = target.col;
                pred[targetE.row][targetE.col].row = target.row;
                changematrix(maze, pred, targetE.row, targetE.col);
                break;
            }
            if ((maze[targetE.row][targetE.col] == '.')&&(!(contains(visited,visitHead, targetE))))
            {
                que.add_to_back(targetE);
                pred[targetE.row][targetE.col].col = target.col;
                pred[targetE.row][targetE.col].row = target.row;
            }
        }
        if (target.col - 1 > 0)
        {
            Location targetN;
            targetN.row = target.row;
            targetN.col = target.col-1;
            if (maze[targetN.row][targetN.col] == 'F')
            {
                cout << "Found it!" << targetN.row << " " << targetN.col << endl;
                pred[targetN.row][targetN.col].col = target.col;
                pred[targetN.row][targetN.col].row = target.row;
                changematrix(maze, pred, targetN.row, targetN.col);
                break;
            }
            if ((maze[targetN.row][targetN.col] == '.')&(!(contains(visited,visitHead, targetN))))
            {
                que.add_to_back(targetN);
                pred[targetN.row][targetN.col].col = target.col;
                pred[targetN.row][targetN.col].row = target.row;
            }
        }
        if (target.col + 1 < cols)
        {
            Location targetS;
            targetS.row = target.row;
            targetS.col = target.col+1;
            if (maze[targetS.row][targetS.col] == 'F')
            {
                cout << "Found it!" << targetS.row << " " << targetS.col << endl;
                pred[targetS.row][targetS.col].col = target.col;
                pred[targetS.row][targetS.col].row = target.row;
                changematrix(maze, pred, targetS.row, targetS.col);
                break;
            }
            if ((maze[targetS.row][targetS.col] == '.')&&(!(contains(visited,visitHead, targetS))))
            {
                que.add_to_back(targetS);
                pred[targetS.row][targetS.col].col = target.col;
                pred[targetS.row][targetS.col].row = target.row;
            }
        }
    }
    
    for (int i = 0; i < rows; i++)
    {
        delete [] pred[i];
    }
    delete [] pred;
    delete [] visited;
    // delete pred[][] and mymaze[][] after all finished and visited 傻逼！
    return 1;
}
bool contains(Location* visited, int visitHead, Location target)
{
    for (int i = 0; i < visitHead; i++)
    {
        if(visited[i].col == target.col && visited[i].row == target.row)
            return true;
    }
    return false;
}

void changematrix(char** maze,Location** pred,int row,int col)
{
    Location search = pred[row][col];
    while (true)
    {
        if(maze[search.row][search.col] == 'S')
            break;
        maze[search.row][search.col] = '*';
        search = pred[search.row][search.col];
    }
}
