//
//  test.cpp
//  Mazeio
//
//  Created by Jin H on 11/13/17.
//  Copyright © 2017 Jin H. All rights reserved.
//

#include <stdio.h>
#include "mazeio.h"

int main()
{
    int row = 3;
    int col = 4;
    char** maze = read_maze(&row, &col);
    print_maze(maze, row, col);
    return 0;
}
