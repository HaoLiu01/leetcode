/*
 * 226_InvertBinaryTree.h
 *
 *  Created on: Jun 4, 2016
 *      Author: hao
 */

#ifndef LEETCODE_SOURCE_226_INVERTBINARYTREE_H_
#define LEETCODE_SOURCE_226_INVERTBINARYTREE_H_

/*
invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1
*/

#include "common.h"

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return NULL;

        TreeNode* tmp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmp);

        return root;
    }
};

#endif /* LEETCODE_SOURCE_226_INVERTBINARYTREE_H_ */
