/*
 * 122_BestTimeToBuyAndSellStock.h
 *
 *  Created on: Jul 24, 2016
 *      Author: hao
 */

#ifndef LEETCODE_SOURCE_122_BESTTIMETOBUYANDSELLSTOCK_H_
#define LEETCODE_SOURCE_122_BESTTIMETOBUYANDSELLSTOCK_H_

/*
Say you have an array for which the ith element is the price of a given stock
on day i.

Design an algorithm to find the maximum profit. You may complete as many
transactions as you like (ie, buy one and sell one share of the stock multiple
times). However, you may not engage in multiple transactions at the same time
(ie, you must sell the stock before you buy again).*/

#include "common.h"

// 动态规划
//
//        0      if n = 0
// f(n) = max{ Pn - Pn-1 + f(n-2), Pn - Pn-2 + f(n-3), ... }

// Time Limit Exceeded
// Last executed input: more than 80,000 elements.
int maxProfit(vector<int>& prices) {
    if (prices.size() < 2)
        return 0;

    vector<int> maxArray(prices.size(), 0);
    for (int i = 1; i < prices.size(); i++) {
        maxArray[i] = maxArray[i - 1];
        for (int j = i - 1; j >= 0; j--) {
            int choise = prices[i] - prices[j];
            if (j - 1 >= 0)
                choise += maxArray[j - 1];
            maxArray[i] = std::max(maxArray[i], choise);
        }
    }

    return maxArray[prices.size() - 1];
}

#endif /* LEETCODE_SOURCE_122_BESTTIMETOBUYANDSELLSTOCK_H_ */
