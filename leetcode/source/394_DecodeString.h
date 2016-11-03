/*
 * 394_DecodeString.h
 *
 *  Created on: 2016年11月3日
 *      Author: hao
 */

#ifndef LEETCODE_SOURCE_394_DECODESTRING_H_
#define LEETCODE_SOURCE_394_DECODESTRING_H_

#include "common.h"

bool isAlpha(char c) {
	return (c - 'a' >= 0) && ('z' - c >= 0);
}

string decodeString(string s) {
	int firstLB = s.find('[');
	if (firstLB < 0)
		return s;

	int lastRB = s.rfind(']');

	int nextStart = firstLB + 2;
	while(isAlpha(s[nextStart]))
		nextStart++;

	int num = atoi(s.substr(0, firstLB).c_str());
	string str = s.substr(firstLB + 1, nextStart - firstLB - 1);
	str += decodeString(s.substr(nextStart, lastRB - nextStart));
	if (lastRB + 1 != s.size())
		str += s.substr(lastRB + 1, s.size() - lastRB - 1);

	string res = str;
	while (--num) {
		res += str;
	}

	return res;
}

#endif /* LEETCODE_SOURCE_394_DECODESTRING_H_ */
