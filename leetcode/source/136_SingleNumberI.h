/*
 * 136_SingleNumberI.h
 *
 *  Created on: Jun 14, 2016
 *      Author: hao
 */

#ifndef LEETCODE_SOURCE_136_SINGLENUMBERI_H_
#define LEETCODE_SOURCE_136_SINGLENUMBERI_H_
/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?*/

#include "common.h"

int singleNumber(vector<int>& nums) {
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
        res ^= nums[i];
    }

    return res;
}


#endif /* LEETCODE_SOURCE_136_SINGLENUMBERI_H_ */
