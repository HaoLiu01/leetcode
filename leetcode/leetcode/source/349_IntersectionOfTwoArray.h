/*
 * IntersectionOfTwoArray.h
 *
 *  Created on: Jun 5, 2016
 *      Author: haoliu01
 */

#ifndef LEETCODE_SOURCE_349_INTERSECTIONOFTWOARRAY_H_
#define LEETCODE_SOURCE_349_INTERSECTIONOFTWOARRAY_H_

#include "common.h"

/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:

    Each element in the result must be unique.
    The result can be in any order.
*/

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
  set<int> s1, s2;
  for (int i = 0; i < nums1.size(); i++)
    s1.insert(nums1[i]);

  for (int i = 0; i < nums2.size(); i++)
    s2.insert(nums2[i]);

  vector<int> res;
  for (set<int>::const_iterator i = s1.begin(), e = s1.end(); i != e; i++)
    if (s2.count(*i))
      res.push_back(*i);

  return res;
}


#endif /* LEETCODE_SOURCE_349_INTERSECTIONOFTWOARRAY_H_ */
