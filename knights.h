#pragma once
using namespace std;

void createBoard();
void printBoard();
void startKnight(int startingPosition);
void roamKnight(int x, int y);
bool isValid(int x, int y);
void generateNewRowCol(int x, int y);
