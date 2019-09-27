// "Copyright 2019 Kesley Kenny"
#include <stdio.h>
#include <stdbool.h>
#include "../include/velha.hpp"

int board[3][3];
int pushedX = 0;
int pushedO = 0;

void showBoard() {
  char firstAsciiNumber = 97;

  printf("  d e f\n");
  for (int i = 0; i < 3; ++i) {
    printf("%c ", firstAsciiNumber++);
    for (int j = 0; j < 3; ++j) {
      printf("%i ", board[i][j]);
    }
    printf("\n");
  }
}

void restartGame() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      board[i][j] = 0;
    }
  }
  pushedX = 0;
  pushedO = 0;
}

bool checkValidSpot(char row, char column) {
  bool verificRow = row < 97 || row > 99;
  bool verificColumn = column < 100 || column > 102;

  if (!verificRow && !verificColumn) {
    return true;
  }
  return false;
}

void push(char row, char column, int positionValue) {
  if (checkValidSpot(row, column)) {
    if (board[row - 97][column - 100]) {
      printf("Error: Spot marked already.\n\n");
    } else {
      board[row - 97][column - 100] = positionValue;
    }
  } else {
    printf("Spot not valid. Please enter a correct value.\n");
  }
}

void pushX(char row, char column) {
  push(row, column, 1);
  ++pushedX;
}

void pushO(char row, char column) {
  push(row, column, 2);
  ++pushedO;
}

int checkGameStatus() {
  if (checkIfInvalid()) {
    printf("Status: Invalid game!\n\n");
    return -2;
  }
  if (checkIfUndefined()) {
    printf("Status: Undefined game!\n\n");
    return -1;
  }
  if (checkIfATie()) {
    printf("Status: Game was a tie!\n\n");
    return 0;
  }
  if (checkIfWinner() > 0) {
    printf("Status: %i was the winner!\n\n", checkIfWinner());
    return checkIfWinner();
  }
}

bool checkIfUndefined() {
  return pushedX < 3 && pushedO < 3;
}

bool checkIfInvalid() {
  return pushedX > (pushedO + 1) || pushedO > (pushedX + 1);
}

bool checkIfATie() {
  bool verific1 = pushedO == 5 && pushedX == 4;
  bool verific2 = pushedO == 4 && pushedX == 5;
  return checkIfWinner() == -10 && verific1 || verific2;
}

int checkIfWinner() {
  if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2]) {
    return board[0][2];
  } else if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0]) {
    return board[0][0];
  } else if (board[0][0] == board[0][1] && board[0][0] == board[0][2] && board[0][0]) {
    return board[0][0];
  } else if (board[1][0] == board[1][1] && board[1][0] == board[1][2] && board[1][0]) {
    return board[1][0];
  } else if (board[2][0] == board[2][1] && board[2][0] == board[2][2] && board[2][0]) {
    return board[2][0];
  } else if (board[0][0] == board[1][0] && board[0][0] == board[0][0] && board[2][0]) {
    return board[0][0];
  } else if (board[0][1] == board[1][1] && board[0][1] == board[2][1] && board[0][1]) {
    return board[0][1];
  } else if (board[0][2] == board[1][2] && board[0][2] == board[2][2] && board[0][2]) {
    return board[0][2];
  } else {
    return -10;
  }
}
