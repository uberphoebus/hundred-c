// 018 포인터 연산
// p + i = p + i * sizeof(*p)
// p - q = (p - q) / sizeof(*p)

#include <stdio.h>

int main() {
    int a = 10;
    int b = 20;
    int c[5] = {1, 2, 3, 4, 5};

    int *pa = &a;
    int *pb = &b;
    int *pc;

    pc = c + 2; // pc = &c[2] = 3
    printf("[%p] %d\n", pc, *pc);

    pc = pc - 1; // pc = &c[1] = 2
    printf("[%p] %d\n", pc, *pc);

    pc = c; // pc = &c[0] = 1
    int *pd = &c[4];

    int cnt = pd - pc; // &c[4] - &c[0] = 4
    printf("[%p] [%p] %d\n", pd, pc, cnt);
}