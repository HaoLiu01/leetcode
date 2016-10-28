/*
 * 237_DeleteNodeInALinkedList.h
 *
 *  Created on: Jul 19, 2016
 *      Author: hao
 */

#ifndef LEETCODE_SOURCE_237_DELETENODEINALINKEDLIST_H_
#define LEETCODE_SOURCE_237_DELETENODEINALINKEDLIST_H_

/*
Write a function to delete a node (except the tail) in a singly linked list,
given only access to that node. Supposed the linked list is 1 -> 2 -> 3 -> 4
and you are given the third node with value 3, the linked list should
become 1 -> 2 -> 4 after calling your function. Subscribe to see which
companies asked this question
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include "common.h"

void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}



#endif /* LEETCODE_SOURCE_237_DELETENODEINALINKEDLIST_H_ */
