#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_PATH "../studentRecord.txt"

typedef struct {
  int sid;
  char name[20];
  struct subject {
    int scode;
    char sname[20];
    int score;
  } sub[3];
  int total;
  float avg;
} student;

void displayMenu();

int main() {
  int choice = 0;
  do {
    displayMenu();
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("\n");
    selectMenu(choice);
  } while (choice != 0);
  return 0;
}

void title() {
  printf("\n");
  printf("**********************************************************\n");
  printf("*                                                        *\n");
  printf("*                  Student Record System                 *\n");
  printf("*                                                        *\n");
  printf("**********************************************************\n\n");
}

void displayMenu() {
  title();
  printf(" 1. Insert Student Record");
  printf("\t2. Display Record Counts\n");
  printf(" 3. Display All Records");
  printf("\t\t4. Search Student\n");
  printf(" 5. Update Student");
  printf("\t\t6. Delete Student\n");
  printf(" 7. Sort By Score");
  printf("\t\t8. Sort By ID\n");
  printf(" 9. Sort By Name");
  printf("\t\t0. Exit\n\n");
}

void selectMenu(int ch) {
  switch (ch) {
  case 1:
    insertRecord();
    break;
  case 2:
    printf("Total Records: %d\n", displayRecordCounts());
    break;
  case 3:
    displayAllRecords();
    break;
  case 4:
    searchStudent();
    break;
  case 5:
    updateStudent();
    break;
  case 6:
    deleteStudent();
    break;
  case 7:
    // sortByScore();
    break;
  case 8:
    // sortByID();
    break;
  case 9:
    // sortByName();
    break;
  case 0:
    printf("Exiting...\n\n");
    break;
  default:
    printf("Invalid choice!\n");
  }
}

void insertRecord() {
  FILE *fp;
  student s;

  char buf[20];
  fp = fopen(FILE_PATH, "a");
  printf("Enter Student ID: ");
  scanf("%s", buf);
  getchar();
  for (int i = 0; buf[i] != '\0'; i++) {
    if (!isdigit(buf[i])) {
      printf("ID must be a number!\n");
      return;
    }
  }
  s.sid = atoi(buf);

  printf("Enter Student Name: ");
  scanf("%[^\n]", s.name);

  s.total = 0;
  for (int i = 0; i < 3; i++) {
    printf("Enter Subject Score [%d] : ", i + 1);
    scanf("%d", &s.sub[i].score);
    s.total += s.sub[i].score;
  }
  s.avg = (float)s.total / 3.0;

  fwrite(&s, sizeof(student), 1, fp);
  fclose(fp);
}

int displayRecordCounts() {
  FILE *fp;
  student s;

  fp = fopen(FILE_PATH, "r");
  if (fp == NULL) {
    printf("File not found!\n");
    return 0;
  }

  fseek(fp, 0, SEEK_END);              // move to end of file
  int n = ftell(fp) / sizeof(student); // get total records
  fclose(fp);
  return n;
}

void displayAllRecords() {
  FILE *fp;
  student s;

  fp = fopen(FILE_PATH, "r");
  if (fp == NULL) {
    printf("File not found!\n");
    return 0;
  }

  if (displayRecordCounts() >= 0) {
    printf("%-10s%-10s%6s%6s%6s%8s%8s\n", "ID", "Name", "S1", "S2", "S3",
           "Total", "Avg");
    for (int i = 0; i < 54; i++) {
      printf("-");
    }
    printf("\n");

    while (fread(&s, sizeof(student), 1, fp) == 1) {
      printf("%-10d%-10s%6d%6d%6d%8d%8.2f\n", s.sid, s.name, s.sub[0].score,
             s.sub[1].score, s.sub[2].score, s.total, s.avg);
    }
  }

  fclose(fp);
}

void searchStudent() {
  FILE *fp;
  student s;
  int sid, found = 0;

  fp = fopen(FILE_PATH, "r");
  if (fp == NULL) {
    printf("File not found!\n");
    return 0;
  }

  printf("Enter Student ID: ");
  scanf("%d", &sid);
  while (fread(&s, sizeof(student), 1, fp)) {
    if (s.sid == sid) {
      found = 1;
      printf("%-10d%-10s", s.sid, s.name);
      for (int i = 0; i < 3; i++) {
        printf("%6d", s.sub[i].score);
      }
      printf("%8d%8.2f\n", s.total, s.avg);
    }
  }

  if (found == 0) {
    printf("Student not found!\n");
  }

  fclose(fp);
}

void updateStudent() {
  FILE *fp, *fp1;
  student s;
  int sid, found = 0;

  fp = fopen(FILE_PATH, "r");
  if (fp == NULL) {
    printf("File not found!\n");
    return 0;
  }

  fp1 = fopen("../temp.txt", "w");

  printf("Enter Student ID: ");
  scanf("%d", &sid);

  while (fread(&s, sizeof(student), 1, fp)) {
    if (s.sid == sid) {
      found = 1;
      s.total = 0;
      getchar();

      printf("Enter Student Name: ");
      scanf("%[^\n]", s.name);

      for (int i = 0; i < 3; i++) {
        printf("Enter Subject Score [%d] : ", i + 1);
        scanf("%d", &s.sub[i].score);
        s.total += s.sub[i].score;
      }
      s.avg = (float)s.total / 3.0;
    }
    fwrite(&s, sizeof(student), 1, fp1);
  }
  fclose(fp);
  fclose(fp1);

  if (found == 1) {
    remove(FILE_PATH);                // delete original file
    rename("../temp.txt", FILE_PATH); // rename temp file
  } else {
    printf("Student not found!\n");
  }
}

void deleteStudent() {
  FILE *fp, *fp1;
  student s;
  int sid, found = 0;

  fp = fopen(FILE_PATH, "r");
  if (fp == NULL) {
    printf("File not found!\n");
    return 0;
  }

  fp1 = fopen("../temp.txt", "w");

  printf("Enter Student ID: ");
  scanf("%d", &sid);

  while (fread(&s, sizeof(student), 1, fp)) {
    if (s.sid == sid) {
      found = 1;
    } else {
      fwrite(&s, sizeof(student), 1, fp1);
    }
  }
  fclose(fp);
  fclose(fp1);

  if (found == 1) {
    remove(FILE_PATH);                // delete original file
    rename("../temp.txt", FILE_PATH); // rename temp file
  } else {
    printf("Student not found!\n");
  }
}
