#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int &number = nums[i];
            while (number > 0 && number <= n && nums[number-1] != number)
                swap(number, nums[number-1]);
        }

        for (int i = 0; i < n; i++)
            cout << nums[i] << " ";
        cout << endl;

        for (int i = 0; i < n; i++)
            if (nums[i] != i + 1)
                return i + 1;

        return n + 1;
    }
};

int main(void)
{
    int num;
    vector<int> nums;
    while (cin >> num)
        nums.push_back(num);

    Solution slt;
    int res = slt.firstMissingPositive(nums);
    cout << res << endl;

    return 0;
}
