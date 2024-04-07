#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000
#define CNT 1000

int search(int a[], int v);
void printArr(int a[], int n);
void find_min_max(int a[], int n);

int main() {
  int a[CNT];
  int value, index;

  srand(time(NULL));
  for (int i = 0; i < CNT; i++) {
    a[i] = rand() % MAX;
  }

  printArr(a, CNT);
  find_min_max(a, CNT);

  printf("Enter a value to search: ");
  scanf("%d", &value);

  if ((index = search(a, value)) != -1) {
    printf("Found at index %d\n", index);
  } else {
    printf("Not found\n");
  }

  printf("\nmin = %d, max = %d\n", a[0], a[CNT - 1]);
}

int search(int a[], int v) {
  for (int i = 0; i < CNT; i++) {
    if (a[i] == v) {
      return i;
    }
  }
  return -1;
}

void printArr(int a[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%c%6d", (i % 20 == 0) ? '\n' : ' ', a[i]);
  }
  printf("\n");
}

void find_min_max(int a[], int n) {
  int min = a[0], max = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] < min) {
      min = a[i];
    } else if (a[i] > max) {
      max = a[i];
    }
  }
  printf("min = %d, max = %d\n", min, max);
}