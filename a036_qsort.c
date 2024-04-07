#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct student {
  int id;
  char name[20];
  int score;
};

int compare1(const void *p, const void *q) {
  int a = ((struct student *)p)->id;
  int b = ((struct student *)q)->id;
  return a - b;
}

int compare2(const void *p, const void *q) {
  int a = ((struct student *)p)->score;
  int b = ((struct student *)q)->score;
  return b - a;
}

int compare3(const void *p, const void *q) {
  char *a = ((struct student *)p)->name;
  char *b = ((struct student *)q)->name;
  return strcmp(a, b);
}

void printArr(struct student a[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%5d %10s %4d\n", a[i].id, a[i].name, a[i].score);
  }
  printf("\n");
}

int main() {
  struct student a[] = {{1, "Kim", 90},
                        {2, "Lee", 80},
                        {3, "Park", 85},
                        {4, "Choi", 70},
                        {5, "Jung", 75}};

  printf("sort by id\n");
  qsort(a, 5, sizeof(struct student), compare1);
  printArr(a, 5);

  printf("sort by score\n");
  qsort(a, 5, sizeof(struct student), compare2);
  printArr(a, 5);

  printf("sort by name\n");
  qsort(a, 5, sizeof(struct student), compare3);
  printArr(a, 5);
}