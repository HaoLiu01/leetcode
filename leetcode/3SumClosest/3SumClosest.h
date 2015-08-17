/*
 * 3SumClosest.h
 *
 *  Created on: Aug 17, 2015
 *      Author: hao
 */

#ifndef LEETCODE_3SUMCLOSEST_H_
#define LEETCODE_3SUMCLOSEST_H_

#include <vector>
#include <algorithm>

/**********************************************************************************
*
* Given an array S of n integers, find three integers in S such that the sum is
* closest to a given number, target. Return the sum of the three integers.
* You may assume that each input would have exactly one solution.
*
*     For example, given array S = {-1 2 1 -4}, and target = 1.
*
*     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*
*
**********************************************************************************/

inline int abs(int x) {
	return x > 0 ? x : -x;
}

int threeSumClosest(std::vector<int> &nums, int target) {
    std::sort(nums.begin(), nums.end());
    int closest = nums[0] + nums[1] + nums[2];

    for (unsigned i = 0; i < nums.size(); i++) {
        for (unsigned j = nums.size() - 1; j > i + 1; j--) {
            int op0 = nums[i], op1 = nums[j];

            for (unsigned k = i + 1; k < j; k++) {
                int sum = nums[k] + op0 + op1;

                if (abs(sum - target) < abs(closest - target))
                	closest = sum;

                // no need to search following.
                if (sum > target)
                	break;
            }
        }
    }

    return closest;
}

#endif /* 3SUMCLOSEST_3SUMCLOSEST_H_ */
