// 036 qsort
// qsort 사용시 비교함수 compare 필요
// 배열에 저장된 원소의 형과 비교하는 규칙이 다를 수 있기 때문
// compare 함수는 두 원소의 주소를 인자로 받아서 비교 결과를 리턴

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int id;
    char name[20];
    int score;
};

int compare1(const void *p, const void *q) {
    // 학번 순으로 정렬
    int a = ((struct student *)p)->id; // p를 student 구조체 포인터로 캐스팅
    int b = ((struct student *)q)->id;
    return a - b; // 오름차순 정렬
}

int compare2(const void *p, const void *q) {
    // 점수 순으로 정렬
    int a = ((struct student *)p)->score;
    int b = ((struct student *)q)->score;
    return b - a; // 내림차순 정렬
}

int compare3(const void *p, const void *q) {
    // 이름 순으로 정렬
    char *a = ((struct student *)p)->name;
    char *b = ((struct student *)q)->name;
    return strcmp(a, b); // 오름차순 정렬
}

void printArr(struct student a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%5d %10s %4d\n", a[i].id, a[i].name, a[i].score);
    }
    printf("\n");
}

int main() {
    struct student a[] = {
        {1001, "steve", 88}, {1003, "tom", 98}, {1002, "jane", 76}};

    printf("sort by id(asc)\n");
    // 배열, 원소 개수, 원소 크기, 비교함수
    qsort(a, 3, sizeof(struct student), compare1);
    printArr(a, 3);

    printf("sort by score(desc)\n");
    qsort(a, 3, sizeof(struct student), compare2);
    printArr(a, 3);

    printf("sort by name(asc)\n");
    qsort(a, 3, sizeof(struct student), compare3);
    printArr(a, 3);
}