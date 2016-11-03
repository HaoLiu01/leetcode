/*
 * 412_FizzBuzz.h
 *
 *  Created on: 2016年11月2日
 *      Author: hao
 */

#ifndef LEETCODE_SOURCE_412_FIZZBUZZ_H_
#define LEETCODE_SOURCE_412_FIZZBUZZ_H_

/*Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.*/
#include "common.h"

vector<string> fizzBuzz(int n) {
	vector<string> res;
	for (int i = 1; i <= n; i++) {
		if (i % 3 == 0) {
			if (i % 5 == 0)
				res.push_back("FizzBuzz");
			else
				res.push_back("Fizz");
			continue;
		}
		if (i % 5 == 0) {
			if (i % 3 == 0)
				res.push_back("FizzBuzz");
			else
				res.push_back("Buzz");
			continue;
		}

		stringstream ss;
		ss<<i;
		res.push_back(ss.str());
	}
	return res;
}

/*
 * similar solution
 *
vector<string> fizzBuzz(int n) {
	vector<string> result;
	for(int i = 1; i <= n; i++) {
		string elem = "";
		if(!(i % 3)) elem += "Fizz";
		if(!(i % 5)) elem += "Buzz";
		if(elem == "") elem += to_string(i);
		result.push_back(elem);
	}
	return result;
}*/
#endif /* LEETCODE_SOURCE_412_FIZZBUZZ_H_ */
