//
// Created by hao on 02/11/16.
//

#ifndef LEETCODE_387_FIRSTUNIQUECHAR_H
#define LEETCODE_387_FIRSTUNIQUECHAR_H

#include "common.h"

int firstUniqChar(string s) {
    set<char> nonUniq;
    int size = s.size();

    for (int i = 0; i < size; i++) {
        if (nonUniq.count(s[i]))
            continue;

        int j = i + 1;
        for (; j < size; j++) {
            if (s[i] == s[j]) {
                nonUniq.insert(s[i]);
                break;
            }
        }

        if (j == size)
        	return i;
    }

    return -1;
}

/*
Solutions online
*/

int firstUniqChar2(string s) {
	int table[26] = { 0 };
	for (auto c : s)
		table[c - 'a']++;
	for (int i = 0; i < s.length(); i++)
		if (table[s[i] - 'a'] == 1)
			return i;
	return -1;
}

#endif //LEETCODE_387_FIRSTUNIQUECHAR_H
