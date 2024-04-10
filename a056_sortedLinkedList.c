#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void insert_list();
void delete_list();
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
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("0. Exit\n");
    printf("\n------------------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      insert_list();
      break;
    case 2:
      delete_list();
      break;
    case 3:
      display();
      break;
    case 0:
      exit(0);
    default:
      printf("Invalid choice\n");
    }
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

void insert_list() {
  struct node *ptr, *temp;
  int i, value;
  temp = (struct node *)malloc(sizeof(struct node));
  if (temp == NULL) {
    printf("Memory was not allocated\n");
    return;
  }

  printf("Enter the value for the node: ");
  scanf("%d", &value);
  temp->value = value;
  temp->next = NULL;

  if (head == NULL) {
    head = temp;
  } else if (head->value > value) {
    temp->next = head;
    head = temp;
  } else {
    for (ptr = head; ptr->next; ptr = ptr->next) {
      if (ptr->next->value > value) {
        temp->next = ptr->next;
        ptr->next = temp;
        return;
      }
    }
    ptr->next = temp;
  }
}

void delete_list() {
  int data;
  struct node *ptr = head, *tmp;

  if (head == NULL) {
    printf("List is empty\n");
    return;
  }

  printf("Enter the value to be deleted: ");
  scanf("%d", &data);

  if (head->value == data) {
    head = head->next;
    free(tmp);
    return;
  }

  for (ptr = head; ptr->next; ptr = ptr->next) {
    if (ptr->next->value == data) {
      tmp = ptr->next;
      ptr->next = ptr->next->next;
      free(tmp);
      return;
    }
  }
  printf("Element not found\n");
}