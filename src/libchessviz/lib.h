#pragma once

int TransX(char x);
int TransY(int y);
void dash();
void out_board(char board[9][9]);
void Motion(char board[9][9], char x1, char x2, int y1, int y2);
int CheckRangeX(char x1, char x2, char x3, char x4);
int CheckRangeY(int y1, int y2, int y3, int y4);
