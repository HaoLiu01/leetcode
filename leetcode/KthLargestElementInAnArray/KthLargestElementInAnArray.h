/*
 * KthLargestElementInAnArray.h
 *
 *  Created on: Aug 15, 2015 11:40:17 AM
 *      Author: Hao Liu
 *      E-mail: haoliu233@163.com
 */

#ifndef LEETCODE_KTHLARGESTELEMENTINANARRAY_KTHLARGESTELEMENTINANARRAY_H_
#define LEETCODE_KTHLARGESTELEMENTINANARRAY_KTHLARGESTELEMENTINANARRAY_H_

/**********************************************************************************
 *
 * Find the kth largest element in an unsorted array.
 * Note that it is the kth largest element in the sorted order, not the kth distinct element.
 *
 * For example,
 * Given [3,2,1,5,6,4] and k = 2, return 5.
 *
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 *
 * Credits:Special thanks to @mithmatt for adding this problem and creating all test cases.
 *
 **********************************************************************************/

#include <vector>

void Exchange(std::vector<int> &array, int i, int j) {
  int tmp = array[i];
  array[i] = array[j];
  array[j] = tmp;
}

// Copy from quick sort.
int partition(std::vector<int> &array, int s, int t) {
  int i = s - 1;
  int pivot = array[t];
  for (int j = s; j < t; j++) {
    if (array[j] < pivot) {
      i++;
      Exchange(array, i, j);
    }
  }

  Exchange(array, i + 1, t);
  return i + 1;
}

int findKthFromHeadToTail(std::vector<int> &array, int head, int tail, int k) {
	int p = partition(array, head, tail);
	int nth = tail - p + 1;

	if (nth == k)
		return array[p];
	if (nth < k)
		return findKthFromHeadToTail(array, head, p - 1, k - nth);
	return findKthFromHeadToTail(array, p + 1, tail, k);
}

int findKthLargest(std::vector<int>& nums, int k) {
	std::vector<int> array = nums;
	return findKthFromHeadToTail(array, 0, array.size() - 1, k);
}

#endif /* LEETCODE_KTHLARGESTELEMENTINANARRAY_KTHLARGESTELEMENTINANARRAY_H_ */
