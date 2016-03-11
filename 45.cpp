#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        
        vector<int> times(size, 0);
        for (int i = 0; i < size - 1; i++)
            for (int j = min(nums[i], size - 1 - i); j > 0; j--)
            {
                if (times[i+j] == 0 || times[i+j] > times[i] + 1)
                    times[i+j] = times[i] + 1;
                else
                    break;
            }
        
        return times.back();
    }
};

int main(void)
{
    Solution slt;

    int num;
    vector<int> nums;
    while (cin >> num)
        nums.push_back(num);
    cout << slt.jump(nums) << endl;
    
    return 0;
}
