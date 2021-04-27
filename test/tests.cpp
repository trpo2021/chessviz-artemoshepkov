#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <libchessviz/lib.h>

struct coord {
  char type, x1, x2, sign;
  int y1, y2;
};

TEST_CASE("TransX() function must return the corresponding X coordinate")
{
  REQUIRE(TransX('a') == 1);
  REQUIRE(TransX('l') == 0);
}

TEST_CASE("TransY() function must return the corresponding Y coordinate")
{
  REQUIRE(TransY(1) == 7);
  REQUIRE(TransY(19) == -1);
}

TEST_CASE("CheckRangeX() function should return 1 if the X coordinates given by the user do not fall out of the range of the board boundaries, otherwise it will return 0")
{
  coord test1, test2;

  test1.x1 = 'a'; test1.x2 = 'b';
  test2.x1 = 'c'; test2.x2 = 'd';
  REQUIRE(CheckRangeX(test1, test2) == 1);

  test1.x1 = 'e'; test1.x2 = 'f';
  test2.x1 = 'g'; test2.x2 = 'h';
  REQUIRE(CheckRangeX(test1, test2) == 1);

  test1.x1 = 't'; test1.x2 = 'b';
  test2.x1 = 'c'; test2.x2 = 'd';
  REQUIRE(CheckRangeX(test1, test2) == 0);

  test1.x1 = 'a'; test1.x2 = 't';
  test2.x1 = 'c'; test2.x2 = 'd';
  REQUIRE(CheckRangeX(test1, test2) == 0);

  test1.x1 = 'a'; test1.x2 = 'b';
  test2.x1 = 't'; test2.x2 = 'd';
  REQUIRE(CheckRangeX(test1, test2) == 0);

  test1.x1 = 'a'; test1.x2 = 'b';
  test2.x1 = 'c'; test2.x2 = 't';
  REQUIRE(CheckRangeX(test1, test2) == 0);
}

TEST_CASE("CheckRangeY() function should return 1 if the Y coordinates given by the user do not fall out of the range of the board boundaries, otherwise it will return 0")
{
  coord test1, test2;

  test1.y1 = 1; test1.y2 = 2;
  test2.y1 = 3; test2.y2 = 4;
  REQUIRE(CheckRangeY(test1, test2) == 1);

  test1.y1 = 5; test1.y2 = 6;
  test2.y1 = 7; test2.y2 = 8;
  REQUIRE(CheckRangeY(test1, test2) == 1);

  test1.y1 = 10; test1.y2 = 2;
  test2.y1 = 3; test2.y2 = 4;
  REQUIRE(CheckRangeY(test1, test2) == 0);

  test1.y1 = 1; test1.y2 = 10;
  test2.y1 = 3; test2.y2 = 4;
  REQUIRE(CheckRangeY(test1, test2) == 0);

  test1.y1 = 1; test1.y2 = 2;
  test2.y1 = 10; test2.y2 = 4;
  REQUIRE(CheckRangeY(test1, test2) == 0);

  test1.y1 = 1; test1.y2 = 2;
  test2.y1 = 3; test2.y2 = 10;
  REQUIRE(CheckRangeY(test1, test2) == 0);
}

TEST_CASE("CheckType() function should return 1 if the shape type entered by the user matches the shape on the board, otherwise 0 is output")
{
  char board[9][9] = { {'8', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                       {'7', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                       {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {'4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {'2', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                       {'1', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                       {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'} };
  coord test1, test2;

  test1.x1 = 'a'; test1.y1 = 1; test1.type = 'R';
  test2.x1 = 'h'; test2.y1 = 8; test2.type = 'r';
  REQUIRE(CheckType(board, test1, test2) == 1);

  test1.x1 = 'd'; test1.y1 = 2; test1.type = 'P';
  test2.x1 = 'd'; test2.y1 = 8; test2.type = 'q';
  REQUIRE(CheckType(board, test1, test2) == 1);

  test1.x1 = 'd'; test1.y1 = 1; test1.type = 'r';
  test2.x1 = 'd'; test2.y1 = 7; test2.type = 'R';
  REQUIRE(CheckType(board, test1, test2) == 0);

  test1.x1 = 'a'; test1.y1 = 1; test1.type = 'r';
  test2.x1 = 'b'; test2.y1 = 1; test2.type = 'R';
  REQUIRE(CheckType(board, test1, test2) == 0);
}
