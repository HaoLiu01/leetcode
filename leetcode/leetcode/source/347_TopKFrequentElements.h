/*
 * 347_TopKFrequentElements.h
 *
 *  Created on: Aug 7, 2016
 *      Author: hao
 */

#ifndef LEETCODE_SOURCE_347_TOPKFREQUENTELEMENTS_H_
#define LEETCODE_SOURCE_347_TOPKFREQUENTELEMENTS_H_

/*
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

#include "common.h"

static bool cmp_by_value(const pair<int,int>& lhs, const pair<int,int>& rhs) {
  return lhs.second > rhs.second;
}

// Map and sort
vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> count;
    for (int i = 0; i < nums.size(); i++) {
        if (count.count(nums[i]))
            count[nums[i]] = count[i] + 1;
        else
            count[nums[i]] = 1;
    }
//    unordered_map<int, int> count;
//    for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
//        ++count[*it];

    vector<pair<int, int> > name_score_vec(count.begin(), count.end());
    sort(name_score_vec.begin(), name_score_vec.end(), cmp_by_value);

//    multimap<int,int,greater<int>> VecSort;
//    for( unordered_map<int, int>::iterator  it=count.begin();it!=count.end();++it)
//    {
//         VecSort.insert(pair<int, int>((it->second), it->first));
//    }

    vector<int> result(k, 0);
    for (int i = 0; i < k; ++i) {
        result[i] = name_score_vec[i].first;
    }
    return result;
}

// Other solution: 用小根堆取代大根堆，在堆元素超过K时，删除堆顶元素，因为它不可能是数量最多的K个元素之一
//typedef pair<int, int> data;
//
//vector<int> topKFrequent(vector<int>& nums, int k) {
//    unordered_map<int, int> hash;
//    priority_queue<data, vector<data>, greater<data>> heap;
//    vector<int> ret;
//
//    for(int num:nums)
//​    ​    ​hash[num]++;
//
//    for(auto it:hash) {
//        heap.push(make_pair(it.second, it.first));
//        if(heap.size() > k) heap.pop();
//    }
//
//    while(!heap.empty()) {
//        ret.push_back(heap.top().second);
//        heap.pop();
//    }
//
//    return ret;
//}

// 桶排序
//vector<int> topKFrequent(vector<int>& nums, int k) {
//    unordered_map<int, int> hash;
//    vector<vector<int>> buckets(nums.size() + 1);
//    vector<int> ret;
//
//    for (int num : nums)
//        ​ ​ ​hash[num]++;
//
//    for (auto it : hash)
//        ​ ​ ​buckets[it.second].push_back(it.first);
//
//    for (int i = buckets.size() - 1; i > 0; --i) {
//        for (auto num : buckets[i]) {
//            ret.push_back(num);
//            if (ret.size() == k)
//                return ret;
//        }
//    }
//
//    return ret;
//}

#endif /* LEETCODE_SOURCE_347_TOPKFREQUENTELEMENTS_H_ */
