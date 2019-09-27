// "Copyright 2019 Kesley Kenny"
#include <stdio.h>
#include "../include/velha.hpp"

void insertOption(int optionValue) {
  char row;
  char column;

  printf("Select a row: ");
  scanf("%s", &row);

  printf("Select a column: ");
  scanf("%s", &column);

  printf("\n");
  if (optionValue == 1) {
    pushX(row, column);
  } else {
    pushO(row, column);
  }
}

int main() {
  int switchNumber;

  while (checkGameStatus() < 0) {
    printf(
      "1-Insert X\n"
      "2-Insert O\n"
      "3-Show Board\n"
      "4-Restart Game\n\n");
    printf("Enter a number: ");
    scanf("%i", &switchNumber);

    printf("\n");
    switch (switchNumber) {
      case 1:
        insertOption(1);
        break;
      case 2:
        insertOption(2);
        break;
      case 3:
        showBoard();
        printf("\n");
        break;
      case 4:
        restartGame();
        break;
      default:
        printf("Error: Invalid value\n");
    }
    printf("=======================\n\n");
  }
}
