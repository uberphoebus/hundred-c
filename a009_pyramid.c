// 009 이중반복문 피라미드

#include <stdio.h>

int main() {
    printf("피라미드(1)\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j <= i; j++)
            printf("*");
        printf("\n");
    }
    printf("\n\n");

    printf("피라미드(2)\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < i * 2 + 1; j++)
            printf("*");
        printf("\n");
    }
    printf("\n\n");

    printf("피라미드(3)\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5 - i; j++)
            printf("*");
        printf("\n");
    }
    printf("\n\n");

    printf("피라미드(4)\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5 - i - 1; j++)
            printf(" ");
        for (int j = 0; j <= i; j++)
            printf("*");
        printf("\n");
    }
    printf("\n\n");

    printf("피라미드(5)\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4 - i; j++)
            printf(" ");
        for (int j = 0; j < i * 2 + 1; j++)
            printf("*");
        printf("\n");
    }
    printf("\n\n");

    printf("피라미드(6)\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < i; j++)
            printf(" ");
        for (int j = 0; j < 10 - (i * 2 + 1); j++)
            printf("*");
        printf("\n");
    }
}