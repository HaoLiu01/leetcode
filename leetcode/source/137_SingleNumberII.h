/*
 * 137_SingleNumberII.h
 *
 *  Created on: Jun 20, 2016
 *      Author: hao
 */

#ifndef LEETCODE_SOURCE_137_SINGLENUMBERII_H_
#define LEETCODE_SOURCE_137_SINGLENUMBERII_H_
/*
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?*/

#include "common.h"
/*
用ones记录到当前计算的变量为止，二进制1出现“1次”（mod 3 之后的 1）的数位。用twos记录到当前计
算的变量为止，二进制1出现“2次”（mod 3 之后的 2）的数位。当ones和twos中的某一位同时为1时表示
二进制1出现3次，此时需要清零。即用二进制模拟三进制计算。最终ones记录的是最终结果。*/

int singleNumber(vector<int>& nums) {
    int ones = 0, twos = 0, xthrees = 0;
    for (unsigned i = 0; i < nums.size(); i++) {
        twos |= (ones & nums[i]);
        ones ^= nums[i];
        xthrees = ~(ones & twos);
        ones &= xthrees;
        twos &= xthrees;
    }

    return ones;
}

#endif /* LEETCODE_SOURCE_137_SINGLENUMBERII_H_ */
