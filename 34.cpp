#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        int left_idx = 0;
        int right_idx = size - 1;
        int mid_idx;
        vector<int> range(2, -1);

        // Find start
        while (left_idx <= right_idx)
        {
            mid_idx = (left_idx + right_idx) / 2;
            if (nums[mid_idx] == target)
            {
                if (mid_idx == 0 || nums[mid_idx-1] < target)
                {
                    range[0] = mid_idx;
                    break;       
                }
                else
                    right_idx = mid_idx - 1;
            }
            else if (nums[mid_idx] < target)
                left_idx = mid_idx + 1;
            else
                right_idx = mid_idx - 1;
        }

        // Find end
        if (range[0] != -1)
        {
            left_idx = range[0] + 1;
            right_idx = size - 1;
            
            while (left_idx <= right_idx)
            {
                mid_idx = (left_idx + right_idx) / 2;
                if (nums[mid_idx] == target)
                {
                    if (mid_idx == size - 1 || nums[mid_idx+1] > target)
                    {
                        range[1] = mid_idx;
                        break;       
                    }
                    else
                        left_idx = mid_idx + 1;
                }
                else if (nums[mid_idx] < target)
                    left_idx = mid_idx + 1;
                else
                    right_idx = mid_idx - 1;
            }
        }

        if (range[1] == -1)
            range[1] = range[0];

        return range;
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
    vector<int> range = slt.searchRange(nums, target);
    for (int i = 0; i < range.size(); i++)
        cout << range[i] << " ";
    cout << endl;

    return 0;
}
