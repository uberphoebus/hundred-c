// 055 연결리스트에서 데이터 삭제
// 헤드 노드를 삭제할 경우, 헤드 노드의 다음 노드를 헤드 노드로 지정하고 free
// 중간 노드를 삭제할 경우, 앞의 노드를 뒤의 노드로 연결 후 free

#include <stdio.h>
#include <stdlib.h>

void append();       // 리스트의 맨 뒤에 노드 추가
void insert();       // 리스트의 맨 앞에 노드 추가
void insert_pos();   // 리스트의 특정 위치에 노드 추가
void display();      // 리스트의 노드들을 출력
void delete_begin(); // 리스트의 맨 앞 노드 삭제
void delete_end();   // 리스트의 맨 뒤 노드 삭제
void delete_pos();   // 리스트의 특정 위치에 있는 노드 삭제

struct node {
    int value;
    struct node *next;
};

struct node *head = NULL; // 리스트의 첫 노드를 가리키는 포인터

int main() {
    int choice;

    while (1) {
        printf("\n============ MENU ============\n");
        printf("1. Append\n");
        printf("2. Insert\n");
        printf("3. Insert at position\n");
        printf("4. Display\n");
        printf("5. Delete beginning\n");
        printf("6. Delete end\n");
        printf("7. Delete at position\n");
        printf("0. Exit\n");
        printf("------------------------------\n");

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
        case 5:
            delete_begin();
            break;
        case 6:
            delete_end();
            break;
        case 7:
            delete_pos();
            break;
        case 0:
            exit(0);
        }
        display();
    }
}

void append() {
    struct node *temp, *ptr; // 새로운 노드를 가리킬 포인터

    temp = (struct node *)malloc(sizeof(struct node)); // 새로운 노드 생성
    if (temp == NULL) { // 메모리 할당 실패
        printf("Out of memory!\n");
        exit(0);
    }

    printf("\nEnter value: ");
    scanf("%d", &temp->value); // 새로운 노드의 값 입력
    temp->next = NULL; // 새로운 노드의 다음 노드를 NULL로 초기화

    if (head == NULL) {             // 리스트가 비어있을 경우
        head = temp;                // 새로운 노드를 첫 노드로 지정
    } else {                        // 리스트가 비어있지 않으면
        ptr = head;                 // 첫 노드부터 시작
        while (ptr->next != NULL) { // 마지막 노드를 찾을 때까지
            ptr = ptr->next;        // 다음 노드로 이동
        }
        ptr->next = temp; // 마지막 노드의 다음 노드로 새로운 노드를 지정
    }
}

void insert() {
    struct node *temp =
        (struct node *)malloc(sizeof(struct node)); // 새로운 노드 생성

    if (temp == NULL) { // 메모리 할당 실패
        printf("Out of memory!\n");
        exit(0);
    }

    printf("Enter value: ");
    scanf("%d", &temp->value); // 새로운 노드의 값 입력
    temp->next = NULL; // 새로운 노드의 다음 노드를 NULL로 초기화

    if (head == NULL) { // 리스트가 비어있을 경우
        head = temp;    // 새로운 노드를 첫 노드로 지정
    } else {            // 리스트가 비어있지 않으면
        temp->next = head; // 새로운 노드의 다음 노드로 첫 노드를 지정
        head = temp; // 새로운 노드를 첫 노드로 지정
    }
}

void insert_pos() {
    struct node *ptr, *temp;
    int i, pos;

    temp = (struct node *)malloc(sizeof(struct node)); // 새로운 노드 생성
    if (temp == NULL) { // 메모리 할당 실패
        printf("Out of memory!\n");
        exit(0);
    }

    printf("Enter position to insert : ");
    scanf("%d", &pos);
    printf("Enter value: ");
    scanf("%d", &temp->value); // 새로운 노드의 값 입력
    temp->next = NULL; // 새로운 노드의 다음 노드를 NULL로 초기화

    if (pos == 0) {        // 리스트의 맨 앞에 삽입
        temp->next = head; // 새로운 노드의 다음 노드로 첫 노드를 지정
        head = temp; // 새로운 노드를 첫 노드로 지정
    } else {
        for (i = 0, ptr = head; i < pos - 1; i++) { // 포인터를 헤드부터 이동
            ptr = ptr->next;                        // 다음 노드로 이동
            if (ptr == NULL) { // 노드의 개수보다 큰 위치에 삽입
                printf("Cannot insert at %d\n", pos);
                return;
            }
        }
        temp->next =
            ptr->next; // 새로운 노드의 다음 노드로 ptr의 다음 노드를 지정
        ptr->next = temp; // ptr의 다음 노드로 새로운 노드를 지정
    }
}

void display() {
    struct node *ptr = head;

    if (ptr == NULL) {
        printf("List is empty!\n");
        return;
    } else {
        printf("\nList:");
        while (ptr != NULL) {
            printf(" %d ->", ptr->value);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void delete_begin() {
    struct node *ptr = head;

    if (ptr == NULL) {
        printf("List is empty!\n");
        return;
    } else {
        head = head->next; // 헤드 노드를 두 번째 노드로 지정
        printf("The deleted node is : %d\n", ptr->value);
        free(ptr); // 첫 번째 노드를 메모리에서 해제
    }
}

void delete_end() {
    struct node *temp = NULL, *ptr = NULL;

    if (head == NULL) {
        printf("List is empty!\n");
        exit(0);
    } else if (head->next == NULL) {
        ptr = head;
        head = NULL;
        printf("The deleted node is : %d\n", ptr->value);
        free(ptr);
    } else {
        ptr = head;
        while (ptr->next != NULL) {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = NULL;
        printf("\nThe deleted node is : %d\n", ptr->value);
        free(ptr);
    }
}

void delete_pos() {
    int i, pos;
    struct node *temp = NULL, *ptr = NULL;

    if (head == NULL) {
        printf("List is empty!\n");
        exit(0);
    } else {
        printf("Enter position to delete: ");
        scanf("%d", &pos);
        if (pos == 0) {
            ptr == head;
            head = head->next;
            printf("The deleted node is : %d\n", ptr->value);
            free(ptr);
        } else {
            ptr = head;
            for (i = 0; i < pos; i++) {
                temp = ptr;
                ptr = ptr->next;
                if (ptr == NULL) {
                    printf("Position not found!\n");
                    return;
                }
            }
            temp->next = ptr->next;
            printf("The deleted node is : %d\n", ptr->value);
            free(ptr);
        }
    }
}