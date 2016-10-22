/*
 * 382_LinkedListRandomNode.h
 *
 *  Created on: Oct 17, 2016
 *      Author: hao
 */

#ifndef LEETCODE_SOURCE_382_LINKEDLISTRANDOMNODE_H_
#define LEETCODE_SOURCE_382_LINKEDLISTRANDOMNODE_H_

/*

Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

Follow up:
What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using extra space?

Example:

// Init a singly linked list [1,2,3].
ListNode head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
Solution solution = new Solution(head);

// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
solution.getRandom();
*/

#include "common.h"
#include <time.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution_short {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution_short(ListNode* head_) : head(head_), len(1) {
        ListNode* cur = head;
        while(cur = cur->next)
            len ++;
    }

    /** Returns a random node's value. */
    int getRandom() {
        srand((unsigned)time(NULL));

        // int t = rand() % len
        int target = rand() % len;
        ListNode* cur = head;
        while(target--)
            cur = cur->next;

        return cur->val;
    }

private:
    ListNode* head;
    int len;
};

/*
Follow up中说链表可能很长，我们没法提前知道长度，这里用到了著名了水塘抽样的思路，
由于限定了head一定存在，所以我们先让返回值res等于head的节点值，然后让cur指向head的
下一个节点，定义一个变量i，初始化为2，若cur不为空我们开始循环，我们在[0, i - 1]中取
一个随机数，如果取出来0，那么我们更新res为当前的cur的节点值，然后此时i自增一，cur指
向其下一个位置，这里其实相当于我们维护了一个大小为1的水塘，然后我们随机数生成为0的话，
我们交换水塘中的值和当前遍历到底值，这样可以保证每个数字的概率相等，参见代码如下：
*/

class Solution {
public:
    /** @param head The linked list's head. Note that the head is guanranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        int res = head->val, i = 2;
        ListNode *cur = head->next;
        while (cur) {
            int j = rand() % i;
            if (j == 0)
                res = cur->val;
            ++i;
            cur = cur->next;
        }
        return res;
    }
private:
    ListNode *head;
};
/*
水塘抽样
Dictionary of Algorithms and Data Structures[2]所载的O(n)算法，包含以下步骤（假设阵列S以0开始标示）：

從S中抽取首k項放入「水塘」中
對於每一個S[j]項（j ≥ k）：
   隨機產生一個範圍從0到j的整數r
   若 r < k 則把水塘中的第r項換成S[j]項*/

/*
int main() {
    int S[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    const int k = 4;
    int R[k];
    int i, j;
    for (i = 0; i < k; i++)
        R[i] = S[i];

    for (i = k; i < sizeof(S) / sizeof(S[0]); i++) {
        srand(time(NULL));
        j = rand() % i;
        if (j < k)
            R[j] = S[i];
    }

    for (int i = 0; i < k; i++)
        cout << R[i] << ends;
    cout << endl;
}
*/

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */

#endif /* LEETCODE_SOURCE_382_LINKEDLISTRANDOMNODE_H_ */
