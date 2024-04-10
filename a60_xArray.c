#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
  int n;

  printf("Enter the number of elements: ");
  scanf("%d", &n);

  // up
  for (int i = 0; i < n / 2; i++) {
    for (int j = 0; j < i; j++) {
      printf(" %c", '0');
    }
    printf(" %c", 'X');
    for (int j = 0; j < n - 2 * (i + 1); j++) {
      printf(" %c", '0');
    }
    printf(" %c", 'X');
    for (int j = 0; j < i; j++) {
      printf(" %c", '0');
    }
    printf("\n");
  }

  // middle
  for (int j = 0; j < n / 2; j++) {
    printf(" %c", '0');
  }
  printf(" %c", 'X');
  for (int j = 0; j < n / 2; j++) {
    printf(" %c", '0');
  }
  printf("\n");

  // down
  for (int i = n / 2 - 1; i >= 0; i--) {
    for (int j = 0; j < i; j++) {
      printf(" %c", '0');
    }
    printf(" %c", 'X');
    for (int j = 0; j < n - 2 * (i + 1); j++) {
      printf(" %c", '0');
    }
    printf(" %c", 'X');
    for (int j = 0; j < i; j++) {
      printf(" %c", '0');
    }
    printf("\n");
  }
}