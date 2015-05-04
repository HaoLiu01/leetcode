#include<iostream>
#include "QuickSort.h"
#include "QuickSelect.h"
#include "HeapSort.h"
#include "MergeSort.h"

using namespace std;

void printArray(int *array, int length, int start = 0) {
  for (int i = 0; i < length; i++)
    cout << array[i] << " ";
  cout << endl;
}

void TEST_QSelect() {
  cout << "TEST QSelect\n";

  int A[] = { 10, 8, 6, 4, 2, 0, 9, 7, 5, 3, 1 };
  int Kth = quick_select(A, 6, 2, 10);
  cout << Kth << endl;
}

void TEST_QSort() {
  cout << "TEST QSort\n";

  int array[10] = { 1, 8, 7, 6, 9, 10, 2, 3, 16, 4 };

  cout << "Before: ";
  printArray(array, 10, 0);

  quick_sort(array, 0, 9);

  cout << "After: ";
  printArray(array, 10, 0);
}

void TEST_HeapSort() {
  cout << "Test HeapSort" << endl;
  int array[10] = { 1, 8, 7, 6, 9, 10, 2, 3, 16, 4 };
  cout << "Before: ";
  printArray(array, 10, 0);

  HeapSort(array, 10);

  cout << "After: ";
  printArray(array, 10, 0);
}

void TEST_MergeSort() {
  cout << "Test MergeSort" << endl;
  int array[10] = { 1, 8, 7, 6, 9, 10, 2, 3, 16, 4 };
  cout << "Before: ";
  printArray(array, 10, 0);

  MergeSort(array, 0, 10);

  cout << "After: ";
  printArray(array, 10, 0);
}

int main() {
//  TEST_QSort();
  TEST_QSelect();
//  TEST_HeapSort();
//  TEST_MergeSort();
  return 0;
}
