//
//  Test.cpp
//  pointers
//
//  Created by Jin H on 11/10/17.
//  Copyright © 2017 Jin H. All rights reserved.
//
using namespace std;
#include "Test.hpp"
#include <iostream>
#include <sstream>
void printCard(int id)
{
    int typ = id / 13;
    string type,suit;
    switch (typ)
    {
        case 0:
            suit = 'H';
            break;
        case 1:
            suit = 'D';
            break;
        case 2:
            suit = 'C';
            break;
        case 3:
            suit = 'S';
            break;
    }
    typ = id % 13;
    switch (typ)
    {
        case 0:
            type = 'A';
            break;
        case 1:
            type = '2';
            break;
        case 2:
            type = '3';
            break;
        case 3:
            type = '4';
            break;
        case 4:
            type = '5';
            break;
        case 5:
            type = '6';
            break;
        case 6:
            type = '7';
            break;
        case 7:
            type = '8';
            break;
        case 8:
            type = '9';
            break;
        case 9:
            type = '10';
            break;
        case 10:
            type = 'J';
            break;
        case 11:
            type = 'Q';
            break;
        case 12:
            type = 'K';
            break;
    }
    string types = suit + '-' + to_string(typ);
    cout << types << endl;
    
}
int main()
{
    printCard(5);
    return 0;
}
