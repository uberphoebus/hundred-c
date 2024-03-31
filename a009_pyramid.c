#include <stdio.h>

#define ROW 5

int main() {
  printf("(1)\n");
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < i + 1; j++) {
      printf("*");
    }
    printf("\n");
  }

  printf("\n(2)\n");
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < i * 2 + 1; j++) {
      printf("*");
    }
    printf("\n");
  }

  printf("\n(3)\n");
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < ROW - i; j++) {
      printf("*");
    }
    printf("\n");
  }

  printf("\n(4)\n");
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < ROW - i; j++) {
      printf(" ");
    }
    for (int j = 0; j < i + 1; j++) {
      printf("*");
    }
    printf("\n");
  }

  printf("\n(5)\n");
  for (int i = 1; i <= ROW; i++) {
    for (int j = 1; j <= ROW - i; j++) {
      printf(" ");
    }
    for (int j = 1; j <= i * 2 - 1; j++) {
      printf("*");
    }
    printf("\n");
  }
  printf("\n");

  printf("\n(6)\n");
  for (int i = ROW; i >= 1; i--) {
    for (int j = 1; j <= ROW - i; j++) {
      printf(" ");
    }
    for (int j = 1; j <= i * 2 - 1; j++) {
      printf("*");
    }
    printf("\n");
  }
  printf("\n");
}