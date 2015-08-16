#include <iostream>
#include <assert.h>

#include "TwoSum/TwoSum.h"
#include "3sum/3sum.h"
#include "KthLargestElementInAnArray/KthLargestElementInAnArray.h"
#include "utils.h"

using namespace std;

int main() {

    // Test TwoSum
    int myints[] = { 2, 7, 11, 15 };
    vector<int> nums(myints, myints + 4);
    vector<int> res0 = TwoSum(nums, 9);
    util::title("Test TwoSum:");
    util::output(res0);

    // Test 3sum
    const int threeSumA[] = { -1, 4, 8, 9, 0, 1, 2, -1, -4, -5, -3, -2, -7 };
    vector<int> threeSumV(threeSumA, threeSumA + sizeof(threeSumA) / sizeof(int));
    vector<vector<int> > res1 = threeSum(threeSumV);
    util::title("Test 3um:");
    util::output(res1);

    // Test KthLargest Array
    int res2 = findKthLargest(threeSumV, 3);
    cout << "Test Kth Largest:" << endl;
    cout << res2 << endl;

    return 0;
}
