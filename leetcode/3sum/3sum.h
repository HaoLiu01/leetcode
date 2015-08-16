/*
 * 3sum.h
 *
 *  Created on: Aug 15, 2015 9:04:24 AM
 *      Author: Hao Liu
 *      E-mail: haoliu233@163.com
 */

#ifndef LEETCODE_3SUM_3SUM_H_
#define LEETCODE_3SUM_3SUM_H_

#include <vector>
#include <algorithm>

/**********************************************************************************
 *
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
 * Find all unique triplets in the array which gives the sum of zero.
 *
 * Note:
 *
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 * The solution set must not contain duplicate triplets.
 *
 *     For example, given array S = {-1 0 1 2 -1 -4},
 *
 *     A solution set is:
 *     (-1, 0, 1)
 *     (-1, -1, 2)
 *
 *
 **********************************************************************************/

using namespace std;

bool compare(int i, int j) {
    return i < j;
}

vector<vector<int> > threeSum(vector<int>& nums) {
    vector<vector<int> > result;

    sort(nums.begin(), nums.end());

    for (unsigned i = 0; i < nums.size(); i++) {
        for (unsigned j = nums.size() - 1; j > i + 1; j--) {
            int op0 = nums[i];
            if (op0 > 0)
                break;

            int op1 = nums[j];
            if (op1 < 0)
                break;

            for (unsigned k = i + 1; k < j; k++) {
                int sum = nums[k] + op0 + op1;
                if (sum == 0) {
                    int tmp[] = { op0, nums[k], op1 };
                    result.push_back(vector<int>(tmp, tmp + 3));
                }
                // no need to search follwing.
                if (sum > 0)
                    break;
            }
        }
    }

    return result;
}

#endif /* LEETCODE_3SUM_3SUM_H_ */
