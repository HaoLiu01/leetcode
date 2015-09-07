/*
 * 4Sum.h
 *
 *  Created on: Aug 17, 2015
 *      Author: hao
 */

#ifndef LEETCODE_4SUM_4SUM_H_
#define LEETCODE_4SUM_4SUM_H_

#include <vector>
#include <algorithm>

/**********************************************************************************
 *
 * Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
 * Find all unique quadruplets in the array which gives the sum of target.
 *
 * Note:
 *
 * Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
 * The solution set must not contain duplicate quadruplets.
 *
 *     For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
 *
 *     A solution set is:
 *     (-1,  0, 0, 1)
 *     (-2, -1, 1, 2)
 *     (-2,  0, 0, 2)
 *
 *
 **********************************************************************************/

// Time limited exceed
std::vector<std::vector<int> > fourSum(std::vector<int> &nums, int target)
{
    std::vector<std::vector<int> > result;
    std::sort(nums.begin(), nums.end());

    for (unsigned i = 0; i < nums.size(); i++)
    {
        int op0 = nums[i];
        for (unsigned j = nums.size() - 1; j > i; j--)
        {
            int op1 = nums[j];

            for (unsigned k = i + 1; k < j - 1; k++)
            {
                int op2 = nums[k];

                for (unsigned l = k + 1; l < j; l++)
                {
                    int sum = op0 + op1 + op2 + nums[l];
                    if (sum == target)
                    {
                        int tmp[] =
                        { op0, op2, nums[l], op1 };
                        result.push_back(vector<int>(tmp, tmp + 4));
                    }

                    if (sum > target)
                        break;
                }
            }
        }
    }

    return result;
}

#endif /* LEETCODE_4SUM_4SUM_H_ */
