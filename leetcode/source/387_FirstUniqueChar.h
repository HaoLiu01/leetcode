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

#endif //LEETCODE_387_FIRSTUNIQUECHAR_H
