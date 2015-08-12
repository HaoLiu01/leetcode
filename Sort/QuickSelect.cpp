/*
 * QUICK_SELECT.cpp
 *
 *  Created on: 2015-3-27
 *      Author: hao
 */

#include<iostream>
#include "QuickSort.h"

int quick_select(int *A, int k, int head, int tail) {
  int p = partition(A, head, tail);
  int N = p - head + 1;
  if (N == k)
    return A[p];
  else if (N < k)
    return quick_select(A, k - N, p + 1, tail);
  else
    return quick_select(A, k, head, p - 1);
}

//============================================================================
// Author      : Hao Liu
// Description : Day 3: Google test related to quick_select learning:
//               taop.marchtea.com/02.01.html
//============================================================================

void google_ABandK(int *A, int *B, int AL, int BL, int k) {
  int C[AL * BL];
  for (int i = 0; i < AL; i++)
    for (int j = 0; j < BL; j++)
      C[i * BL + j] = B[j] + A[i];

  int KthV = quick_select(C, k, 0, AL * BL - 1);
  int count = 0;
  for (int i = 0; i < AL * BL; i++)
    if (C[i] < KthV) {
      std::cout << C[i] << " ";
      count++;
    }

  for (int i = 0; i < k - count; i++)
    std::cout << KthV << "";
}
