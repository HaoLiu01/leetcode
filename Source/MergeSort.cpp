#include "MergeSort.h"

void Merge(int *A, int head, int plen, int len) {
  int n1 = plen;
  int n2 = len - plen;
  int L[n1], R[n2];
  for (int i = 0; i < n1; i++)
    L[i] = A[head + i];
  for (int i = 0; i < n2; i++)
    R[i] = A[head + plen + i]; //?
  int i = 0, j = 0, k = head;
  for (; k < head + len && i < n1 && j < n2;)
    if (L[i] < R[j])
      A[k++] = L[i++];
    else
      A[k++] = R[j++];

  // Handle left elements.
  if (i == n1)
    for (; j < n2;)
      A[k++] = R[j++];
  else
    for (; i < n1;)
      A[k++] = L[i++];
}

void MergeSort(int *A, int head, int len) {
  if (len > 1) {
    int plen = len / 2;
    MergeSort(A, head, plen);
    MergeSort(A, head + plen, len - plen);
    Merge(A, head, plen, len);
  }
}
