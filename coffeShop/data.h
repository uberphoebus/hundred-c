typedef struct menuItem {
  int ida;
  char menuName[30];
  int price;
  struct menuItem *next;
} menuItem;

typedef struct orderNode {
  int orderId;
  int menuId;
  char menuName[30];
  int price;
  int sales;
  struct orderNode *next;
} orderNode;

typedef struct saleNode {
  int menuId;
  char menuName[30];
  int price;
  int sales;
  struct saleNode *next;
} saleNode;