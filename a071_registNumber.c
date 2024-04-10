#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int checkNumber(char regNum[]);

int main() {
  char regNum[14];
  printf("Enter a registration number: ");
  scanf("%s", regNum);

  int check = checkNumber(regNum);
  if (check == regNum[12] - '0') {
    printf("Valid registration number\n");
  } else {
    printf("Invalid registration number\n");
  }
}

int checkNumber(char regNum[]) {
  int origin[13];
  int chk[12] = {2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 4, 5};
  int chkSum = 0;

  for (int i = 0; i < 13; i++) {
    origin[i] = regNum[i] - '0';
  }
  for (int i = 0; i < 12; i++) {
    chkSum += origin[i] * chk[i];
  }
  return (11 - (chkSum % 11)) % 10;
}