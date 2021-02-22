#include <iostream>
#include <iomanip>      // std::setw for field width
#include <string>       // to_string
#include <algorithm>    // find
#include <vector>       // vector
#include <cstdlib>      // random
using namespace std;

#include "knights.h"

string board[5][5];

void createBoard() {
  for (int row = 0; row < 5; row++) {
    for (int col = 0; col < 5; col++) {
      board[row][col] = "[]";
    }
  }
}

void printBoard() {
  for (int row = 0; row < 5; row++) {
    for (int col = 0; col < 5; col++) {
      cout << setw(3) << board[row][col] << " ";
    }
    cout << endl;
  }
}

int row;
int col;
int numMove;

// initializing initial position of knight
void startKnight(int startingPosition) {
  numMove = startingPosition;

  switch(startingPosition) {
    case 1:
      board[0][3] = "[" + to_string(startingPosition) + "]";
      row = 0;
      col = 3;
      roamKnight(row, col);
      break;
    case 2:
      board[1][4] = "[" + to_string(startingPosition) + "]";
      row = 1;
      col = 4;
      roamKnight(row, col);
      break;
    case 3:
      board[3][4] = "[" + to_string(startingPosition) + "]";
      row = 3;
      col = 4;
      roamKnight(row, col);
      break;
    case 4:
      board[4][3] = "[" + to_string(startingPosition) + "]";
      row = 4;
      col = 3;
      roamKnight(row, col);
      break;
    case 5:
      board[4][1] = "[" + to_string(startingPosition) + "]";
      row = 4;
      col = 1;
      roamKnight(row, col);
      break;
    case 6:
      board[3][0] = "[" + to_string(startingPosition) + "]";
      row = 3;
      col = 0;
      roamKnight(row, col);
      break;
    case 7:
      board[1][0] = "[" + to_string(startingPosition) + "]";
      row = 1;
      col = 0;
      roamKnight(row, col);
      break;
    case 8:
      board[0][1] = "[" + to_string(startingPosition) + "]";
      row = 0;
      col = 1;
      roamKnight(row, col);
      break;
  }
}

// moving knight
void roamKnight(int x, int y) {
  cout << endl;

    if (row + 1 > -1 && row + 1 < 5 && col + 2 > -1 && col + 2 < 5 && board[row + 1][col + 2] == "[]") {
        numMove++;
        row += 1;
        col += 2;
        board[row][col] = "[" + to_string(numMove) + "]";

        // check if move results in no other possible moves
        // if valid, print and proceed with move
        if (isValid(row, col)) {
          printBoard();
          roamKnight(row, col);
        }
        // if invalid, resets to default
        else {
          numMove--;
          board[row][col] = "[]";
          row -= 1;
          col -= 2;

          while (!isValid(row, col)) {
            generateNewRowCol(row, col);
            printBoard();
            roamKnight(row, col);
          }
        }
    }
    else if (row + 1 > -1 && row + 1 < 5 && col - 2 > -1 && col - 2 < 5 && board[row + 1][col - 2] == "[]") {
        numMove++;
        row += 1;
        col -= 2;
        board[row][col] = "[" + to_string(numMove) + "]";
        printBoard();
        roamKnight(row, col);

        if (isValid(row, col)) {
          printBoard();
          roamKnight(row, col);
        }
        else {
          numMove--;
          board[row][col] = "[]";
          row -= 1;
          col += 2;

          while (!isValid(row, col)) {
            generateNewRowCol(row, col);
            printBoard();
            roamKnight(row, col);
          }
        }
    }
    else if (row - 1 > -1 && row - 1 < 5 && col + 2 > -1 && col + 2 < 5 && board[row - 1][col + 2] == "[]") {
        numMove++;
        row -= 1;
        col += 2;
        board[row][col] = "[" + to_string(numMove) + "]";
        printBoard();
        roamKnight(row, col);

        // check if move results in no other possible moves
        if (isValid(row, col)) {
          printBoard();
          roamKnight(row, col);
        }
        else {
          numMove--;
          board[row][col] = "[]";
          row += 1;
          col -= 2;

          while (!isValid(row, col)) {
            generateNewRowCol(row, col);
            printBoard();
            roamKnight(row, col);
          }
        }
    }
    else if (row - 1 > -1 && row - 1 < 5 && col - 2 > -1 && col - 2 < 5 && board[row - 1][col - 2] == "[]") {
        numMove++;
        row -= 1;
        col -= 2;
        board[row][col] = "[" + to_string(numMove) + "]";
        printBoard();
        roamKnight(row, col);

        // check if move results in no other possible moves
        if (isValid(row, col)) {
          printBoard();
          roamKnight(row, col);
        }
        else {
          numMove--;
          board[row][col] = "[]";
          row += 1;
          col += 2;

          while (!isValid(row, col)) {
            generateNewRowCol(row, col);
            printBoard();
            roamKnight(row, col);
          }
        }
    }
    else if (row - 2 > -1 && row - 2 < 5 && col + 1 > -1 && col + 1 < 5 && board[row - 2][col + 1] == "[]") {
        numMove++;
        row -= 2;
        col += 1;
        board[row][col] = "[" + to_string(numMove) + "]";
        printBoard();
        roamKnight(row, col);

        // check if move results in no other possible moves
        if (isValid(row, col)) {
          printBoard();
          roamKnight(row, col);
        }
        else {
          numMove--;
          board[row][col] = "[]";
          row += 2;
          col -= 1;

          while (!isValid(row, col)) {
            generateNewRowCol(row, col);
            printBoard();
            roamKnight(row, col);
          }
        }
    }
    else if (row - 2 > -1 && row - 2 < 5 && col - 1 > -1 && col - 1 < 5 && board[row - 2][col - 1] == "[]") {
        numMove++;
        row -= 2;
        col -= 1;
        board[row][col] = "[" + to_string(numMove) + "]";
        printBoard();
        roamKnight(row, col);

        // check if move results in no other possible moves
        if (isValid(row, col)) {
          printBoard();
          roamKnight(row, col);
        }
        else {
          numMove--;
          board[row][col] = "[]";
          row += 2;
          col -= 1;

          while (!isValid(row, col)) {
            generateNewRowCol(row, col);
            printBoard();
            roamKnight(row, col);
          }
        }
    }
    else if (row + 2 > -1 && row + 2 < 5 && col + 1 > -1 && col + 1 < 5 && board[row + 2][col + 1] == "[]") {
        numMove++;
        row += 2;
        col += 1;
        board[row][col] = "[" + to_string(numMove) + "]";
        printBoard();
        roamKnight(row, col);

        // check if move results in no other possible moves
        if (isValid(row, col)) {
          printBoard();
          roamKnight(row, col);
        }
        else {
          numMove--;
          board[row][col] = "[]";
          row -= 2;
          col -= 1;

          while (!isValid(row, col)) {
            generateNewRowCol(row, col);
            printBoard();
            roamKnight(row, col);
          }
        }
    }
    else if (row + 2 > -1 && row + 2 < 5 && col - 1 > -1 && col - 1 < 5 && board[row + 2][col - 1] == "[]") {
        numMove++;
        row += 2;
        col -= 1;
        board[row][col] = "[" + to_string(numMove) + "]";
        printBoard();
        roamKnight(row, col);

        // check if move results in no other possible moves
        if (isValid(row, col)) {
          printBoard();
          roamKnight(row, col);
        }
        else {
          numMove--;
          board[row][col] = "[]";
          row -= 2;
          col += 1;

          while (!isValid(row, col)) {
            generateNewRowCol(row, col);
            printBoard();
            roamKnight(row, col);
          }
        }
    }
}

bool isValid(int x, int y) {
  if (row + 1 > -1 && row + 1 < 5 && col + 2 > -1 && col + 2 < 5 && board[row + 1][col + 2] == "[]") {
      return true;
  }
  else if (row + 1 > -1 && row + 1 < 5 && col - 2 > -1 && col - 2 < 5 && board[row + 1][col - 2] == "[]") {
      return true;
  }
  else if (row - 1 > -1 && row - 1 < 5 && col + 2 > -1 && col + 2 < 5 && board[row - 1][col + 2] == "[]") {
      return true;
  }
  else if (row - 1 > -1 && row - 1 < 5 && col - 2 > -1 && col - 2 < 5 && board[row - 1][col - 2] == "[]") {
      return true;
  }
  else if (row - 2 > -1 && row - 2 < 5 && col + 1 > -1 && col + 1 < 5 && board[row - 2][col + 1] == "[]") {
      return true;
  }
  else if (row - 2 > -1 && row - 2 < 5 && col - 1 > -1 && col - 1 < 5 && board[row - 2][col - 1] == "[]") {
      return true;
  }
  else if (row + 2 > -1 && row + 2 < 5 && col + 1 > -1 && col + 1 < 5 && board[row + 2][col + 1] == "[]") {
      return true;
  }
  else if (row + 2 > -1 && row + 2 < 5 && col - 1 > -1 && col - 1 < 5 && board[row + 2][col - 1] == "[]") {
      return true;
  }
  else {
    return false;
  }
}

vector<int> vecRows {2, 1, -1, -2, -2, -1, 1, 2};
vector<int> vecCols {1, 2, 2, 1, -1, -2, -2, -1};

void generateNewRowCol(int x, int y) {
  // Iterator used to store the position of searched element
  vector<int>::iterator itRow = find(vecRows.begin(), vecRows.end(), x);
  vector<int>::iterator itCol = find(vecCols.begin(), vecCols.end(), y);
  int xIndex = itRow - vecRows.begin();
  int yIndex = itCol - vecCols.begin();

  // if x and y have the same index, remove them from both vectors
  if (xIndex == yIndex) {
    vecRows.erase(vecRows.begin() + xIndex);
    vecRows.erase(vecCols.begin() + yIndex);
  }

  srand(time(0));
  while(!isValid(row, col)) {
    row = vecRows[rand()%((7 - 0))];
    col = vecCols[rand()%((7 - 0))];
    generateNewRowCol(row, col);
  }

  // defaulted for next usage
  vecRows = {2, 1, -1, -2, -2, -1, 1, 2};
  vecCols = {1, 2, 2, 1, -1, -2, -2, -1};
}

// if (row + 1 > -1 && row + 1 < 5 && col + 2 > -1 && col + 2 < 5 && board[row + 1][col + 2] == "[]") {
//     return true;
// }
// else if (row + 1 > -1 && row + 1 < 5 && col - 2 > -1 && col - 2 < 5 && board[row + 1][col - 2] == "[]") {
//     return true;
// }
// else if (row - 1 > -1 && row - 1 < 5 && col + 2 > -1 && col + 2 < 5 && board[row - 1][col + 2] == "[]") {
//     return true;
// }
// else if (row - 1 > -1 && row - 1 < 5 && col - 2 > -1 && col - 2 < 5 && board[row - 1][col - 2] == "[]") {
//     return true;
// }
// else if (row - 2 > -1 && row - 2 < 5 && col + 1 > -1 && col + 1 < 5 && board[row - 2][col + 1] == "[]") {
//     return true;
// }
// else if (row - 2 > -1 && row - 2 < 5 && col - 1 > -1 && col - 1 < 5 && board[row - 2][col - 1] == "[]") {
//     return true;
// }
// else if (row + 2 > -1 && row + 2 < 5 && col + 1 > -1 && col + 1 < 5 && board[row + 2][col + 1] == "[]") {
//     return true;
// }
// else if (row + 2 > -1 && row + 2 < 5 && col - 1 > -1 && col - 1 < 5 && board[row + 2][col - 1] == "[]") {
//     return true;
// }
// else {
//   return false;
// }
