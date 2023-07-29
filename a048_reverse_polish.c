// 048 스택 reverse polish 계산기 -> 점검
// 산술식을 이진트리(수식트리)로 표현하는 후위표현식 사용
// 피연산자면 push, 연산자면 스택에서 pop을 두번해서 연산하고 계산 결과 push

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define MAXVAL 100
#define NUMBER '0'

float stack[MAXVAL]; // stack
int sp = 0;          // stack pointer

int getop(char s[]) {
    int i, c;

    while ((s[0] = c = getchar()) == ' ' || c == '\t')
        ; // skip white space

    s[1] = '\0';
    if (isdigit(c))
        while (isdigit(s[++i] = c = getchar()))
            ; // collect integer part
    if (c == '.')
        while (isdigit(s[++i] = c = getchar()))
            ; // collect fraction part
    s[i] = '\0';
    if (c != '\0')
        ungetc(c, stdin); // push back character

    return NUMBER;
}

void push(float f) {
    if (sp < MAXVAL)     // stack overflow check
        stack[sp++] = f; // push
    else
        printf("stack full\n");
}

float pop() {
    if (sp > 0)             // stack underflow check
        return stack[--sp]; // pop
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int main() {
    int type;
    double op2;
    char s[MAXOP];

    int i, c;
    while ((s[0] = c = getchar()) != EOF) {
        if (isdigit(c)) {
            ungetc(c, stdin);
            scanf("%d", &i);
            push(i);
        } else {
            switch (c) {
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
            }
        }
    }
}