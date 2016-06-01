/*
 * ReverseString.h
 *
 *  Created on: Jun 1, 2016
 *      Author: hao
 */

#ifndef LEETCODE_344_REVERSESTRING_REVERSESTRING_H_
#define LEETCODE_344_REVERSESTRING_REVERSESTRING_H_

#include "common.h"

//    Write a function that takes a string as input and returns the string reversed.
//
//    Example:
//    Given s = "hello", return "olleh".


string reverseString(string s) {

//    Wrong method:
//    if (s.empty())
//        return s;
//
//    string a;
//    const char *sptr = s.c_str();
//    char nptr[s.size()];
//    for (int i = s.size() - 1; i >= 0; i--)
//        nptr[i] = *sptr++;
//    return string(nptr);

    int i = 0, j = s.size() - 1;
    while(i < j)
    {
        swap(s[i], s[j]);
        i++;
        j--;
    }

    return s;
}

string reverseString2(string s) {
    if (s.empty())
        return s;

    const char *sptr = s.c_str();
    char nptr[s.size()];
    for (int i = s.size() - 1; i >= 0; i--)
        nptr[i] = *sptr++;
    s.assign(nptr, s.size());
    return s;
}

#endif /* LEETCODE_344_REVERSESTRING_REVERSESTRING_H_ */
