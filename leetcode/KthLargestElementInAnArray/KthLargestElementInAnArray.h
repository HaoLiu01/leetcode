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

int partition(vector<int>& nums, int head, int tail) {
    int i = head, j = tail;
    while(nums[++i] <= nums[head]);

    while(nums[--j] >= nums[head]);

    for (int i = head + 1, j = tail; i != j;) {
        ;
    }
}

int reverse(vector<int>& nums, int head, int tail, int k) {
    if (head > tail)
        return 0;

    int mid = head + tail / 2;

}

int findKthLargest(vector<int>& nums, int k) {
    return 0;
}

#endif /* LEETCODE_KTHLARGESTELEMENTINANARRAY_KTHLARGESTELEMENTINANARRAY_H_ */
