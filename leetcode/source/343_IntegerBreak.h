/*
 * 343_IntegerBreak.h
 *
 *  Created on: 2016年10月30日
 *      Author: hao
 */

#ifndef LEETCODE_SOURCE_343_INTEGERBREAK_H_
#define LEETCODE_SOURCE_343_INTEGERBREAK_H_
/*
Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: You may assume that n is not less than 2 and not larger than 58.*/

/*
//錯誤解法，8的最大值是18，而不是16。
int maxProduct(int n) {
	if (n <= 4)
		return n;

	if (n % 2 == 0) {
		int tmp = maxProduct(n / 2);
		return tmp * tmp;
	} else {
		return maxProduct(n / 2) * maxProduct(n / 2 + 1);
	}
}

int integerBreak(int n) {
	if (n <= 3)
		return n - 1;
	return maxProduct(n);
}*/

/*
Hint:
There is a simple O(n) solution to this problem.
You may check the breaking results of n ranging from 7 to 10 to discover the regularities.
*/

// 儘量最大化3的個數
int deduct3AndProduct(int n) {
	if (n <= 4)
		return n;
	return 3 * deduct3AndProduct(n - 3);
}

int integerBreak(int n) {
	if (n <= 3)
		return n - 1;

	return deduct3AndProduct(n);
}

#endif /* LEETCODE_SOURCE_343_INTEGERBREAK_H_ */
