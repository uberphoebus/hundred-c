#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void *p, const void *q) { return *(int *)p - *(int *)q; }

int main() {
  int a[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
  int *ptr;
  int key;

  printf("Enter a value to search: ");
  scanf("%d", &key);

  ptr = (int *)bsearch(&key, a, 10, sizeof(int), compare);
  if (ptr != NULL) {
    printf("Found at index %ld\n", ptr - a);
  } else {
    printf("Not found\n");
  }
}