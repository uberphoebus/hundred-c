#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int a[10];
  int dice[30];

  int rand_min = 1;
  int rand_max = 6;

  srand(time(0)); // rand seed -> curr time
  for (int i = 0; i < 10; i++) {
    a[i] = rand(); // [0, 32767]
    printf("%d ", a[i]);
  }
  printf("\nRAND_MAX = %x, %d\n", RAND_MAX, RAND_MAX);

  for (int i = 0; i < 30; i++) {
    dice[i] = rand() % rand_max + rand_min;
    printf("%6d%c", dice[i], (i + 1) % 10 != 0 ? ' ': '\n');
  }
}