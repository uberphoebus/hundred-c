#include "main.h"

int main() {
  if (passwordCheck() == 0) {
    return 0;
  }

  loadCoffeeMenu();
  // loadTodaySales();
  // mainMenu();
}

int passwordCheck() {
  int password;
  printf("\n\t\tCoffee Shop Management System\n");
  printf("\t\tEnter Password: ");
  scanf("%d", password);
  if (password == 1234) {
    return 1;
  } else {
    printf("Password is incorrect.\n");
    sleep(1000);
    return 0;
  }
}

void loadCoffeeMenu() {
  FILE *fp;
  menuItem *tmp = menuItemList;
  char line[80], menuName[30];
  int id, price;

  fp = fopen("../menu.txt", "r");
  if (fp == NULL) {
    printf("[load menu] File not found.\n");
    return;
  }

  while (fgets(line, 80, fp) != NULL) {
    sscanf(line, "%d %s %d", &id, menuName, &price);
    insertCoffeeMenu(id, menuName, price);
  }
}
