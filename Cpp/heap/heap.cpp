//
// Created by zh137 on 2023/3/15.
//

#include "heap.h"
#include <cstdlib>
#include <iostream>

heap create (int Maxsize) {
  heap h;
  h.size = 0;
  h.cap = Maxsize;
  h.add(0);//ele[0]:guard
  return h;
}

void insert(int item, heap h) {
  std::cout << "Maxheap mod...\n";
  if (h.size == h.cap) {
    printf("Full");
    return;
  }
  int i = ++(h.size);
  if (h.ele[0] < item) {h.ele[0] = item;}
  for ( ;h.ele[i/2] < item;i/=2) {
    h.ele[i] = h.ele[i/2];
  }
  h.ele[i] = item;
}

int main() {
  auto h = create(5);
  int input;
  std::cout << "Insert:\n";
  std::cin >> input;
  insert(input, h);
}