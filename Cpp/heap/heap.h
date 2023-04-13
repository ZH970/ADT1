//
// Created by zh137 on 2023/3/15.
//
#include <vector>

#ifndef ADT_HEAP_H
#define ADT_HEAP_H

#endif // ADT_HEAP_H
struct heap{
  std::vector<int> ele;
  int size;
  int cap;

  void add(int s) {
    ele.push_back(s);
  }
};