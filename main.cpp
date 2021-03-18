#include "lib.h"
#include <iostream>
using namespace std;

int main()
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
    out_board(board);

    char x1, x2, d;
    char x3, x4;
    int y1, y2;
    int y3, y4;

    cout << TransX(x1);
    while (1) {
      for (int i = 0; i < 5; ++i) {

      }
        cin >> x1 >> y1 >> d >> x2 >> y2;
        cin >> x3 >> y3 >> d >> x4 >> y4;
        Motion(board, x1, x2, y1, y2);
        Motion(board, x3, x4, y3, y4);
        out_board(board);
    }
}
