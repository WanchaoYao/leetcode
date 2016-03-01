#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        if (size < 1)
            return;

        int max = nums.back();

        int i = size - 2;
        for (; i >= 0; i--)
        {
            if (nums[i] < max)
            {
                int greater = max + 1;
                int idx = -1;
                for (int j = i + 1; j < size; j++)
                    if (nums[j] > nums[i] && nums[j] < greater)
                    {
                        greater = nums[j];
                        idx = j;
                    }

                nums[idx] = nums[i];
                nums[i] = greater;
                
                sort(nums.begin()+i+1, nums.end());
                
                break;
            }
            else
                max = nums[i];
        }

        if (i == -1)
            sort(nums.begin(), nums.end());
    }
};

int main(void)
{
    int num;
    vector<int> nums;
    while (cin >> num)
        nums.push_back(num);

    Solution slt;
    slt.nextPermutation(nums);
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;

    return 0;
}
