#define _CRT_SECURE_NO_WARNINGS
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#define MAXLINES 1000
#define MAXLEN 1000

char *lineptr[MAXLINES] = {NULL};

void writelines(char *lineptr[]) {
  char **ptr = lineptr;
  while (*ptr) {
    printf("%s\n", *ptr++);
  }
}