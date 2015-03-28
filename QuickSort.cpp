/*
 * QUCK_SORT.cpp
 *
 *  Created on: 2015-3-26
 *      Author: hao
 */

#include <iostream>

using namespace std;

void exchange(int *array, int i, int j) {
  int tmp = array[i];
  array[i] = array[j];
  array[j] = tmp;
}

int partition(int *array, int s, int t) {
  int i = s - 1;
  int pivot = array[t];
  for (int j = s; j < t; j++) {
    if (array[j] < pivot) {
      i ++;
      exchange(array, i, j);
    }
  }

  exchange(array, i+1, t);
  return i+1;
}

void quick_sort(int *array, int s, int t) {
  if (s < t) {
    int p = partition(array, s, t);
    quick_sort(array, s, p-1);
    quick_sort(array, p+1, t);
  }
}
