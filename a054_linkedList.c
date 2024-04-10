#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void append();
void insert();
void insert_pos();
void display();

struct node {
  int value;
  struct node *next;
};

struct node *head = NULL;

int main() {
  int choice;
  while (1) {
    printf("\n==============================\n");
    printf("1. Append\n");
    printf("2. Insert\n");
    printf("3. Insert at position\n");
    printf("4. Display\n");
    printf("0. Exit\n");
    printf("\n------------------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      append();
      break;
    case 2:
      insert();
      break;
    case 3:
      insert_pos();
      break;
    case 4:
      display();
      break;
    case 0:
      exit(0);
    default:
      printf("Invalid choice\n");
    }
  }
}

void append() {
  struct node *temp;
  struct node *ptr;
  temp = (struct node *)malloc(sizeof(struct node));
  if (temp == NULL) {
    printf("Out of memory\n");
    exit(0);
  }
  printf("Enter the value: ");
  scanf("%d", &temp->value);
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

void insert() {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  if (temp == NULL) {
    printf("Out of memory\n");
    return;
  }
  printf("Enter the value: ");
  scanf("%d", &temp->value);
  temp->next = NULL;

  if (head == NULL) {
    head = temp;
  } else {
    temp->next = head;
    head = temp;
  }
}

void insert_pos() {
  struct node *temp, *ptr;
  int pos, i;

  temp = (struct node *)malloc(sizeof(struct node));
  if (temp == NULL) {
    printf("Out of memory\n");
    return;
  }

  printf("Enter the position: ");
  scanf("%d", &pos);
  printf("Enter the value: ");
  scanf("%d", &temp->value);
  temp->next = NULL;

  if (pos == 0) {
    temp->next = head;
    head = temp;
  } else {
    for (i = 0, ptr = head; i < pos - 1; i++) {
      ptr = ptr->next;
      if (ptr == NULL) {
        printf("Position not found\n");
        return;
      }
    }
    temp->next = ptr->next;
    ptr->next = temp;
  }
}

void display() {
  struct node *ptr = head;
  if (ptr == NULL) {
    printf("List is empty\n");
    return;
  } else {
    printf("List is: ");
    while (ptr != NULL) {
      printf("%d ->\t", ptr->value);
      ptr = ptr->next;
    }
    printf("\n");
  }
}