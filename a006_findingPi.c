// 006 원주율 계산
// pi = 4(1 - 1/3 + 1/5 - 1/7 + 1/9 - ...)
// sign = 1, -1, 1, -1, 1, -1, ...

#include <stdbool.h>
#include <stdio.h>

int main() {
    bool sign = false; // false: -, true: +
    double pi = 0.0;

    for (int i = 1; i <= 100000000; i += 2) {
        if (sign == false) {
            pi += 1.0 / i;
            sign = true;
        } else {
            pi -= 1.0 / i;
            sign = false;
        }

        if (i < 20 || i > 99999990)
            printf("i = %10d, pi = %.18f\n", i, pi * 4);
    }
}