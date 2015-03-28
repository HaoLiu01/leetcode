//============================================================================
// Author      : Hao Liu
// Description : Day 4: HEAP SORT from
//               http://cricode.com/970.html
//============================================================================

#include "QUICK_SORT.h"

int parent(int i) { return i/2; }
int left(int i) { return i*2 + 1; }
int right(int i) { return i*2 + 2; }

void MAX_HEAPIFY(int *A, int i) {
  int l = left(i);
  int r = right(i);
  int max;
  if (A[i] > A[l])
    max = i;
  else
    max = l;

  if (A[max] < A[r])
    max = r;

  if (max != i) {
    exchange(A, max, i);
    MAX_HEAPIFY(A, max);
  }
}

void BUILD_MAX_HEAP(int *A, int Len) {
  for (int i= Len/2; i >= 0; i--) {
    MAX_HEAPIFY(A, i);
  }
}

void HEAP_SORT(int *A, int Len) {
  BUILD_MAX_HEAP(A, Len);

  for (unsigned i = Len - 1; i >= 0; i++) {
    exchange(A, 0, i);
    MAX_HEAPIFY(A, 0);
  }
}
