#include <iostream>
#include <iomanip>      // std::setw for field width
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

// void moveKnight
