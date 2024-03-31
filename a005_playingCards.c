#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 52
#define CLOVER 0
#define DIAMOND 1
#define HEART 2
#define SPADE 3

int check[CARDS] = {0};  // duplicate check
int cards_order[CARDS] = {0}; // random order
int rand_max = 51;
char suit;

int main(void) {
  srand(time(0));
  for (int i = 0; i < CARDS; i++) {
    int x;
    do {
      x = (int)((double)rand() / RAND_MAX * rand_max);
    } while (check[x] != 0);
    check[x] = 1;
    cards_order[i] = x;
  }

  printf("cards_order[]:\n");
  for (int i = 0; i < CARDS; i++) {
    printf("%-5d%c", cards_order[i], (i + 1) % 13 == 0 ? '\n':' ');
  }
  printf("\n");

  printf("cards :\n");
  for (int i = 0; i < CARDS; i++) {
    int denom = cards_order[i] % 13 + 1;
    switch (cards_order[i] / 13) {
      case CLOVER:
        suit = 'C';
        break;
      case DIAMOND:
        suit = 'D';
        break;
      case HEART:
        suit = 'H';
        break;
      case SPADE:
        suit = 'S';
        break;
    }
    printf("%c%2d%s", suit, denom, (i + 1) % 13 == 0 ? "\n":", ");
  }
}