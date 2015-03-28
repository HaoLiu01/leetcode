#ifndef QUICK_SORT_H
#define QUICK_SORT_H

void exchange(int *array, int i, int j);

int partition(int *array, int s, int t);

void printArray(int *array, int length);

void quick_sort(int *array, int s, int t);

#endif
