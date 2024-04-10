#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void printMaze(char **maze, int rows, int columns);

int main() {
  FILE *fp;
  char filename[32];
  char **maze;
  int nRows, nColumns;

  printf("Enter the filename: ");
  scanf("%s", filename);
  if ((fp = fopen(filename, "r")) == NULL) {
    printf("File not found\n");
    exit(1);
  }

  fscanf(fp, "%d", &nRows);
  fscanf(fp, "%d", &nColumns);
  printf("Rows: %d, Columns: %d\n\n", nRows, nColumns);

  maze = (char **)malloc(nRows * sizeof(char *));
  for (int i = 0; i < nRows; i++) {
    maze[i] = (char *)malloc(nColumns * sizeof(char));
  }

  fgetc(fp); // remove newline
  for (int i = 0; i < nRows; i++) {
    for (int j = 0; j < nColumns; j++) {
      maze[i][j] = fgetc(fp);
    }
    fgetc(fp); // remove newline
  }

  printMaze(maze, nRows, nColumns);

  for (int i = 0; i < nRows; i++) {
    free(maze[i]);
  }
  free(maze);
}

void printMaze(char **maze, int rows, int columns) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      printf("%c", maze[i][j]);
    }
    printf("\n");
  }
}