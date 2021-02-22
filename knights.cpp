#include <iostream>
using namespace std;

const int sizeRow = 6;
const int sizeCol = 6;

int row_delta[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int col_delta[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

int board[sizeRow][sizeCol];

void printBoard() {
    for (int i = 0; i < sizeRow; i++) {
        for (int j = 0; j < sizeCol; j++) {
            if (board[i][j] < 10)
                cout << ' ';
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
    cin.get();
}

// bool isValid(int x, int y) {
//   if (
//        (row + 1 > -1 && row + 1 < 5 && col + 2 > -1 && col + 2 < 5 && board[row + 1][col + 2] == "[]")
//     || (row + 1 > -1 && row + 1 < 5 && col - 2 > -1 && col - 2 < 5 && board[row + 1][col - 2] == "[]")
//     || (row - 1 > -1 && row - 1 < 5 && col + 2 > -1 && col + 2 < 5 && board[row - 1][col + 2] == "[]")
//     || (row - 1 > -1 && row - 1 < 5 && col - 2 > -1 && col - 2 < 5 && board[row - 1][col - 2] == "[]")
//     || (row - 2 > -1 && row - 2 < 5 && col + 1 > -1 && col + 1 < 5 && board[row - 2][col + 1] == "[]")
//     || (row - 2 > -1 && row - 2 < 5 && col - 1 > -1 && col - 1 < 5 && board[row - 2][col - 1] == "[]")
//     || (row + 2 > -1 && row + 2 < 5 && col + 1 > -1 && col + 1 < 5 && board[row + 2][col + 1] == "[]")
//     || (row + 2 > -1 && row + 2 < 5 && col - 1 > -1 && col - 1 < 5 && board[row + 2][col - 1] == "[]")
//   ) {
//     return true;
//   }
//
//   return false;
// }
//
// // initializing initial position of knight
// void startKnight(int startingPosition) {
//   numMove = startingPosition;
//
//   switch(startingPosition) {
//     case 1:
//       board[0][3] = "[" + to_string(startingPosition) + "]";
//       row = 0;
//       col = 3;
//       roamKnight(row, col);
//       break;
//     case 2:
//       board[1][4] = "[" + to_string(startingPosition) + "]";
//       row = 1;
//       col = 4;
//       roamKnight(row, col);
//       break;
//     case 3:
//       board[3][4] = "[" + to_string(startingPosition) + "]";
//       row = 3;
//       col = 4;
//       roamKnight(row, col);
//       break;
//     case 4:
//       board[4][3] = "[" + to_string(startingPosition) + "]";
//       row = 4;
//       col = 3;
//       roamKnight(row, col);
//       break;
//     case 5:
//       board[4][1] = "[" + to_string(startingPosition) + "]";
//       row = 4;
//       col = 1;
//       roamKnight(row, col);
//       break;
//     case 6:
//       board[3][0] = "[" + to_string(startingPosition) + "]";
//       row = 3;
//       col = 0;
//       roamKnight(row, col);
//       break;
//     case 7:
//       board[1][0] = "[" + to_string(startingPosition) + "]";
//       row = 1;
//       col = 0;
//       roamKnight(row, col);
//       break;
//     case 8:
//       board[0][1] = "[" + to_string(startingPosition) + "]";
//       row = 0;
//       col = 1;
//       roamKnight(row, col);
//       break;
//   }
// }

// bool isValid(int row, int col) {
//   if ((row < 0 || row >= 5 || col < 0 || col >= 5) && board[sizeRow][sizeCol] != 0) {
//     return true;
//   }
//   return false;
// }

bool knightsTour(int numMove, int x, int y) {
    if (numMove == sizeRow * sizeCol) {
        printBoard();
        return true;
    }

    for (int a = 0; a < 8; a++) {
        int nextX = x + row_delta[a];
        int nextY = y + col_delta[a];

        // if (isValid(nextX, nextY)) {
        //   continue;
        // }

        if (nextX < 0 || nextX >= sizeRow || nextY < 0 || nextY >= sizeCol)
            continue;

        if (board[nextX][nextY] != 0)
            continue;

        board[nextX][nextY] = numMove + 1;
        knightsTour(numMove + 1, nextX, nextY);
        board[nextX][nextY] = 0;
    }
    return false;
}

void centerpiece(int initialROW, int initialCOL) {
  for (int row = 0; row < sizeRow; row++) {
    for (int col = 0; col < sizeCol; col++) {
      board[row][col] = 0;
    }
  }
    board[initialROW][initialCOL] = 1;
    knightsTour(1, initialROW, initialCOL);
}

// vector<int> vecRows_knightMoves {2, 1, -1, -2, -2, -1, 1, 2};
// vector<int> vecCols_knightMoves {1, 2, 2, 1, -1, -2, -2, -1};
// void generateNewRowCol(int rowShift, int colShift) {
//   // Iterator used to store the position of searched element
//   vector<int>::iterator itRow = find(vecRows_knightMoves.begin(), vecRows_knightMoves.end(), rowShift);
//   vector<int>::iterator itCol = find(vecCols_knightMoves.begin(), vecCols_knightMoves.end(), colShift);
//   int rowShiftIndex = itRow - vecRows_knightMoves.begin();
//   int colShiftIndex = itCol - vecCols_knightMoves.begin();
//
//   // if x and y have the same index, remove them from both vectors
//   if (rowShiftIndex == colShiftIndex) {
//     vecRows_knightMoves.erase(vecRows_knightMoves.begin() + rowShiftIndex);
//     vecCols_knightMoves.erase(vecCols_knightMoves.begin() + colShiftIndex);
//   }
//
//   int counter = 0;
//   while(!isValid(row, col) &&
//         ( ((abs(row - vecRows_knightMoves[counter]) != 2) && (abs(col - vecCols_knightMoves[counter]) != 1)) ||
//         ((abs(row - vecRows_knightMoves[counter]) != 1) && (abs(col - vecCols_knightMoves[counter]) != 2)) ) &&
//         (((row + vecRows_knightMoves[counter]) < 0 && (row + vecRows_knightMoves[counter]) > 4) && ((col + vecCols_knightMoves[counter]) < 0 && (col + vecCols_knightMoves[counter]) > 4))) {
//     counter++;
//     generateNewRowCol(vecRows_knightMoves[counter], vecCols_knightMoves[counter]);
//   }
//
//   row += vecRows_knightMoves[counter];
//   col += vecCols_knightMoves[counter];
//
//   cout << row << col;
// }
