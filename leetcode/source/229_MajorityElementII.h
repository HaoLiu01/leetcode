/*
 * 229_MajorityElementII.h
 *
 *  Created on: 2016年11月6日
 *      Author: hao
 */

#ifndef LEETCODE_SOURCE_229_MAJORITYELEMENTII_H_
#define LEETCODE_SOURCE_229_MAJORITYELEMENTII_H_
/*
 Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.

 Hint:

 How many majority elements could it possibly have?
 0-2 elements.  ⌊ 8/3 ⌋ = 2
 */

//vector<int> majorityElement(vector<int>& nums) {
//
//}
#include "common.h"

bool isCandidate(int count, int candidate, int num) {
	return count != 0 && candidate == num;
}

vector<int> majorityElementII(vector<int>& nums) {
	int countA = 0, countB = 0, candidateA, candidateB;
	for (int i = 0; i < nums.size(); i++) {
		if (isCandidate(countA, candidateA, nums[i])) {
			countA++;
			continue;
		}
		if (isCandidate(countB, candidateB, nums[i])) {
			countB++;
			continue;
		}

		// So countA == 0 || countB == 0
		if (countA == 0) {
			countA++;
			candidateA = nums[i];
			continue;
		}
		if (countB == 0) { // countB == 0
			countB++;
			candidateB = nums[i];
			continue;
		}

		// Remove 3 different elements, don't affect the result
		countA--;
		countB--;
		continue;
	}

	vector<int> res;
	// A and B may be the result, check the total number.
	if (countA != 0) {
		int count = 0;
		for (auto i : nums)
			if (i == candidateA)
				count++;
		if (count > nums.size() / 3)
			res.push_back(candidateA);
	}
	if (countB != 0) {
		int count = 0;
		for (auto i : nums)
			if (i == candidateB)
				count++;
		if (count > nums.size() / 3)
			res.push_back(candidateB);
	}

	return res;
}

#endif /* LEETCODE_SOURCE_229_MAJORITYELEMENTII_H_ */
