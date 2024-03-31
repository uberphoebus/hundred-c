#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
  int i, a, b, c;
  int day, month, year;
  char s[100];

  int x = scanf("%d %c %d", &a, &i, &b); // 12 + 34
  printf("scanf() returns %d\n", x);
  printf("(1) %d %c %d\n", a, i, b);
  c = getchar(); // read '\n'

  scanf("%d[^\n]", s);   // up-to '\n'
  printf("(2) %s\n", s);

  scanf("%*d%s", &s);    // 123abc or 123 abc
  printf("(3) %s\n", s);

  scanf("%5d%2d", &a, &b);  // 1234567
  printf("(4) %d %d\n", a, b);
}