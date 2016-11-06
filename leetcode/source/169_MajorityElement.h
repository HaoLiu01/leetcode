/*
 * 169_MajorityElement.h
 *
 *  Created on: 2016年11月6日
 *      Author: hao
 */

#ifndef LEETCODE_SOURCE_169_MAJORITYELEMENT_H_
#define LEETCODE_SOURCE_169_MAJORITYELEMENT_H_

#include "common.h"

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
	if (equal.size() >= half)
		return target;
	else if (less.size() >= half)
		return majorityElement(less);
	else if (great.size() >= half)
		return majorityElement(great);
}

#endif /* LEETCODE_SOURCE_169_MAJORITYELEMENT_H_ */
