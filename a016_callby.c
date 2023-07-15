// 016 call by value / reference

#include <stdio.h>

// call by value
void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

// call by reference
void swap2(int *px, int *py) {
    int temp = *px;
    *px = *py;
    *py = temp;
}

int main() {
    int x = 3;
    int y = 4;

    swap(x, y);
    printf("swap()  : x = %d, y = %d\n", x, y);

    swap2(&x, &y);
    printf("swap2() : x = %d, y = %d\n", x, y);
}