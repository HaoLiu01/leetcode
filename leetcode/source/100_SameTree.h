/*
 * 100_SameTree.h
 *
 *  Created on: Jul 24, 2016
 *      Author: hao
 */

#ifndef LEETCODE_SOURCE_100_SAMETREE_H_
#define LEETCODE_SOURCE_100_SAMETREE_H_

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include "common.h"

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p) {
        if (!q)
            return true;
        else
            return false;
    }

    if (!q) {
        return false;
    }

    if (!isSameTree(p->left, q->left) || !isSameTree(p->right, q->right))
        return false;

    if (p->val == q->val)
        return true;
    return false;
}

#endif /* LEETCODE_SOURCE_100_SAMETREE_H_ */
