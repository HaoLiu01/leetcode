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
//vector<int> productExceptSelf(vector<int>& nums) {
//    int totalProduct = nums[0];
//    int countZero = 0;
//    for (int i = 1; i < nums.size(); i++) {
//        totalProduct *= nums[i];
//        if (nums[i] == 0) {
//            countZero ++;
//            if (countZero > 1)
//                break;
//        }
//    }
//
//    vector<int> res;
//
//    if (countZero > 1) {
//        for (int i = 0; i < nums.size(); i++)
//            res.push_back(0);
//    } else {
//        for (int i = 0; i < nums.size(); i++)
//            if (nums[i] != 0) {
//                res.push_back(totalProduct / nums[i]);
//            } else {
//                int newTotal = 1;
//                for (int j = 0; j < nums.size(); j++) {
//                    if (i != j)
//                        newTotal *= nums[j];
//                }
//                res.push_back(newTotal);
//            }
//    }
//
//    return res;
//}

vector<int> productExceptSelf(vector<int>& nums) {
//    product of left elements * product of right elements
    int *left = new int[nums.size()];
    int *right = new int[nums.size()];
    int maxIdx = nums.size() - 1;

    left[0] = nums[0];
    for (int i = 1; i < maxIdx; i++)
        left[i] = nums[i] * left[i - 1];

    right[maxIdx] = nums[maxIdx];
    for (int i = maxIdx - 1; i > 0; i--)
        right[i] = nums[i] * right[i + 1];

    vector<int> res;
    res.push_back(right[1]);
    for (int i = 1; i < maxIdx; i++)
        res.push_back(left[i - 1] * right[i + 1]);

    res.push_back(left[maxIdx - 1]);

    delete left;
    delete right;
    return res;
}

// A better solution
vector<int> productExceptSelf2(vector<int>& nums) {
    int len = nums.size();
    vector<int> left(len,  1);  //当前元素左边的乘积
    vector<int> right(len, 1);  //当前元素右边的乘积
    vector<int> result;

    for(int i=1; i<len; i++){
        left[i] = left[i-1]*nums[i-1];
    }

    for(int i=len-2; i>=0; i--){
        right[i] = right[i+1]*nums[i+1];
    }

    for(int i=0; i<len; i++){
        result.push_back(left[i] * right[i]);
    }

    return result;
}

#endif /* LEETCODE_SOURCE_238_PRODUCTOFARRAYEXCEPTSELF_H_ */
