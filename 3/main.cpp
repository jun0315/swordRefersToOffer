#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int> &nums) {
        int exist[100001];
        for (int i = 0; i < nums.size(); i++) {
            if (exist[nums[i]] != 1) {
                exist[nums[i]] = 1;
            } else {
                return nums[i];
            }
        }
        return nums[0];
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0, 1, 2, 3, 4, 11, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    cout << solution.findRepeatNumber(nums);

}
