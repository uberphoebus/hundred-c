#define _CRT_SECURE_NO_WARNINGS
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int passwordChecker(char password[]);

int main() {
  char password[30];

  while (1) {
    printf("Enter a password: ");
    scanf("%s", password);

    switch (passwordChecker(password)) {
    case 1:
      printf("8 characters\n");
      break;
    case 2:
      printf("1 uppercase\n");
      break;
    case 3:
      printf("1 lowercase\n");
      break;
    case 4:
      printf("1 digit\n");
      break;
    case 5:
      printf("1 special character\n");
      break;
    default:
      printf("valid password\n");
      return 0;
    }
  }
}

int passwordChecker(char password[]) {
  int checkUpperFlag = 0;
  int checkLowerFlag = 0;
  int checkSpecialFlag = 0;
  int checkDigitFlag = 0;

  if (strlen(password) < 8) {
    return 1;
  }

  for (int i = 0; i < strlen(password); i++) {
    if (isupper(password[i])) {
      checkUpperFlag = 1;
    } else if (islower(password[i])) {
      checkLowerFlag = 1;
    } else if (isdigit(password[i])) {
      checkDigitFlag = 1;
    } else {
      checkSpecialFlag = 1;
    }
  }

  if (checkUpperFlag == 0) {
    return 2;
  }
  if (checkLowerFlag == 0) {
    return 3;
  }
  if (checkDigitFlag == 0) {
    return 4;
  }
  if (checkSpecialFlag == 0) {
    return 5;
  }
  return 0;
}
