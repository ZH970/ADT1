//
// Created by zh137 on 2023/3/13.
//

#ifndef ADT_SLL_H
#define ADT_SLL_H

#endif//ADT_SLL_H

typedef struct node{
  node *next;
  int c;
  int e;
}node,*List;

void Init(List &L);
void Insert(List &L,int c,int e);
void input(List &L);
List sum(List L1,List L2);
void print(List L);
