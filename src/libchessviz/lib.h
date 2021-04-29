#pragma once
const int N = 9;
int TransX(char x);
int TransY(int y);
void dash();
void out_board(char board[N][N]);
void Motion(char board[N][N], coord str);
int CheckRangeX(coord first, coord second);
int CheckRangeY(coord first, coord second);
int CheckType (char board[N][N], coord first, coord second);
