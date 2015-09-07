/*
 * MedianOfTwoSortedArrays.h
 *
 *  Created on: Aug 17, 2015
 *      Author: hao
 */

#ifndef LEETCODE_MEDIANOFTWOSORTEDARRAYS_MEDIANOFTWOSORTEDARRAYS_H_
#define LEETCODE_MEDIANOFTWOSORTEDARRAYS_MEDIANOFTWOSORTEDARRAYS_H_

#include <vector>

/**********************************************************************************
 *
 * There are two sorted arrays A and B of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 *
 **********************************************************************************/

int MedianOfTwoSortedArrays(std::vector<int> &A, std::vector<int> &B)
{
    std::vector<int> C;
    unsigned m = A.size(), n = B.size();
    unsigned i = 0, j = 0;

    for (; i < m && j < n;)
    {
        if (A[i] <= B[j])
        {
            C.push_back(A[i]);
            i++;
        }
        else
        {
            C.push_back(B[j]);
            j++;
        }
    }

    unsigned mid = (m + n) / 2;
    if (mid <= C.size())
        return C[mid];
    else if (i == m)
        return B[mid - C.size()];
    else
        return A[mid - C.size()];
}

#endif /* LEETCODE_MEDIANOFTWOSORTEDARRAYS_MEDIANOFTWOSORTEDARRAYS_H_ */
