#include<iostream>
#include "QuickSort.h"
#include "QuickSelect.h"
#include "HeapSort.h"
#include "MergeSort.h"

using namespace std;

void printArray(int *array, int length, int start = 0) {
  for (int i = 0; i < length; i++)
    std::cout << array[i] << " ";
  std::cout << std::endl;
}

void TEST_QSelect() {
  std::cout << "TEST QSelect\n";

  int A[] = { 10, 8, 6, 4, 2, 0, 9, 7, 5, 3, 1 };
  int Kth = quick_select(A, 6, 2, 10);
  std::cout << Kth << std::endl;
}

void TEST_QSort() {
  std::cout << "TEST QSort\n";

  int array[10] = { 1, 8, 7, 6, 9, 10, 2, 3, 16, 4 };

  std::cout << "Before: ";
  printArray(array, 10, 0);

  quick_sort(array, 0, 9);

  std::cout << "After: ";
  printArray(array, 10, 0);
}

void TEST_HeapSort() {
  std::cout << "Test HeapSort" << std::endl;
  int array[10] = { 1, 8, 7, 6, 9, 10, 2, 3, 16, 4 };
  std::cout << "Before: ";
  printArray(array, 10, 0);

  HeapSort(array, 10);

  std::cout << "After: ";
  printArray(array, 10, 0);
}

void TEST_MergeSort() {
  std::cout << "Test MergeSort" << std::endl;
  int array[10] = { 1, 8, 7, 6, 9, 10, 2, 3, 16, 4 };
  std::cout << "Before: ";
  printArray(array, 10, 0);

  MergeSort(array, 0, 10);

  std::cout << "After: ";
  printArray(array, 10, 0);
}

int main() {
//  TEST_QSort();
  TEST_QSelect();
//  TEST_HeapSort();
//  TEST_MergeSort();
  return 0;
}
