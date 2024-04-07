#include <stdio.h>
#include <time.h>

int main() {
  double start, end;

  start = (double)clock() / CLOCKS_PER_SEC;

  int sum = 0;
  for (int i = 0; i < 100000000; i++) {
    sum += i;
  }

  end = (double)clock() / CLOCKS_PER_SEC;
  printf("sum = %d | time = %f\n", sum, end - start);
}