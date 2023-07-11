// 001 정수를 배열에 저장 -> 최소값, 최대값, 평균값 출력
// 1. 배열의 크기만큼 정수를 입력받는다.
// 2. 입력받은 정수를 배열에 저장한다.
// 3. 배열에 저장된 정수 중에서 최소값, 최대값, 평균값을 출력한다.

#include <stdio.h>

int main() {
    int a[10];    // 저장 배열
    int min, max; // 최소값, 최대값
    int sum = 0;  // 평균을 위한 합계

    for (int i = 0; i < 10; i++) {
        printf("%d번째 숫자를 입력하세요 : ", i + 1);
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < 10; i++) {
        printf("%3d ", a[i]);
    }
    printf("\n");

    min = max = a[0];

    for (int i = 0; i < 10; i++) {
        sum += a[i];
        if (min > a[i])
            min = a[i];
        else if (max < a[i])
            max = a[i];
    }

    printf("min = %d\n", min);
    printf("max = %d\n", max);
    printf("avg = %.2f\n", sum / 10.0);
}