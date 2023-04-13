//
// Created by zh137 on 2023/3/13.
//
#include "Tree.h"
#include <iostream>

int tree[5];
queue q;

void iac(Bt &bt) {
  int value = 0;
  std::cout << "Please input the tree with proper order:\n";
  std::cin >> value;
  if (value != 0) {
    bt = new node;
    bt->data = value;

    iac(bt->left);
    iac(bt->right);
  }
  else {
    bt = nullptr;
  }
}

void push(int n, queue* qe) {
  //Use preorder traversal
  qe->data[qe->rear] = n;
  if (qe->rear == Max) {
    qe->rear = 0;
  }
  else {
    qe->rear += 1;
  }
  if (qe->front == -1) {qe->front += 1;}
}

void output(Bt &bt) {
  //Use sequence output
  if (bt->data != 0) {
    push(bt->data,&q);
  }
  else {
    std::cout << "Error! Empty binary tree.\n";
    return ;
  }
  output(bt->left);
  output(bt->right);
}

/*
int main() {
  Bt T;
  q.front = -1;
  q.rear = 0;
  iac(T);
  push(T->data, &q);
  output(T);
  return 0;
}*/
