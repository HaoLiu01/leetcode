/*
 * AddAndSearchWord.h
 *
 *  Created on: Sep 8, 2015
 *      Author: hao
 */

#ifndef LEETCODE_ADDANDSEARCHWORD_ADDANDSEARCHWORD_H_
#define LEETCODE_ADDANDSEARCHWORD_ADDANDSEARCHWORD_H_

/**********************************************************************************
 *
 * Design a data structure that supports the following two operations:
 *
 * void addWord(word)
 * bool search(word)
 *
 * search(word) can search a literal word or a regular expression string containing only letters `a-z` or `.`
 * A `.` means it can represent any one letter.
 *
 * For example:
 *
 *   addWord("bad")
 *   addWord("dad")
 *   addWord("mad")
 *   search("pad") -> false
 *   search("bad") -> true
 *   search(".ad") -> true
 *   search("b..") -> true
 *
 * Note:
 * You may assume that all words are consist of lowercase letters a-z.
 *
 * click to show hint.
 *
 * You should be familiar with how a Trie works. If not, please work on this problem: Implement Trie (Prefix Tree) first.
 *
 *
 **********************************************************************************/

#include <string.h>
#include <iostream>
#include <string>
using namespace std;

// Adds a word into the data structure.
void addWord(string word) {

}

// Returns if the word is in the data structure. A word could
// contain the dot character '.' to represent any one letter.
bool search(string word) {
    return false;
}

#endif /* LEETCODE_ADDANDSEARCHWORD_ADDANDSEARCHWORD_H_ */
