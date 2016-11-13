/*
 * 229_MajorityElementII_unittest.cpp
 *
 *  Created on: 2016年11月13日
 *      Author: hao
 */

#include "source/229_MajorityElementII.h"

#include "gtest/gtest.h"
#include "common.h"

TEST(test_229, MajorityElementII) {
	{
		int input[] = { 6, 5, 5 };
		vector<int> nums(input, input + 3);
		vector<int> res = majorityElementII(nums);
		EXPECT_EQ(1u, res.size());
		EXPECT_EQ(5u, res[0]);
	}

	{
		int input[] = { 6, 5, 5, 6, 7, 7, 5 };
		vector<int> nums(input, input + 7);
		vector<int> res = majorityElementII(nums);
		EXPECT_EQ(1u, res.size());
		EXPECT_EQ(5u, res[0]);
	}

	{
		int input[] = { 6, 5, 5, 6, 7, 7, 8, 8, 9 };
		vector<int> nums(input, input + 9);
		vector<int> res = majorityElementII(nums);
		EXPECT_TRUE(res.empty());
	}
}
