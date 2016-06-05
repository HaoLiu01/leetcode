/*
 * 283_MoveZeroes.h
 *
 *  Created on: Jun 5, 2016
 *      Author: haoliu01
 */

#ifndef LEETCODE_SOURCE_283_MOVEZEROES_H_
#define LEETCODE_SOURCE_283_MOVEZEROES_H_

/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:

    You must do this in-place without making a copy of the array.
    Minimize the total number of operations.
*/

#include "common.h"

void moveZeroes(vector<int>& nums) {
  unsigned count = 0;
  for (vector<int>::const_iterator i = nums.begin(), e = nums.end(); i != e; )
  {
    if (*i) {
      i++;
      continue;
    }

    i = nums.erase(i);
    count++;
  }

  while(count-- > 0)
    nums.push_back(0);
}

#endif /* LEETCODE_SOURCE_283_MOVEZEROES_H_ */
