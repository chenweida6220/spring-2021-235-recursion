#include <iostream>
#include <iomanip>      // std::setw for field width
#include <string>       // to_string
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

// void knightsTour() {
//
// }

void moveKnight(int row, int col, int move) {

board[0][0] = "[" + to_string(move) + "]";

    if (row + 1 > -1 && row + 1 < 5 && col + 2 > -1 && col + 2 < 5 && board[row + 1][col + 2] == "[]") {
        move++;
        row += 1;
        col += 2;
        board[row][col] = "[" + to_string(move) + "]";
        cout << endl << endl;
        printBoard();
        moveKnight(row, col, move);
    }

    else if (row + 1 > -1 && row + 1 < 5 && col - 2 > -1 && col - 2 < 5 && board[row + 1][col - 2] == "[]") {
        move++;
        row += 1;
        col -= 2;
        board[row][col] = "[" + to_string(move) + "]";
        cout << endl << endl;
        printBoard();
        moveKnight(row, col, move);
    }

    else if (row - 1 > -1 && row - 1 < 5 && col + 2 > -1 && col + 2 < 5 && board[row - 1][col + 2] == "[]") {
        move++;
        row -= 1;
        col += 2;
        board[row][col] = "[" + to_string(move) + "]";
        cout << endl << endl;
        printBoard();
        moveKnight(row, col, move);
    }

    else if (row - 1 > -1 && row - 1 < 5 && col - 2 > -1 && col - 2 < 5 && board[row - 1][col - 2] == "[]") {
        move++;
        row -= 1;
        col -= 2;
        board[row][col] = "[" + to_string(move) + "]";
        cout << endl << endl;
        printBoard();
        moveKnight(row, col, move);
    }

    else if (row - 2 > -1 && row - 2 < 5 && col + 1 > -1 && col + 1 < 5 && board[row - 2][col + 1] == "[]") {
        move++;
        row -= 2;
        col += 1;
        board[row][col] = "[" + to_string(move) + "]";
        cout << endl << endl;
        printBoard();
        moveKnight(row, col, move);
    }

    else if (row - 2 > -1 && row - 2 < 5 && col - 1 > -1 && col - 1 < 5 && board[row - 2][col - 1] == "[]") {
        move++;
        row -= 2;
        col -= 1;
        board[row][col] = "[" + to_string(move) + "]";
        cout << endl << endl;
        printBoard();
        moveKnight(row, col, move);
    }

    else if (row + 2 > -1 && row + 2 < 5 && col + 1 > -1 && col + 1 < 5 && board[row + 2][col + 1] == "[]") {
        move++;
        row += 2;
        col += 1;
        board[row][col] = "[" + to_string(move) + "]";
        cout << endl << endl;
        printBoard();
        moveKnight(row, col, move);
    }

    else if (row + 2 > -1 && row + 2 < 5 && col - 1 > -1 && col - 1 < 5 && board[row + 2][col - 1] == "[]") {
        move++;
        row += 2;
        col -= 1;
        board[row][col] = "[" + to_string(move) + "]";
        cout << endl << endl;
        printBoard();
        moveKnight(row, col, move);
    }
}
