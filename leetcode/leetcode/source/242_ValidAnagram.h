/*
 * 242_ValidAnagram.h
 *
 *  Created on: Aug 7, 2016
 *      Author: hao
 */

#ifndef LEETCODE_SOURCE_242_VALIDANAGRAM_H_
#define LEETCODE_SOURCE_242_VALIDANAGRAM_H_

/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/

#include "common.h"

bool isAnagram(string s, string t) {
    map<char, int> c_s, c_t;

    if (s.length() != t.length())
        return false;

    for (int i = 0; i < s.length(); i++) {
        if (c_s.count(s[i]))
            c_s[s[i]]++;
        else
            c_s[s[i]] = 1;

        if (c_t.count(t[i]))
            c_t[t[i]]++;
        else
            c_t[t[i]] = 1;
    }

    for (map<char, int>::iterator i = c_s.begin(), e = c_s.end(); i != e; i++) {
        if (c_t.count(i->first) && c_t[i->first] == i->second)
            continue;
        return false;
    }

    return true;
}

#endif /* LEETCODE_SOURCE_242_VALIDANAGRAM_H_ */
