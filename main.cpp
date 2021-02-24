#include <iostream>
using namespace std;

void out_board(char x1, char x2, int y1, int y2);

int main()
{
    out_board(0, 0, 0, 0);
    char x1 = 'a', x2 = 'a', d;
    int y1 = 2, y2 = 3;
    // cin >> x1 >> y1 >> d >> x2 >> y2;
}

void out_board(char x1, char x2, int y1, int y2)
{
    char board[9][9]
            = {{'8', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
               {'7', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
               {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'2', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
               {'1', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
               {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j)
            cout << board[i][j] << ' ';
        cout << endl;
    }
    for (int i = 0; i < 20; ++i)
        cout << "_";
    cout << endl;
}
