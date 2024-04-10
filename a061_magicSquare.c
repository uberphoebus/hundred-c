#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
  int x, y, n;
  int a[100][100] = {
      0,
  };

  printf("Enter the size of the magic square: ");
  scanf("%d", &n);

  int col = n / 2;
  int row = 0;

  for (int i = 1; i <= n * n; i++) {
    a[row][col] = i;
    int t_row = row - 1;
    int t_col = col + 1;
    if (t_row == -1) {
      t_row = n - 1;
    }
    if (t_col == n) {
      t_col = 0;
    }
    if (a[t_row][t_col] != 0) {
      row++;
    } else {
      row = t_row;
      col = t_col;
    }
  }

  int sum_col;
  for (int i = 0; i < n; i++) {
    sum_col = 0;
    for (int j = 0; j < n; j++) {
      printf("%4d", a[i][j]);
      sum_col += a[j][i];
    }
    printf(" -> %4d\n", sum_col);
    printf("\n");
  }
}