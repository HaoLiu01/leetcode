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
//    int eor = 0;
//    for (int i = 0; i < nums.size(); i++) {
//        eor ^= nums[i];
//    }

/*
    首先计算nums数组中所有数字的异或，记为xor
    令lowbit = xor & -xor，lowbit的含义为xor从低位向高位，第一个非0位所对应的数字
    例如假设xor = 6（二进制：0110），则-xor为（二进制：1010，-6的补码，two's complement）
    则lowbit = 2（二进制：0010）
    根据异或运算的性质，“同0异1”
    记只出现一次的两个数字分别为a与b
    可知a & lowbit与b & lowbit的结果一定不同
    通过这种方式，即可将a与b拆分开来*/

    int eor = 0;
    for (int i = 0; i < nums.size(); i++) {
        eor ^= nums[i];
    }

    int lowbit = eor & (~(eor - 1));
    int A = 0, B = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (lowbit & nums[i])
            A ^= nums[i];
        else
            B ^= nums[i];
    }

    return vector<int>( { A, B });
}

#endif /* LEETCODE_SOURCE_260_SINGLENUMBERIII_H_ */
