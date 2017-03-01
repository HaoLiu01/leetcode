

/*

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.*/

#include <bitset>
using std::bitset;

int hammingDistance(int x, int y) {
	return bitset<32>(x^y).count();
}
