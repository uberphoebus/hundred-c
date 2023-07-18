// 038 이진탐색 bsearch
// compare 함수 필요
// 반환값은 key가 저장된 곳의 포인터, key가 없으면 NULL 반환

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main() {
    int a[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int *ptr; // bsearch의 반환값을 받을 포인터
    int key;

    printf("key? ");
    scanf("%d", &key);

    // bsearch(찾을 값, 배열 이름, 배열의 요소 개수, 요소의 크기, compare)
    ptr = (int *)bsearch(&key, a, 10, sizeof(int), compare);

    if (ptr == NULL)
        printf("%d은(는) 배열 안에 없습니다.\n", key);
    else
        printf("%d은(는) a[%ld]번째에 있습니다.\n", *ptr, ptr - a);
}