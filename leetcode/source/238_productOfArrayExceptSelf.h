/*
 * 238_productOfArrayExceptSelf.h
 *
 *  Created on: Jul 19, 2016
 *      Author: hao
 */

#ifndef LEETCODE_SOURCE_238_PRODUCTOFARRAYEXCEPTSELF_H_
#define LEETCODE_SOURCE_238_PRODUCTOFARRAYEXCEPTSELF_H_

/*
Given an array of n integers where n > 1, nums, return an array output such that
output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does
not count as extra space for the purpose of space complexity analysis.)*/

#include "common.h"

// With division
vector<int> productExceptSelf(vector<int>& nums) {
    int totalProduct = nums[0];
    int countZero = 0;
    for (int i = 1; i < nums.size(); i++) {
        totalProduct *= nums[i];
        if (nums[i] == 0) {
            countZero ++;
            if (countZero > 1)
                break;
        }
    }

    vector<int> res;

    if (countZero > 1) {
        for (int i = 0; i < nums.size(); i++)
            res.push_back(0);
    } else {
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != 0) {
                res.push_back(totalProduct / nums[i]);
            } else {
                int newTotal = 1;
                for (int j = 0; j < nums.size(); j++) {
                    if (i != j)
                        newTotal *= nums[j];
                }
                res.push_back(newTotal);
            }
    }

    return res;
}

#endif /* LEETCODE_SOURCE_238_PRODUCTOFARRAYEXCEPTSELF_H_ */
