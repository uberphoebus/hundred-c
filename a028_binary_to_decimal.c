#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>

long long decimal_to_binary(int dec) {
  long long bin = 0;
  int mask = 0x01; // 0000 0001
  int bit;

  for (int i = 0; i < 16; i++) {
    bit = dec & mask;
    bin += bit * pow(10, i);
    dec = dec >> 1;
  }

  return bin;
}

int main() {
  long long bin;
  int dec;

  dec = 139;
  bin = decimal_to_binary(dec);
  printf("Decimal %d is Binary %lld\n", dec, bin);

  dec = 10922;
  bin = decimal_to_binary(dec);
  printf("Decimal %d is Binary %lld\n", dec, bin);
}