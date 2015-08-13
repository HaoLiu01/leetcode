// Source : https://oj.leetcode.com/problems/two-sum/
// Author : Hao Chen
// Date   : 2014-06-17

/**********************************************************************************
*
* Given an array of integers, find two numbers such that they add up to a specific target number.
*
* The function twoSum should return indices of the two numbers such that they add up to the target,
* where index1 must be less than index2. Please note that your returned answers (both index1 and index2)
* are not zero-based.
*
* You may assume that each input would have exactly one solution.
*
* Input: numbers={2, 7, 11, 15}, target=9
* Output: index1=1, index2=2
*
*
**********************************************************************************/

#include <vector>
#include <map>

using namespace std;

// Time Limit Exceeded
//class Solution {
//public:
//  vector<int> TwoSum(vector<int> &nums, int target) {
//    vector<int> result;
//
//    for (int i = 0; i < nums.size(); i++) {
//      for (int j = i + 1; j < nums.size(); j++) {
//        if (nums[i] + nums[j] == target) {
//          result.push_back(i);
//          result.push_back(j);
//          return result;
//        }
//      }
//    }
//
//    return result;
//  }
//};

// Use space to save time.
class Solution {
public:
  vector<int> TwoSum(vector<int> &nums, int target) {
    vector<int> result;
    map<int, int> cache;

    for (unsigned i = 0; i < nums.size(); i++) {
      int other = target - nums[i];

      // Find two indices.
      if (cache.count(other)) {
        result.push_back(cache[other]);
        result.push_back(i);
        return result;
      }

      // Ignore current index on duplication.
      if (cache.count(nums[i]))
        continue;

      // Record current index and value.
      cache[nums[i]] = i;
    }

    return result;
  }
};
