#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>

void printDayTime(struct tm *t);

int main() {
  struct tm *t;
  time_t now;

  time(&now);
  printf("time = %ld\n", now);

  t = localtime(&now);
  printf("asctime = %s", asctime(t));
}