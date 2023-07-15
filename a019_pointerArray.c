// 019 이중포인터와 포인터의 배열

#include <stdio.h>

int main() {
    int x = 10;
    int *ptr = &x;
    int **pptr = &ptr;
    int ***ppptr = &pptr;

    printf("%d %d %d %d\n", x, *ptr, **pptr, ***ppptr);

    char s[] = "abcd";
    char *t = "abcd";

    printf("[%p] = %s\n", s, s);
    printf("[%p] = %s\n", t, t);

    char *p[] = {"tiger", "lion", "zebra", "giraffe", "dragon"}; // 포인터 배열1
    char q[][10] = {"tiger", "lion", "zebra", "giraffe",
                    "dragon"}; // 포인터 배열2

    for (int i = 0; i < 5; i++) {
        printf("%s\n", p[i]);
    }
}