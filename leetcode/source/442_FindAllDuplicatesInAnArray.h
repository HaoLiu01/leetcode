/*
 * 442_FindAllDuplicatesInAnArray.h
 *
 *  Created on: 2016年11月4日
 *      Author: hao
 */

#ifndef LEETCODE_SOURCE_442_FINDALLDUPLICATESINANARRAY_H_
#define LEETCODE_SOURCE_442_FINDALLDUPLICATESINANARRAY_H_

#include "common.h"

vector<int> findDuplicates(vector<int>& nums) {
	vector<int> res;
	set<int> cache;
	for (auto i : nums)
		if (cache.count(i))
			res.push_back(i);
		else
			cache.insert(i);
	return res;
}

//Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
//
//Find all the elements that appear twice in this array.
// Could you do it without extra space and in O(n) runtime?
//
// 使得nums[i] == i + 1
vector<int> findDuplicates2(vector<int>& nums) {
	vector<int> res;
	int i = 0;
	while (i < nums.size()) {
		// make sure that nums[nums[i] - 1】 == nums[i],
		// I.E. nums[a - 1] = a Or nums[a] = a + 1
		if (nums[i] != nums[nums[i] - 1])
			swap(nums[i], nums[nums[i] - 1]);
		else
			i++;
	}
	for (i = 0; i < nums.size(); i++) {
		if (nums[i] != i + 1)
			res.push_back(nums[i]);
	}
	return res;
}

#endif /* LEETCODE_SOURCE_442_FINDALLDUPLICATESINANARRAY_H_ */
