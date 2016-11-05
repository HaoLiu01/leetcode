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

// 不能处理两个[][]并排的情况
string decodeString(string s) {
	int firstLB = s.find('[');
	if (firstLB < 0)
		return s;

	int lastRB = s.rfind(']');

	int nextStart = firstLB + 2;
	while (isAlpha(s[nextStart]))
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

bool isDigital(char c) {
	return (c - '0' >= 0) && ('9' - c >= 0);
}

string stringByDigital(const string &str, int num) {
	string fullStr = str;
	while (--num)
		fullStr += str;
	return fullStr;
}

// parse a pattern like PATTERN = num['a-z'PATTERN]'a-z'
string parseStrPattern(const char *&pos) {
	string extStr;

	if (isDigital(*pos)) {
		// get number
		string numStr;
		do {
			numStr += *(pos++);
		} while (isDigital(*pos));
		int num = atoi(numStr.c_str());

		assert(*pos == '[');
		++pos;

		while (*pos != ']')
			extStr += parseStrPattern(pos);
		++pos;

		extStr = stringByDigital(extStr, num);
	}

	while (isAlpha(*pos)) {
		extStr += *pos;
		++pos;
	}

	return extStr;
}

string decodeString2(string s) {
	const char *pos = s.c_str();
	string res;
	while (*pos != 0)
		res += parseStrPattern(pos);
	return res;
}

// Another simple solution online
string decodeString3(string s) {
	auto found = s.find_last_of('[');
	if (found == string::npos) {
		return s;
	} else {
		auto iNum = found;
		while (isdigit(s[iNum - 1]))
			iNum--;
		int num = stoi(s.substr(iNum, found - iNum));
		auto foundEnd = s.find_first_of(']', found);
		string mid = s.substr(found + 1, foundEnd - found - 1);
		string midsum;
		while (num-- > 0)
			midsum += mid;
		return decodeString(s.substr(0, iNum) + midsum + s.substr(foundEnd + 1));
	}
}

#endif /* LEETCODE_SOURCE_394_DECODESTRING_H_ */
