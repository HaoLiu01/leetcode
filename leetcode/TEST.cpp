#include <iostream>
#include <assert.h>
#include <string>

#include "3Sum/3Sum.h"
#include "TwoSum/TwoSum.h"
#include "3SumClosest/3SumClosest.h"
#include "KthLargestElementInAnArray/KthLargestElementInAnArray.h"
#include "4Sum/4Sum.h"
#include "MedianOfTwoSortedArrays/MedianOfTwoSortedArrays.h"
#include "triangle/triangle.h"
#include "Anagrams/anagrams.h"
#include "344_ReverseString/ReverseString.h"
#include "338_CountingBits/CountingBits.h"
#include "source/258_AddDigits.h"
#include "source/349_IntersectionOfTwoArray.h"
#include "source/283_MoveZeroes.h"
#include "source/347_TopKFrequentElements.h"
#include "source/168_ExcelSheetColumnTitle.h"

#include "common.h"

using namespace std;

int main() {

  {
    // Test TwoSum
    int myints[] = { 2, 7, 11, 15 };
    vector<int> nums(myints, myints + 4);
    vector<int> res0 = TwoSum(nums, 9);
    util::title("Test TwoSum:");
    util::output(res0);

    // Test 3sum
    const int threeSumA[] = { -1, 4, 8, 9, 0, 1, 2, -1, -4, -5, -3, -2, -7 };
    vector<int> threeSumV(threeSumA,
        threeSumA + sizeof(threeSumA) / sizeof(int));
    vector<vector<int> > res1 = threeSum(threeSumV);
    util::title("Test 3um:");
    util::output(res1);

    // Test KthLargest Array
    int res2 = findKthLargest(threeSumV, 3);
    cout << "Test Kth Largest:" << endl;
    cout << res2 << endl;

    int res3 = threeSumClosest(threeSumV, 3);
    cout << "Test 3 Sum closest:" << endl;
    cout << res3 << endl;

    vector<vector<int> > res4 = fourSum(threeSumV, -16);
    cout << "Test 4 Sum:" << endl;
    util::output(res4);

    int A[] = { -1, 0, 4, 9 };
    int B[] = { -3 };
    vector<int> AA(A, A + 4);
    vector<int> BB(B, B + 1);
    cout << "Test median of two sorted arrays: \n  "
        << MedianOfTwoSortedArrays(AA, BB) << endl;
  }

  {
    // Test triangle
    vector<vector<int> > triangle_in;
    int row0[] = { 2 }, row1[] = { 3, 4 }, row2[] = { 6, 5, 7 }, row3[] = { 4,
        1, 8, 3 };
    vector<int> v0(row0, row0 + 1);
    vector<int> v1(row1, row1 + 2);
    vector<int> v2(row2, row2 + 3);
    vector<int> v3(row3, row3 + 4);
    triangle_in.push_back(v0);
    triangle_in.push_back(v1);
    triangle_in.push_back(v2);
    triangle_in.push_back(v3);
    cout << "The minimal total in triangle is:" << minimumTotal(triangle_in)
        << endl;
  }

  {
    // Test Anagrams
    string anaArray[] = { "tea", "and", "ate", "eat", "den" };
    vector<string> anaVec(anaArray, anaArray + 5);
    util::output(anagrams(anaVec));

    // Test ReserveString
    string a = reverseString("hello");
    cout << "The reverse string of \"hello\"  is " << a << endl;
    a = reverseString2("hello");
    cout << "The reverse string of \"hello\"  is " << a << endl;
  }

  {
    // Test CountingBits
    vector<int> vec = countBits(16);
    util::output(vec);
  }

  {
    cout << "addDigits(0) = " << addDigits(0) << endl;
    cout << "addDigits(1385) = " << addDigits(1385) << endl;
  }

  {
    int myints1[] = { 2, 7, 2, 15 };
    vector<int> nums1(myints1, myints1 + 4);
    int myints2[] = { 1, 2, 3, 5 };
    vector<int> nums2(myints2, myints2 + 4);
    vector<int> res = intersection(nums1, nums2);
    cout << "The result of insertsection is:";
    util::output(res);
  }

  {
    int myints[] = { 0, 1, 0, 3, 12, 0 };
    vector<int> nums(myints, myints + 6);
    moveZeroes(nums);
    cout << "The result of moveZeroes is:";
    util::output(nums);

    vector<int> nums1;
    nums1.push_back(0);
    moveZeroes(nums1);
    cout << "The result of moveZeroes is:";
    util::output(nums1);
  }

  {
      int input[] = {1,1,1,2,2,3};
      vector<int> nums(input, input + 6);
      vector<int> res = topKFrequent(nums, 2);
      util::output(res);
  }

  {
      cout << convertToTitle(1) << endl;
      cout << convertToTitle(27) << endl;
      cout << convertToTitle(54) << endl;
  }

  cout << endl;
  return 0;
}
