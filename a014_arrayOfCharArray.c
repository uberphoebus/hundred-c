// 014 문자열의 배열
// 문자배열의 배열로 저장 -> char의 2차원 배열

#include <stdio.h>
#include <string.h>

int main() {
    char name1[][20] = {"kang", "cho", "kim"};
    char name2[][20] = {{'k', 'a', 'n', 'g'}, {'c', 'h', 'o'}, {'k', 'i', 'm'}};

    for (int i = 0; i < 3; i++) {
        printf("%14s", name1[i]);
    }
    printf("\n");

    for (int i = 0; i < 3; i++) {
        printf("%14s", name2[i]);
    }
    printf("\n");

    strcpy(name1[0], "스티브 잡스"); // name1[0]에 "스티브 잡스"를 복사
    strcpy(name1[1], "빌 게이츠");
    strcpy(name1[2], "데니스 리치");

    for (int i = 0; i < 3; i++) {
        printf("%20s", name1[i]);
    }
    printf("\n");
}