/*
 * 169_MajorityElement.h
 *
 *  Created on: 2016年11月6日
 *      Author: hao
 */

#ifndef LEETCODE_SOURCE_169_MAJORITYELEMENT_H_
#define LEETCODE_SOURCE_169_MAJORITYELEMENT_H_

#include "common.h"

// My primary solution
int majorityElement(vector<int>& nums) {
	vector<int> less;
	vector<int> equal;
	vector<int> great;

	auto i = nums.begin();
	int target = *i;
	equal.push_back(target);
	while (++i != nums.end())
		if (*i < target)
			less.push_back(*i);
		else if (*i == target)
			equal.push_back(*i);
		else
			great.push_back(*i);

	int half = nums.size() / 2;
	if (equal.size() > half)
		return target;
	else if (less.size() > half)
		return majorityElement(less);
	else
		return majorityElement(great);
}

// A better solution online
/*

Find k different element, and "remove" them as a group, the remaining element must be the element that appears more than ⌊n/k⌋ times. (Detailed explanation is given in comment)

In this problem, k equals to 2.

Thus we "remove" each pair of 2 different elements, and the remaining element that do not have its counterpart is the desired element.
*/

int majorityElement2(vector<int> &num) {
	int nTimes = 0;
	int candidate = 0;
	for(int i = 0; i < num.size(); i ++)
	{
		if(nTimes == 0)
		{
			candidate = num[i];
			nTimes = 1;
		}
		else
		{
			if(candidate == num[i])
				nTimes ++;
			else
				nTimes --;
		}
	}
	return candidate;
}

#endif /* LEETCODE_SOURCE_169_MAJORITYELEMENT_H_ */
