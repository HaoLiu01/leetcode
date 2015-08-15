// Source : https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// Author : Hao Chen
// Date   : 2015-07-03

/**********************************************************************************
 *
 * Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
 *
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
 *
 * Follow up:
 * What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently?
 * How would you optimize the kthSmallest routine?
 *
 *   Try to utilize the property of a BST.
 *   What if you could modify the BST node's structure?
 *   The optimal runtime complexity is O(height of BST).
 *
 * Credits:Special thanks to @ts for adding this problem and creating all test cases.
 **********************************************************************************/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

// This is accepted.
// But not efficient.
class Solution_ng {
public:
    int count(TreeNode* node) {
        if (!node)
            return 0;
        return count(node->left) + count(node->right) + 1;
    }

    int kthSmallest(TreeNode* root, int k) {
        int num = count(root->left);

        // The smallest one;
        if (num == k - 1) {
            return root->val;
        }

        if (num < k - 1) {
            return kthSmallest(root->right, k - num - 1);
        }

        return kthSmallest(root->left, k);
    }
};

class Solution {
public:
    // Count down k from the smallest element.
    // When K == 0, we get the kth.
    int countDown(TreeNode* node, int &k) {
        if (!node)
            return 0;

        // Visit left nodes first
        int result = countDown(node->left, k);
        if (k == 0)
            return result;

        if (--k == 0)
            return node->val;

        return countDown(node->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        return countDown(root, k);
    }
};
