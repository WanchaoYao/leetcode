#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int left_idx = 0;
        int right_idx = size - 1;
        int mid_idx;
        int left, mid, right;

        while (left_idx <= right_idx)
        {
            mid_idx = (left_idx + right_idx) / 2;
            left = nums[left_idx];
            right = nums[right_idx];
            mid = nums[mid_idx];

            if (target == mid)
                return mid_idx;

            if (left <= mid)
            {
                if (mid <= right)
                {
                    if (target > mid)
                        left_idx = mid_idx + 1;
                    else
                        right_idx = mid_idx - 1;
                }
                else
                {
                    if (target > mid)
                        left_idx = mid_idx + 1;
                    else
                    {
                        if (target <= right)
                            left_idx = mid_idx + 1;
                        else
                            right_idx = mid_idx - 1;
                    }
                }
            }
            else
            {
                if (target > mid)
                {
                    if (target <= right)
                        left_idx = mid_idx + 1;
                    else
                        right_idx = mid_idx - 1;
                }
                else
                    right_idx = mid_idx - 1;
            }
        }

        return -1; 
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
    int idx = slt.search(nums, target);
    cout << idx << endl;

    return 0;
}
