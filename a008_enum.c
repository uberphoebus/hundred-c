#include <stdio.h>

#define APPLE 1
#define BANANA 2
#define ORANGE 3

enum Fruit { Apple, Banana, Orange };
enum Day { Sun=1, Mon, Tue, Wed, Thu, Fri, Sat };

enum Size { Short, Tall, Grande, Venti };
char sizeName[][7] = { "Short", "Tall", "Grande", "Venti" };
int priceAmericano[] = { 3800, 4100, 4600, 5100 };
int priceCappuccino[] = { 4600, 5900, 6400, 6900 };

int main() {
  printf("coffee price table(americano)\n");
  for (int i = Short; i <= Venti; i++) {
    printf("%10s : %5d\n", sizeName[i], priceAmericano[i]);
  }
  printf("coffee price table(cappuccino)\n");
  for (int i = Short; i <= Venti; i++) {
    printf("%10s : %5d\n", sizeName[i], priceCappuccino[i]);
  }
}