#define _CRT_SECURE_NO_WARNINGS
#define PI 3.141592
#include <stdio.h>

void menu();
void circleMenu();
void squareMenu();
void sphareMenu();

int main() {
  int choice;

  do {
    menu();
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      circleMenu();
      break;
    case 2:
      squareMenu();
      break;
    case 3:
      sphareMenu();
      break;
    default:
      break;
    }
  } while (choice != 4);
}

void menu() {
  printf("----- Menu -----\n");
  printf("1. Circle\n");
  printf("2. Square\n");
  printf("3. Sphare\n");
  printf("4. Exit\n");
  printf("Select: ");
}

void circleMenu() {
  float result, num;

  printf("Enter the radius: ");
  scanf("%f", &num);
  result = PI * num * num;
  printf("Area of circle: %.2f\n", result);
}

void squareMenu() {
  float result, num;

  printf("Enter the side: ");
  scanf("%f", &num);
  result = num * num;
  printf("Area of square: %.2f\n", result);
}

void sphareMenu() {
  float result, radius;

  printf("Enter the radius: ");
  scanf("%f", &radius);
  result = 4.0 * PI * radius * radius;
  printf("Area of sphare: %.2f\n", result);
}