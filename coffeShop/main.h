#ifndef MAIN_H
#define MAIN_H
#define _CRT_SECURE_NO_WARNINGS

#include "data.h"
#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern menuItem *menuItemList;
extern orderNode *orderList;

int passwordCheck();
void loadCoffeeMenu();
void insertCoffeeMenu(int id, const char *name, int price);

int deleteCoffeeMenu();
void mainMenu();
void showMainMenu();
void showCoffeeMenuList();
void showCoffeeMenu();
int close();
void waitZeroInput();
void showSaleToday();
void showOrderList();
void showOrders();
void saveMenuFile();
saleNode *addSales(saleNode *saleToday, orderNode *p);

#endif // !MAIN_H