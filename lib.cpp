#include "lib.h"
#include <iostream>
using namespace std;

int TransX(char x)
{
    switch (x) {
    case 'a':
        x = 1;
        break;
    case 'b':
        x = 2;
        break;
    case 'c':
        x = 3;
        break;
    case 'd':
        x = 4;
        break;
    case 'e':
        x = 5;
        break;
    case 'f':
        x = 6;
        break;
    case 'g':
        x = 7;
        break;
    case 'h':
        x = 8;
        break;
    }
    return x;
}

int TransY(int y)
{
    switch (y) {
    case 1:
        y = 7;
        break;
    case 2:
        y = 6;
        break;
    case 3:
        y = 5;
        break;
    case 4:
        y = 4;
        break;
    case 5:
        y = 3;
        break;
    case 6:
        y = 2;
        break;
    case 7:
        y = 1;
        break;
    case 8:
        y = 0;
        break;
    }
    return y;
}

void out_board(char board[9][9])
{
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j)
            cout << board[i][j] << ' ';
        cout << endl;
    }
    for (int i = 0; i < 20; ++i)
        cout << "_";
    cout << endl;
}

void Motion(char board[9][9], char x1, char x2, int y1, int y2)
{
    board[TransY(y2)][TransX(x2)] = board[TransY(y1)][TransX(x1)];
    board[TransY(y1)][TransX(x1)] = ' ';
}
