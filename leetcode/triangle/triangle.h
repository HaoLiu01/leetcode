/*
 * triangle.h
 *
 *  Created on: Sep 7, 2015
 *      Author: hao
 */

#ifndef LEETCODE_TRIANGLE_TRIANGLE_H_
#define LEETCODE_TRIANGLE_TRIANGLE_H_

/**********************************************************************************
 *
 * Given a triangle, find the minimum path sum from top to bottom.
 * Each step you may move to adjacent numbers on the row below.
 *
 * For example, given the following triangle
 *
 * [
 *      [2],
 *     [3,4],
 *    [6,5,7],
 *   [4,1,8,3]
 * ]
 *
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 *
 * Note:
 * Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
 *
 *
 **********************************************************************************/

#include <vector>
using namespace std;

int minimumRow(vector<int> row)
{
    int min = row[0];
    for (unsigned i = 1; i < row.size(); i++)
        min = min > row[i] ? row[i] : min;
    return min;
}

int minimumTotal(vector<vector<int> > &triangle)
{
    int result = triangle[0][0];
    for (unsigned i = 1; i < triangle.size(); i++)
        result += minimumRow(triangle[i]);

    return result;
}

#endif /* LEETCODE_TRIANGLE_TRIANGLE_H_ */
