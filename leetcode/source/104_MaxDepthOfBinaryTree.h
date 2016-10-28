/*
 * 104_MaxDepthOfBinaryTree.h
 *
 *  Created on: Jun 4, 2016
 *      Author: hao
 */

#ifndef LEETCODE_SOURCE_104_MAXDEPTHOFBINARYTREE_H_
#define LEETCODE_SOURCE_104_MAXDEPTHOFBINARYTREE_H_

/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Subscribe to see which companies asked this question*/

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

int maxDepth(TreeNode* root) {
    if (!root)
        return 0;
    return 1 + max(maxDepth(root->right), maxDepth(root->left));
}

#endif /* LEETCODE_SOURCE_104_MAXDEPTHOFBINARYTREE_H_ */
