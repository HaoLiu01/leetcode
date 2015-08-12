#include <vector>

using namespace std;

class Solution {
public:
  vector<int> TwoSum(vector<int> &numbers, int target) {
    vector<int> result;

    for (int i = 0; i < numbers.size(); i++) {
      for (int j = i + 1; j < numbers.size(); j++) {
        if (numbers[i] + numbers[j] == target) {
          result.push_back(i);
          result.push_back(j);
          return result;
        }
      }
    }

    return result;
  }
};
