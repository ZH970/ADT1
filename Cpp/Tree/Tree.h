//
// Created by zh137 on 2023/3/13.
//

#ifndef ADT_TREE_H
#define ADT_TREE_H

#endif // ADT_TREE_H

#define Max 20

typedef struct node {
  int data;
  node *left;
  node *right;
  node() {
    left = nullptr;
    right = nullptr;
  }
}BiTreeNode, *Bt;

typedef struct Queue {
  int data[Max];
  int front;
  int rear;
} queue;

void iac(Bt &bt);