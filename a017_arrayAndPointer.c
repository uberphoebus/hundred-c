// 017 포인터와 배열
// 배열의 이름은 배열의 첫 번째 요소의 주소와 같다.
// int *p = a = &a[0]
// p + i = a + i = &a[i]
// *p = *a = a[0]
// a[i] = *(a + i) = *(p + i) = p[i]

#include <stdio.h>

int add3(int *p) {
    int sum = 0;

    for (int i = 0; i < 3; i++) {
        sum += *(p + i);
    }
    return sum;
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p;

    p = a;

    printf("[%p] %d\n", p, *p);
    printf("[%p] %d\n", a, *a);
    printf("[%p] %d\n", &a[0], a[0]);

    for (int i = 0; i < 10; i++) {
        *(p + i) = *(p + i) * 10; // a[i] = a[i] * 10;
    }

    printf("[%p] %d\n", p + 2, *(p + 2));
    printf("[%p] %d\n", a + 2, *(a + 2));
    printf("[%p] %d\n", &a[2], a[2]);

    printf("add 3 elements: %d\n", add3(a)); // a[0] + a[1] + a[2]
    p++;
    // a++; // error

    printf("add 3 elements: %d\n", add3(p)); // p[1] + p[2] + p[3]
}