#include <stdio.h>
#include <stdlib.h>

#define YEARS 4
#define STUDENTS 10
#define SUBJECTS 10

void randomScore(int score[][STUDENTS][SUBJECTS]);
void printScore(int score[][STUDENTS][SUBJECTS]);
void highestScore(int score[][STUDENTS][SUBJECTS]);
void highestSubject(int score[][STUDENTS][SUBJECTS]);

int main() {
  int score[YEARS][STUDENTS][SUBJECTS];
  randomScore(score);
  printScore(score);
  highestScore(score);
  highestSubject(score);
}

void randomScore(int score[][STUDENTS][SUBJECTS]) {
  for (int i = 0; i < YEARS; i++) {
    for (int j = 0; j < STUDENTS; j++) {
      for (int k = 0; k < SUBJECTS; k++) {
        score[i][j][k] = rand() % 101;
      }
    }
  }
}

void printScore(int score[][STUDENTS][SUBJECTS]) {
  for (int i = 0; i < YEARS; i++) {
    printf("\nYear %d\n", i + 1);
    for (int j = 0; j < STUDENTS; j++) {
      printf("Student %2d : ", j + 1);
      for (int k = 0; k < SUBJECTS; k++) {
        printf("%4d ", score[i][j][k]);
      }
      printf("\n");
    }
  }
}

void highestScore(int score[][STUDENTS][SUBJECTS]) {
  int max = 0;

  struct highest {
    int year;
    int student;
    int subject;
  } highest;
  for (int i = 0; i < YEARS; i++) {
    for (int j = 0; j < STUDENTS; j++) {
      for (int k = 0; k < SUBJECTS; k++) {
        if (score[i][j][k] > max) {
          max = score[i][j][k];
          highest.year = i + 1;
          highest.student = j + 1;
          highest.subject = k + 1;
        }
      }
    }
  }
  printf("\nHighest score: Year %d, Student %2d, Subject %d = %d\n",
         highest.year, highest.student, highest.subject, max);
}

void highestSubject(int score[][STUDENTS][SUBJECTS]) {
  int sum[YEARS][STUDENTS];
  for (int i = 0; i < YEARS; i++) {
    for (int j = 0; j < SUBJECTS; j++) {
      sum[i][j] = 0;
      for (int k = 0; k < STUDENTS; k++) {
        sum[i][j] += score[i][k][j];
      }
    }
  }

  for (int i = 0; i < YEARS; i++) {
    printf("%d Year Sum\n", i + 1);

    int bestScore = 0;
    int bestIndex = 0;

    for (int j = 0; j < SUBJECTS; j++) {
      printf("%4d", sum[i][j]);
      if (bestScore < sum[i][j]) {
        bestScore = sum[i][j];
        bestIndex = j;
      }
    }
    printf("\n");
    printf("Subject = %d, Sum = %d\n", bestIndex + 1, bestScore);
  }
}