#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int key;
  struct node *left, *right;
} treeNode;

treeNode *makeNode(int data);
treeNode *insert(treeNode *node, int data);
treeNode *minNode(treeNode *node);
treeNode *deleteNode(treeNode *node, int data);

void inorder(treeNode *node);
void preorder(treeNode *node);
void postorder(treeNode *node);
void traverse(treeNode *root);

int main() {
  treeNode *root = NULL;
  int data[] = {10, 8, 6, 9, 7, 15, 12, 14};
  int del;

  for (int i = 0; i < 8; i++) {
    root = insert(root, data[i]);
  }
  traverse(root);

  while (1) {
    printf("\nEnter node to delete(-1 to exit): ");
    scanf("%d", &del);
    if (del == -1) {
      break;
    }
    root = deleteNode(root, del);
    traverse(root);
  }
}

treeNode *makeNode(int data) {
  treeNode *ptr = (treeNode *)malloc(sizeof(treeNode));
  ptr->key = data;
  ptr->left = ptr->right = NULL;
  return ptr;
}

treeNode *insert(treeNode *node, int data) {
  if (node == NULL) {
    return makeNode(data);
  }
  if (data < node->key) {
    node->left = insert(node->left, data);
  } else {
    node->right = insert(node->right, data);
  }
  return node;
}

treeNode *minNode(treeNode *node) {
  treeNode *cur = node;
  if (cur == NULL) {
    return NULL;
  }
  while (cur->left != NULL) {
    cur = cur->left;
  }
  return cur;
}

treeNode *deleteNode(treeNode *node, int data) {
  if (node == NULL) {
    return node;
  }
  if (data < node->key) {
    node->left = deleteNode(node->left, data);
  } else if (data > node->key) {
    node->right = deleteNode(node->right, data);
  } else {
    if (node->left == NULL) {
      treeNode *tmp = node->right;
      free(node);
      return tmp;
    } else if (node->right == NULL) {
      treeNode *tmp = node->left;
      free(node);
      return tmp;
    }
    treeNode *tmp = minNode(node->right);
    node->key = tmp->key;
    node->right = deleteNode(node->right, tmp->key);
  }
  return node;
}

void inorder(treeNode *node) {
  if (node != NULL) {
    inorder(node->left);
    printf("%d -> ", node->key);
    inorder(node->right);
  }
}

void preorder(treeNode *node) {
  if (node != NULL) {
    printf("%d -> ", node->key);
    preorder(node->left);
    preorder(node->right);
  }
}

void postorder(treeNode *node) {
  if (node != NULL) {
    postorder(node->left);
    postorder(node->right);
    printf("%d -> ", node->key);
  }
}

void traverse(treeNode *root) {
  printf("Inorder: ");
  inorder(root);
  printf("\nPreorder: ");
  preorder(root);
  printf("\nPostorder: ");
  postorder(root);
  printf("\n");
}