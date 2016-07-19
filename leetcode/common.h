/*
 common.h
 *
  Created on: Jun 1, 2016
      Author: hao
 */

#ifndef LEETCODE_COMMON_H_
#define LEETCODE_COMMON_H_

#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

namespace util
{
void title(const char *s)
{
    std::cout << s << std::endl;
}

void output(vector<int> &vec)
{
    for (auto element : vec)
        std::cout << element << " ";
    std::cout << std::endl;
}

void output(vector<vector<int> > &input)
{
    for (vector<int> vec : input)
        output(vec);
}

void output(vector<string> vec)
{
    for (auto element : vec)
        std::cout << element << " ";
    std::cout << std::endl;
}
}

#endif /* LEETCODE_COMMON_H_ */
