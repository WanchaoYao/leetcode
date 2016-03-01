#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        int left_idx = 0;
        int right_idx = size - 1;
        int mid_idx, idx = -1;
        
        while (left_idx <= right_idx)
        {
            mid_idx = (left_idx + right_idx) / 2;

            if (nums[mid_idx] == target)
                return mid_idx;
            else if (nums[mid_idx] < target)
            {
                if (mid_idx == size - 1 || nums[mid_idx+1] > target)
                    return  mid_idx + 1;
                else
                    left_idx = mid_idx + 1;
            }
            else
            {
                if (mid_idx == 0 || nums[mid_idx-1] < target)
                    return mid_idx;
                else
                    right_idx = mid_idx - 1;
            }
        }
    }
};

int main(void)
{
    int num, target;
    cin >> target;
    vector<int> nums;
    while (cin >> num)
        nums.push_back(num);

    Solution slt;
    int idx = slt.searchInsert(nums, target);
    cout << idx << endl;

    return 0;
}
