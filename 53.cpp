#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size, 0);
        int m = nums[0];

        // dp[i] means the max sum of sub array from some j(j<=) to i
        dp[0] = nums[0];
        for (int i = 1; i < size; i++)
        {
            dp[i] = dp[i-1] < 0 ? nums[i] : dp[i-1] + nums[i];
            m = max(m, dp[i]);
        }

        return m; 
    }
};

int main(void)
{
    Solution slt;

    int num;
    vector<int> nums;
    while (cin >> num)
        nums.push_back(num);
    cout << slt.maxSubArray(nums) << endl;
    
    return 0;
}
