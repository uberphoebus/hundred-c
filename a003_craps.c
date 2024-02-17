#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TRIALS 1000000

int main() {
  int cnt[13] = {0};
  int rand_min = 1;
  int rand_max = 6;
  int dice;

  srand(time(0));

  int v = rand_max - rand_min + 1;
  for (int i = 0; i < TRIALS; i++) {
    dice = rand() % rand_max + rand_min;
    dice += rand() % rand_max + rand_min;
    cnt[dice]++;
    
  }

  int total = 0;
  for (int i = 2; i <= 12; i++) {
    printf("cnt[%2d] = %8d, %5.2f%%\n", i, cnt[i], (double)cnt[i] / TRIALS * 100);
    total += cnt[i];
  }
  printf("trials = %d\n", total);
}