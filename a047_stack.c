// 047 stack
// Last-In-First-Out (LIFO)
// push, pop
// 스택의 마지막 인덱스를 스택 포인터로 사용
// push할 때 오버플로우 체크, pop할 때는 스택이 비었는지 체크

#include <stdio.h>
#define MAXVAL 100

int stack[MAXVAL]; // stack
int sp = 0;        // stack pointer

void push(int v) {
    if (sp < MAXVAL)     // stack overflow check
        stack[sp++] = v; // push
    else
        printf("stack full\n");
}

int pop() {
    if (sp > 0)             // stack underflow check
        return stack[--sp]; // pop
    else {
        printf("error: stack empty\n");
        return 0;
    }
}

void printStack() {
    printf("Stack : ");
    for (int i = 0; i < sp; i++)
        printf("%8d ", stack[i]);
    printf("\n");
}

int main() {
    char c;
    int v;
    while (1) {
        printf("Operation: i(insert), d(delete), q(quit) : ");
        scanf(" %c", &c);

        switch (c) {
        case 'i':
            printf("Enter a number : ");
            scanf("%d", &v);
            push(v);
            break;
        case 'd':
            printf("%d removed\n", pop());
            break;
        case 'q':
            return 0;
        }
        printStack();
    }
}