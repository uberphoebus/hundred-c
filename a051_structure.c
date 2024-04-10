#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct student {
  char dept[20];
  int year;
  int id;
  char name[20];
  char phone[20];
};

void printInfo(struct student *s) {
  printf("Dept: %s\n", s->dept);
  printf("Year: %d\n", s->year);
  printf("ID: %d\n", s->id);
  printf("Name: %s\n", s->name);
  printf("Phone: %s\n", s->phone);
}

int main() {
  struct student s1 = {"CS", 2, 20210001, "John Doe", "010-1234-5678"};
  struct student s2 = {"Mathematics", 3, 20200001, "Jane Doe", "010-2345-6789"};
  printInfo(&s1);
  printInfo(&s2);
}