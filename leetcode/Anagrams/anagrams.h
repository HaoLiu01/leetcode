/*
 * anagrams.h
 *
 *  Created on: Oct 3, 2015
 *      Author: hao
 */

#ifndef LEETCODE_ANAGRAMS_ANAGRAMS_H_
#define LEETCODE_ANAGRAMS_ANAGRAMS_H_


/**********************************************************************************
*
* Given an array of strings, return all groups of strings that are anagrams.
*
* Note: All inputs will be in lower-case.
*
* For example:
* Input:　　["tea","and","ate","eat","den"]
* Output:   ["tea","ate","eat"]
*
**********************************************************************************/

#include <map>
#include <vector>
#include <string>

using namespace std;

vector<string> anagrams(vector<string> &strs)
{
    vector<string> result;
    map<string, int> cache;
    for (int i = 0; i < strs.size(); i++)
    {
        string word = strs[i];
        sort(word.begin(), word.end());
        if (cache.find(word) == cache.end())
        {
            cache[word] = i;
        }
        else
        {
            if (cache[word] >= 0)
            {
                result.push_back(strs[cache[word]]);
                cache[word] = -1;
            }
            result.push_back(strs[i]);
        }
    }

    return result;
}


#endif /* LEETCODE_ANAGRAMS_ANAGRAMS_H_ */
