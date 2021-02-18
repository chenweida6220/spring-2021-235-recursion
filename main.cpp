#include <iostream>
using namespace std;

#include "knights.h"

/*
.8.1.
7...2
..N..
6...3
.5.4.
*/

int leftoverMoves[8][2];

// 8 locations
void knightsTour(int startingPosition) {
  if (startingPosition == 1) {
    cout << "Starting Position: " <<

    for (int a = 0; a < 9; a++) {
      for (int b = 0; b < 3; b++) {
        if (leftoverMoves[a][b] == {})
      }
    }
  }
  int allMoves[8][2] = {
    {1, 2},
    {1, -2},
    {-1, 2},
    {-1, -2},

    {2, 1},
    {2, -1},
    {-2, 1},
    {-2, -1}
  };

  // for (int i = 0; i < sizeof(allMoves)/sizeof(allMoves[0]); i++) {
  //   leftoverMoves[i] = allMoves[i];
  // }

// copying allMoves to leftoverMoves
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 3; j++) {
      leftoverMoves[i][j] = allMoves[i][j];
    }
  }
}

bool isValid() {

}

void printBoard() {

}

int main() {
  print
}
