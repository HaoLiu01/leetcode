/*
 * 258_AddDigits.h
 *
 *  Created on: Jun 2, 2016
 *      Author: hao
 */

#ifndef LEETCODE_SOURCE_258_ADDDIGITS_H_
#define LEETCODE_SOURCE_258_ADDDIGITS_H_


/*Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?*/

/*
11 = 2
111 = 3
1385 = 17 = 8

(11 - 1) mod 9 + 1 = 2
(1385 - 1) mode 9 + 1 = 8

Digital Root:
dr(n) = 1 + ((n - 1) mod 9)
*/

int addDigits(int num) {
//    if (num == 0)
//        return 0;

    return (num - 1)%9 + 1;
}

#endif /* LEETCODE_SOURCE_258_ADDDIGITS_H_ */
