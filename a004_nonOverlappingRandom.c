#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CNT 10

int check[CNT + 1] = {0};  // duplicate check
int rand_order[CNT] = {0}; // random order

int rand_max = 10;
int rand_min = 1;

int main() {
  srand(time(0));
  for (int i = 0; i < CNT; i++) {
    int x;
    do {
      x = (double)rand() / RAND_MAX * (rand_max - rand_min + 1) + rand_min;
    } while (check[x] == 1);
    check[x] = 1;
    rand_order[i] = x;
  }

  for (int i = 0; i < CNT; i++) {
    printf("%3d ", rand_order[i]);
  }
  printf("\n");
}