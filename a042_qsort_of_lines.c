#define _CRT_SECURE_NO_WARNINGS
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#define MAXLINES 1000
#define MAXLEN 1000

char *lineptr[MAXLINES] = {NULL};

// Function to write the lines stored in lineptr array
void writelines(char *lineptr[]) {
  // Create a pointer to iterate through the lineptr array
  char **ptr = lineptr;

  // Loop through the lineptr array until a NULL pointer is encountered
  while (*ptr) {
    // Print the current line pointed by ptr
    printf("%s\n", *ptr++);
  }
}

void swap(char *v[], int i, int j) {
  char *temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

void my_qsort(char *v[], int left, int right) {
  int i, last;
  if (left >= right) {
    return;
  }
  swap(v, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; i++) {
    if (strcmp(v[i], v[left]) < 0) {
      swap(v, ++last, i);
    }
  }
  swap(v, left, last);
  my_qsort(v, left, last - 1);
  my_qsort(v, last + 1, right);
}

int main() {
  int nlines = 0;
  char line[MAXLEN];

  printf("Enter the lines to be sorted. Press Ctrl+D to stop.\n");
  // Loop until fgets returns NULL, indicating end of input
  while (fgets(line, MAXLEN, stdin) != NULL) {
    // Check if the line is empty (only contains a newline character)
    if (!strcmp(line, "\n")) {
      // If it is, break out of the loop
      break;
    }
    // Remove the newline character at the end of the line
    line[strlen(line) - 1] = '\0';
    // Allocate memory for the line and store the pointer in lineptr array
    lineptr[nlines] = (char *)malloc(strlen(line) + 1);
    // Check if memory allocation was successful
    if (lineptr[nlines] != NULL) {
      // Copy the line into the allocated memory
      strcpy(lineptr[nlines], line);
      // Increment the number of lines counter
      nlines++;
    }
  }

  my_qsort(lineptr, 0, nlines - 1);
  printf("\nSorted lines:\n");
  writelines(lineptr);
}