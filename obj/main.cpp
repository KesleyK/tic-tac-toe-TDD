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
  if(optionValue == 1) {
    pushX((char) row, (char) column);
  } else {
    pushO(row, column);
  }
}

int main() {
  int switchNumber;

  while (checkGameStatus() <= 0) {
    printf(
      "1-Show Board\n"
      "2-Insert X\n"
      "3-Insert O\n\n"
    );
    printf("Enter a number: ");
    scanf("%i", &switchNumber);

    printf("\n");
    switch (switchNumber) {
      case 1: 
        showBoard();
        printf("\n");
        break;
      case 2:
        insertOption(1);
        break;
      case 3: 
        insertOption(2);
        break;
    }
  }

  printf("\n%i was the winner!\n", checkGameStatus());
}
