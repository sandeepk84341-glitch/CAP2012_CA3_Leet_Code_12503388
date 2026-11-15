// LeetCode 189 - Rotate Array
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = static_cast<int>(nums.size());
        if (n == 0) {
            return;
        }

        k %= n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
