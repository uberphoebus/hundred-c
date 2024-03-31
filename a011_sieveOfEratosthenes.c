#include <stdio.h>
#include <stdbool.h>
#define N 1000

int main() {
  bool a[N + 1];
  int primes = 0;

  a[0] = a[1] = false;
  for (int i = 2; i <= N; i++) {
    a[i] = true;
  }

  for (int i = 2; i <= N / 2; i++) {
    for (int j = 2; j <= N / i; j++) {
      a[i * j] = false;
    }
  }

  for (int i = 0; i <= N; i++) {
    if (a[i]) {
      primes++;
      printf("%4d%c", i, primes % 10 == 0 ? '\n':' ');
    }
  }
  printf("\nTotal %d prime numbers\n", primes);
}