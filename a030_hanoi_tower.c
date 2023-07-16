// 030 하노이의 탑과 메르센 수
// n개의 원반 이동과정에서 (n-1)개 원반 이동과정 -> 재귀
// 메르센 수 : 2^p - 1

#include <math.h>
#include <stdio.h>

void hanoi_tower(int n, char from, char to, char via) {
    if (n == 1)
        printf("Move : %c -> %c\n", from, to);
    else {
        hanoi_tower(n - 1, from, via, to);
        printf("Move : %c -> %c\n", from, to);
        hanoi_tower(n - 1, via, to, from);
    }
}
double mersenne(int i) { return pow(2, i) - 1; }

int main() {
    hanoi_tower(4, 'A', 'C', 'B'); // from, to, via
    int size = 50;

    for (int i = 2; i <= size; i++) {
        double m = mersenne(i);
        printf("M(%2d) = %18.0f = %18.1f일 = %18.1f년\n", i, m, m / 3600 / 24,
               m / 3600 / 24 / 365);
    }
}