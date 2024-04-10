#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

float add(float a, float b) { return a + b; }
float subtract(float a, float b) { return a - b; }
float multiply(float a, float b) { return a * b; }
float divide(float a, float b) { return a / b; }

int main() {
  float a, b;
  int choice;

  float (*func_ptr[4])(float, float) = {add, subtract, multiply, divide};

  printf("Enter two numbers: ");
  scanf("%f %f", &a, &b);
  printf("Enter 0 to add, 1 to subtract, 2 to multiply, 3 to divide: ");
  scanf("%d", &choice);
  printf("Result: %f\n", func_ptr[choice](a, b));
}