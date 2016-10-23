/*
 * 168_ExcelSheetColumnTitle.h
 *
 *  Created on: Aug 7, 2016
 *      Author: hao
 */

#ifndef LEETCODE_SOURCE_168_EXCELSHEETCOLUMNTITLE_H_
#define LEETCODE_SOURCE_168_EXCELSHEETCOLUMNTITLE_H_

/*

Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB
*/

#include "common.h"

string convertToTitle(int n) {
    string re = "";
    char head = 'A';
    do {
        n--;
        re = char (n % 26 + head) + re;
        n = n / 26;
    } while (n != 0);

    return re;
}


#endif /* LEETCODE_SOURCE_168_EXCELSHEETCOLUMNTITLE_H_ */
