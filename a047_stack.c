#define _CRT_SECURE_NO_WARNINGS
// #include <conio.h>
#include <stdio.h>

#define MAXVAL 100

int stakc[MAXVAL]; // stack
int sp = 0;        // stack pointer

void push(int v) {
  if (sp < MAXVAL) {
    stakc[sp++] = v;
  } else {
    printf("error: stack full\n");
  }
}

int pop() {
  if (sp > 0) {
    return stakc[--sp];
  } else {
    printf("error: stack empty\n");
    return 0;
  }
}

void printStack() {
  printf("stack: ");
  for (int i = 0; i < sp; i++) {
    printf("%8d ", stakc[i]);
  }
  printf("\n");
}

int main() {
  int c, v;
  while (1) {
    printf("operation: i(insert), d(delete), q(quit) : ");

    c = getchar();
    printf("\n");

    switch (c) {
    case 'i':
      printf("value: ");
      scanf("%d", &v);
      push(v);
      // printStack(); // Move printStack() here to avoid duplicate output
      break;
    case 'd':
      v = pop();
      printf("deleted value: %d\n", v);
      // printStack(); // Move printStack() here to avoid duplicate output
      break;
    case 'q':
      return 0;
    }
    printStack();
  }
}