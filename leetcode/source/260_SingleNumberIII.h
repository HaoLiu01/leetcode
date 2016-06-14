/*
 * 260_SingleNumberIII.h
 *
 *  Created on: Jun 14, 2016
 *      Author: hao
 */

#ifndef LEETCODE_SOURCE_260_SINGLENUMBERIII_H_
#define LEETCODE_SOURCE_260_SINGLENUMBERIII_H_

/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?*/

#include "common.h"

vector<int> singleNumber(vector<int>& nums) {
    int eor = 0;
    for (int i = 0; i < nums.size(); i++) {
        eor ^= nums[i];
    }
}

#endif /* LEETCODE_SOURCE_260_SINGLENUMBERIII_H_ */
