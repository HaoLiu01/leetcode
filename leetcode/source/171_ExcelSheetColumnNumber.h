/*
 * 171_ExcelSheetColumnNumber.h
 *
 *  Created on: Aug 7, 2016
 *      Author: hao
 */

#ifndef LEETCODE_SOURCE_171_EXCELSHEETCOLUMNNUMBER_H_
#define LEETCODE_SOURCE_171_EXCELSHEETCOLUMNNUMBER_H_

/*
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28
*/

#include "common.h"

int titleToNumber(string s) {
    int num = s.length();
    int res = 0;
    for (int i = 0; i < num; i++)
        res = res * 26 + char (s[i] - 'A') + 1;

    return res;
}


#endif /* LEETCODE_SOURCE_171_EXCELSHEETCOLUMNNUMBER_H_ */
