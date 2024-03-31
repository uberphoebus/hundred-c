#include <stdio.h>

int main() {
  int index;
  int primes = 0;

  for (int i = 2; i < 1000; i++) {
    for (index = 2; index < i; index++) {
      if (i % index == 0) {
        break;
      }
    }
    if (index == i) {
      primes++;
      printf("%4d%c", i, primes % 10 == 0 ? '\n':' ');
    }
  }
  printf("\nTotal %d prime numbers\n", primes);
}