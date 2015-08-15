#include <iostream>
#include <assert.h>

#include "TwoSum/TwoSum.h"
#include "3sum/3sum.h"
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
    const int threeSumA[] = { -1, 0, 1, 2, -1, -4 };
    vector<int> threeSumV(threeSumA, threeSumA + 6);
    vector<vector<int> > res1 = threeSum(threeSumV);
    util::title("Test 3um:");
    util::output(res1);

    return 0;
}
