#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        int start = 0, end = size - 1;
        int max_left_height = 0, max_right_height = 0;
        int total = 0;

        while (start <= end)
        {
            if (height[start] <= height[end])
            {
                if (height[start] <= max_left_height)
                    total += max_left_height - height[start];
                else
                    max_left_height = height[start];
                start++;
            }
            else
            {
                if (height[end] <= max_right_height)
                    total += max_right_height - height[end];
                else
                    max_right_height = height[end];
                end--;
            }
        }
        
        return total;
    }
};

int main(void)
{
    int num;
    vector<int> nums;
    while (cin >> num)
        nums.push_back(num);

    Solution slt;
    int res = slt.trap(nums);
    cout << res << endl;

    return 0;
}
