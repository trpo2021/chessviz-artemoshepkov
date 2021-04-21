#include <libchessviz/lib.h>
#include <iostream>
using namespace std;

int TransX(char x) {
    switch (x) {
    case 'a':
        return 1;
    case 'b':
        return 2;
    case 'c':
        return 3;
    case 'd':
        return 4;
    case 'e':
        return 5;
    case 'f':
        return 6;
    case 'g':
        return 7;
    case 'h':
        return 8;
    default:
        return 0;
    }
}
int TransY(int y) {
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
    default:
        y = -1;
    }
    return y;
}

void dash() {
    for (int i = 0; i < 20; ++i)
        cout << "_";
    cout << endl;
}
void out_board(char board[9][9]) {
    dash();
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j)
            cout << board[i][j] << ' ';
        cout << endl;
    }
    dash();
}

void Motion(char board[9][9], char x1, char x2, int y1, int y2) {
    board[TransY(y2)][TransX(x2)] = board[TransY(y1)][TransX(x1)];
    board[TransY(y1)][TransX(x1)] = ' ';
}

int CheckRangeX(char x1, char x2, char x3, char x4) {
    if (TransX(x1) != 0 && TransX(x2) != 0 && TransX(x3) != 0 && TransX(x4) != 0) {
        return 1;
    }
    else
        return 0;
}
int CheckRangeY(int y1, int y2, int y3, int y4) {
    if (TransY(y1) != -1 && TransY(y2) != -1 && TransY(y3) != -1 && TransY(y4) != -1) {
        return 1;
    }
    else
        return 0;
}
