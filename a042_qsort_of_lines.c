// 042 문자열 정렬

#include <malloc.h>
#include <stdio.h>
#include <string.h>

#define MAXLINES 1000
#define MAXLEN 1000

char *lineptr[MAXLINES] = {NULL}; // 입력된 문자열을 저장할 포인터 배열

void writelines(char *lineptr[]) { // 정렬된 문자열을 출력
    char **ptr = lineptr;
    while (*ptr != NULL) {
        printf("%s\n", *ptr++);
    }
}

void swap(char *v[], int i, int j) { // v[i]와 v[j]를 교환
    char *temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void my_qsort(char *v[], int left, int right) {
    int i, last;

    if (left >= right)
        return;

    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    }

    swap(v, left, last);

    my_qsort(v, left, last - 1);
    my_qsort(v, last + 1, right);
}

int main() {
    int nlines = 0;
    char line[MAXLEN];

    printf("Enter lines to sort.\n");
    while (fgets(line, MAXLEN, stdin) != NULL) {
        if (!strcmp(line, "\n"))
            break;

        line[strlen(line) - 1] =
            '\0'; // fgets는 \n을 포함해서 읽어오므로 \n을 \0으로 바꿔준다.
        lineptr[nlines] = (char *)malloc(strlen(line) + 1);
        if (lineptr[nlines] != NULL) {
            strcpy(lineptr[nlines++], line);
        }
        nlines++;
    }

    my_qsort(lineptr, 0, nlines - 1);
    writelines(lineptr);
}