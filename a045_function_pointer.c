// 045 함수 포인터
// 함수포인터는 주로 매개변수나 배열의 원소로 사용됨

#include <stdio.h>

int add(int a, int b) { return a + b; }

void hello() { printf("Hello, world!\n"); }

int main() {
    int (*ptr)(int, int) = add; // 함수 이름은 함수의 시작 주소
    void (*fptr)() = hello;

    printf("%d\n", ptr(10, 20));
    fptr();
}