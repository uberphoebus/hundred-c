// 005 플레잉 카드 한벌을 랜덤하게 출력
// 카드 52장, 클로버 -> 하트 -> 스페이드 -> 다이아몬드 순

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 52 // 카드 개수가 max보다 크면 무한루프
#define CLOVER 0
#define HEART 1
#define SPADE 2
#define DIAMOND 3

int main() {
    int check[CARDS] = {0};       // 중복 체크 배열
    int cards_order[CARDS] = {0}; // 카드 순서 배열
    int rand_max = 52;            // 0 ~ 51
    char suit;                    // 카드 무늬

    srand(time(0));

    for (int i = 0; i < CARDS; i++) {
        int x;
        do {
            x = rand() % rand_max;
        } while (check[x] == 1); // 중복이면 다시 랜덤 숫자 생성
        check[x] = 1; // 중복 체크 배열에 중복이 아닌 것으로 표시
        cards_order[i] = x; // 랜덤 숫자 저장
    }

    printf("cards_order[]:\n");
    for (int i = 0; i < CARDS; i++) {
        printf("%5d%c", cards_order[i], (i + 1) % 13 == 0 ? '\n' : ' ');
    }
    printf("\n");

    printf("cards:\n");
    for (int i = 0; i < CARDS; i++) {
        int num = cards_order[i] % 13 + 1;
        switch (cards_order[i] / 13) {
        case CLOVER:
            suit = 'C';
            break;
        case HEART:
            suit = 'H';
            break;
        case SPADE:
            suit = 'S';
            break;
        case DIAMOND:
            suit = 'D';
            break;
        }
        printf("%c%2d%s", suit, num, (i + 1) % 13 == 0 ? "\n" : ", ");
    }
}