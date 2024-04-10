#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROOMS 10

typedef struct dormitory {
  int sid;
  char name[10];
  char home[10];
  char gender[5];
  int roomNo;
} dormitory;

int allottedRooms = 0;
int rooms[] = {101, 102, 201, 202, 301, 302, 401, 402, 501, 502};
int roomAllotted[ROOMS] = {0};

void menu();
int getRoomNo();
void allotRoom();
void display();
void printAvailable();
void readDormitory();

int main() {
  int choice;

  srand(time(0));
  readDormitory();
  do {
    menu();
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      allotRoom();
      break;
    case 2:
      display();
      break;
    case 3:
      printAvailable();
      break;
    case 0:
      break;
    }
  } while (choice != 4);
}

void menu() {
  printf("\n---------- Dormitory System ----------\n");
  printf("1. Allot Room\n");
  printf("2. Display\n");
  printf("3. Print Available Rooms\n");
  printf("0. Exit\n");
  printf(" >> Select an option: ");
}

int getRoomNo() {
  int rn = rand() % ROOMS;
  if (roomAllotted[rn] == 0) {
    roomAllotted[rn] = 1;
    return rooms[rn];
  } else {
    getRoomNo();
  }
}

void allotRoom() {
  dormitory dorm;
  FILE *fp = fopen("../dormitory.txt", "a+");
  if (allottedRooms >= ROOMS) {
    printf("All rooms are allotted\n");
    return;
  }
  printf("Enter student ID: ");
  scanf("%d", &dorm.sid);
  printf("Enter student name: ");
  scanf("%s", dorm.name);
  printf("Enter student home: ");
  scanf("%s", dorm.home);
  printf("Enter gender : ");
  scanf("%s", dorm.gender);

  dorm.roomNo = getRoomNo();
  allottedRooms++;
  roomAllotted[dorm.roomNo] = 1;
  printf("%s has been allotted room no. %d\n", dorm.name, dorm.roomNo);

  fwrite(&dorm, sizeof(dorm), 1, fp);
  fclose(fp);
}

void display() {
  dormitory dorm;
  FILE *fp = fopen("../dormitory.txt", "r");
  if (fp == NULL) {
    printf("No records found\n");
    return;
  }

  printf("%10s%10s%10s%10s%10s\n", "Student ID", "Name", "Home", "Gender",
         "Room No.");
  while (fread(&dorm, sizeof(dorm), 1, fp)) {
    printf("%10d%10s%10s%10s%10d\n", dorm.sid, dorm.name, dorm.home,
           dorm.gender, dorm.roomNo);
  }
  fclose(fp);
}

void printAvailable() {
  printf("Allotted Rooms: %d\n", allottedRooms);
  printf("Available Rooms: %d\n", ROOMS - allottedRooms);
  printf("Available Room No.: ");
  for (int i = 0; i < ROOMS; i++) {
    if (roomAllotted[i] == 0) {
      printf("%5d ", rooms[i]);
    }
  }
  printf("\n");
}

void readDormitory() {
  dormitory dorm;
  FILE *fp = fopen("../dormitory.txt", "r");
  if (fp == NULL) {
    return;
  }

  while (fread(&dorm, sizeof(dorm), 1, fp)) {
    for (int i = 0; i < ROOMS; i++) {
      if (dorm.roomNo == rooms[i]) {
        roomAllotted[i] = 1;
        allottedRooms++;
      }
    }
  }
  fclose(fp);
}
