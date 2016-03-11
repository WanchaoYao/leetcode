#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        int start = 0, end = size - 1;
        int total = 0;

        // Left to right
        for (int i = 1; i < size; i++)
        {
            if (height[i] > height[start])
            {
                if (i == start + 1)
                    start= i;
                else
                {
                    end = i;
                    // Caculate
                    int s = min(height[start], height[end]) * (end - start - 1);
                    cout << start << " " << end << " " << s << endl;
                    for (int j = start + 1; j < end; j++)
                        s -= height[j];
                    total += s;

                    start = end;
                }
            }
        }
        
        // Right to left
        start = size - 1, end = 0;
        for (int i = size - 2; i >= 0; i--)
        {
            if (height[i] >= height[start])
            {
                if (i == start - 1)
                    start= i;
                else
                {
                    end = i;
                    // Caculate
                    int s = min(height[start], height[end]) * (start - end - 1);
                    for (int j = start - 1; j > end; j--)
                        s -= height[j];
                    total += s;

                    start = end;
                }
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
