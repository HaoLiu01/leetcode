//
// Created by hao on 01/11/16.
//

#ifndef LEETCODE_384_SHUFFLEANARRAY_H
#define LEETCODE_384_SHUFFLEANARRAY_H

#include "common.h"
#include <cstdlib>

class Solution {
public:
    Solution(vector<int> nums) {
        orig = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return orig;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res = orig;
        int len = res.size();

        for (int i = 0; i < len; i++) {
            int t = rand() % len;
            swap(res[i], res[t]);
        }

        return  res;
    }

private:
    vector<int> orig;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */

#endif //LEETCODE_384_SHUFFLEANARRAY_H
