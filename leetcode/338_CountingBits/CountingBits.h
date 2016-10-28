/*
 * CountingBits.h
 *
 *  Created on: Jun 2, 2016
 *      Author: hao
 */

#ifndef LEETCODE_338_COUNTINGBITS_COUNTINGBITS_H_
#define LEETCODE_338_COUNTINGBITS_COUNTINGBITS_H_


/*
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

0 0 0

1 1 1

2 1 10
3 2 11

4 1 100
5 2 101
6 2 110
7 3 111

8 1 1000
9 2 1001
a 2 1010
b 3 1011
c 2 1100
d 3 1101
e 3 1110
f 4 1111

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.*/

#include <common.h>

vector<int> countBits(int num)
{
    vector<int> ret;
    ret.push_back(0);
    int count = 1;
    int index = 0;

    for (int i = 1; i <= num; i++) {
        ret.push_back(ret[index] + 1);
        index++;
        if (index == count) {
            index = 0;
            count <<= 1;
        }
    }

    return ret;
}


#endif /* LEETCODE_338_COUNTINGBITS_COUNTINGBITS_H_ */
