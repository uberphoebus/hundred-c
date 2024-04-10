#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person {
  int id;
  char name[20];
  char address[50];
  char phone[14];
  char email[30];
  struct person *next;
} person;

person *head = NULL;
int lastId = 0;

void insertNode();
void deleteNode();
void display();
void save();

void append(person *p);
void readFile();

int main() {
  person *ptr;
  int choice;

  readFile();
  do {
    printf("\n----- Address Manage System -----\n");
    printf("1. Insert\n");
    printf("2. Display\n");
    printf("3. Delete\n");
    printf("4. Save\n");
    printf("0. Exit\n");
    printf("\nSelect: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      insertNode();
      display();
      break;
    case 2:
      display();
      break;
    case 3:
      deleteNode();
      display();
      break;
    case 4:
      save();
      break;
    }
  } while (choice != 0);
}

void insertNode() {
  person *ptr, *temp;
  temp = (person *)malloc(sizeof(person));
  temp->next = NULL;
  temp->id = ++lastId;

  printf("Enter name: ");
  scanf(" %s", temp->name);
  printf("Enter address: ");
  scanf(" %[^\n]s", temp->address);
  printf("Enter phone: ");
  scanf(" %s", temp->phone);
  printf("Enter email: ");
  scanf(" %s", temp->email);

  if (head == NULL) {
    head = temp;
  } else {
    ptr = head;
    while (ptr->next != NULL) {
      ptr = ptr->next;
    }
    ptr->next = temp;
  }
}

void deleteNode() {
  person *prev, *ptr = head, *tmp;
  int delId = 0;

  printf("Enter the id to delete: ");
  scanf("%d", &delId);

  if (head == NULL) {
    printf("List is empty\n");
    return;
  } else if (head->id == delId) {
    ptr = head;
    head = head->next;
    free(ptr);
  } else {
    for (ptr = head; ptr->next; ptr = ptr->next) {
      prev = ptr;
      if (ptr->next->id == delId) {
        tmp = ptr->next;
        prev->next = ptr->next->next;
        free(tmp);
        break;
      }
    }
  }
}

void display() {
  person *ptr = head;
  printf("---------------------------------------------------------------------"
         "\n");
  printf("%-5s", "ID");
  printf("%-15s", "Name");
  printf("%-20s", "Address");
  printf("%-20s", "Phone");
  printf("%-20s\n", "Email");
  printf("---------------------------------------------------------------------"
         "\n");

  while (ptr != NULL) {
    printf("%-5d", ptr->id);
    printf("%-15s", ptr->name);
    printf("%-20s", ptr->address);
    printf("%-20s", ptr->phone);
    printf("%-20s\n", ptr->email);
    ptr = ptr->next;
  }
  printf("---------------------------------------------------------------------"
         "\n");
}

void save() {
  FILE *fp = fopen("../address.txt", "w+");
  for (person *ptr = head; ptr; ptr = ptr->next) {
    fwrite(ptr, sizeof(person), 1, fp);
  }
  fclose(fp);
}

void append(person *p) {
  person *ptr, *temp;
  temp = (person *)malloc(sizeof(person));
  temp->id = p->id;
  strcpy(temp->name, p->name);
  strcpy(temp->address, p->address);
  strcpy(temp->phone, p->phone);
  strcpy(temp->email, p->email);
  temp->next = NULL;

  if (head == NULL) {
    head = temp;
  } else {
    ptr = head;
    while (ptr->next != NULL) {
      ptr = ptr->next;
    }
    ptr->next = temp;
  }
}

void readFile() {
  FILE *fp = fopen("../address.txt", "a+");
  person p;
  while (fread(&p, sizeof(person), 1, fp)) {
    if (lastId < p.id) {
      lastId = p.id;
    }
    append(&p);
  }
  fclose(fp);
}
