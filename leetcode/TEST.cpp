#include <assert.h>
#include <TwoSum/TwoSumx.h>

int main() {
  Solution solution;

  // Test TwoSum
  vector<int> numbers;
  numbers.push_back(2);
  numbers.push_back(7);
  numbers.push_back(11);
  numbers.push_back(15);

  vector<int> result = solution.TwoSum(numbers, 9);
  assert(result[0] == 1 && result[1] == 2 && "Test TwoSum");

  return 0;
}
