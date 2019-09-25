#include <stdio.h>
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

void pushX(char row, char column) {
  board[row - 97][column - 100] = 1;
  ++pushedX;
}

void pushO(char row, char column) {
  board[row - 97][column - 100] = 2;
  ++pushedO;
}

int checkGameStatus() {

}