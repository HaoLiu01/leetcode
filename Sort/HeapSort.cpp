//============================================================================
// Author      : Hao Liu
// Description : Day 4: HEAP SORT from
//               http://cricode.com/970.html
//============================================================================

#include "QuickSort.h"

int parent(int i) {
  return i / 2;
}
int left(int i) {
  return i * 2 + 1;
}
int right(int i) {
  return i * 2 + 2;
}

void MaxHeapify(int *A, int i, int Len) {
  int l = left(i);
  int r = right(i);
  int max = i;
  if (l < Len && A[l] > A[i])
    max = l;

  if (r < Len && A[r] > A[max])
    max = r;

  if (max != i) {
    Exchange(A, max, i);
    MaxHeapify(A, max, Len);
  }
}

void BUILD_MAX_HEAP(int *A, int Len) {
  for (int i = Len / 2 - 1; i >= 0; i--) {
    MaxHeapify(A, i, Len);
  }
}

void HeapSort(int *A, int Len) {
  BUILD_MAX_HEAP(A, Len);

  for (int i = Len - 1; i >= 0; i--) {
    Exchange(A, 0, i);
    MaxHeapify(A, 0, i);
  }
}
