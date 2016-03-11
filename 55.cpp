#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> flags(n, false);
        int m = 0;
        int i = 0;
        for (; i <= m && i < n && m < n - 1; i++)
            m = max(m, i + nums[i]);

        return m >= n - 1;
    }
};

int main(void)
{
    Solution slt;

    int num;
    vector<int> nums;
    while (cin >> num)
        nums.push_back(num);
    cout << slt.canJump(nums) << endl;
    
    return 0;
}
