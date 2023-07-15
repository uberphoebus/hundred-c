// 012 scanf() 함수 사용하기
// getchar()으로 \n 제거하기
// * : 입력받은 값을 저장하지 않고 버린다.
// %*d : 정수를 입력받아서 버린다.
// %5d : 최대 5자리 정수를 입력받는다.

#include <stdio.h>

int main() {
    char i;
    int a, b, c, d;
    int day, month, year;
    char s[100];

    int x = scanf("%d %c %d", &a, &i, &b); // 12+34
    c = getchar();                         // \n 제거
    printf("scanf return = %d\n", x);      // 3
    printf("(1) %d %c %d\n", a, i, b);     // 12 + 34

    scanf("%[0-9]", s);    // 1234abc567
    printf("(2) %s\n", s); // 1234

    scanf("%[^\n]", s);    // '\n'이 나올 때까지 입력받음
    printf("(3) %s\n", s); // abc567

    scanf("%*d%s", s);     // 1234abc
    printf("(4) %s\n", s); // abc

    scanf("%d%*c%d%*c%d", &day, &month, &year); // 30/08/2022
    printf("(5) %d %d %d\n", day, month, year); // 30 8 2022

    scanf("%d%*s%d%*s%d%*s", &year, &month, &day); // 2022년 8월 30일
    printf("(6) %d %d %d\n", year, month, day);    // 2022 8 30

    scanf("%5d%[^\n]", &d, s); // 1234567
    printf("(7) %d\n", d);

    scanf("%5d%2d", &a, &b); // 1234567
    printf("(8) %d %d\n", a, b);
}