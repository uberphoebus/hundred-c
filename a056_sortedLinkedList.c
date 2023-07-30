// 056 정렬된 연결리스트

#include <stdio.h>
#include <stdlib.h>

void insert_list(); // 연결리스트에 새로운 노드 삽입
void delete_list(); // 연결리스트에서 노드 삭제
void display();     // 연결리스트 출력

struct node {
    int value;
    struct node *next;
};

struct node *head = NULL; // 연결리스트의 시작 노드를 가리키는 포인터

int main() {
    int choice;

    while (1) {
        printf("\n============ MENU ============\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("0. Exit\n");
        printf("------------------------------\n");

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
        }
        display();
    }
}

void display() {
    struct node *ptr = head;

    if (ptr == NULL) {
        printf("List is empty.\n");
        return;
    } else {
        printf("List: ");
        while (ptr != NULL) {
            printf("%d -> ", ptr->value);
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
        printf("Out of memory!\n");
        return;
    }

    printf("Enter data : ");
    scanf("%d", &value);
    temp->value = value; // 새로운 노드에 데이터 저장
    temp->next = NULL; // 새로운 노드의 다음 노드를 NULL로 초기화

    if (head == NULL) {
        head = temp; // 연결리스트가 비어있으면 새로운 노드를 첫 노드로 지정
    } else if (head->value > value) { // 첫 노드보다 작은 값이 들어오면
        temp->next = head; // 새로운 노드의 다음 노드를 첫 노드로 지정
        head = temp; // 새로운 노드를 첫 노드로 지정
    } else {
        for (ptr = head; ptr->next; ptr = ptr->next) {
            if (ptr->next->value > value) { // 다음 노드보다 작으면
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
        printf("Empty List. Return without deleting!\n");
        return;
    }

    printf("Enter data to delete: ");
    scanf("%d", &data);

    if (head->value == data) { // 첫 노드가 삭제할 노드인 경우
        head = head->next;
        free(ptr);
        return;
    }

    for (ptr = head; ptr->next; ptr = ptr->next) { // 순회
        if (ptr->next->value == data) { // 다음 노드가 삭제할 노드인 경우
            tmp = ptr->next;
            ptr->next = ptr->next->next;
            printf("%d deleted!\n", tmp->value);
            free(tmp);
            return;
        }
    }
    printf("Data not found!\n");
}