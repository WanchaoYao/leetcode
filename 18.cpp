#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<vector<int> > results;
        vector<int> result(4, 0);

        if (size < 4)
            return results;

        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < size - 3; i++)
        {
            // Omit duplicate numbers
            if (i > 0 && nums[i] == nums[i-1])
                continue;

            // nums[i] is too small to be the first number
            if (nums[i] + nums[size-3] + nums[size-2] + nums[size-1] < target)
                continue;

            for (int j = i + 1; j < size - 2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j-1])
                    continue;

                // nums[j] is too small to be the second number
                if (nums[i] + nums[j] + nums[size-2] + nums[size-1] < target)
                    continue;

                int last_idx = size - 1;
                while (last_idx > j + 1 && nums[i] + nums[j] + nums[j+1] + nums[last_idx] > target)
                    last_idx--;

                // All subsequent sets are increasing and not smaller than target
                if (last_idx == j + 1)
                    break;
                
                int n = last_idx;
                for (int m = j + 1; m < size - 1; m++)
                {
                    if (m > j + 1 && nums[m] == nums[m-1])
                        continue;

                    // n moves left from last_idx
                    while (n > m && nums[i] + nums[j] + nums[m] + nums[n] > target)
                        n--;

                    if (n > m)
                    {
                        int sum = nums[i] + nums[j] + nums[m] + nums[n];
                        if (sum == target)
                        {
                            result[0] = nums[i];
                            result[1] = nums[j];
                            result[2] = nums[m];
                            result[3] = nums[n];
                            results.push_back(result);
                        }
                    }
                    // All subsequent sets are increasing and not smaller than target
                    else
                        break;
                }
            }
        }

        return results;
    }
};

int main(void)
{
    Solution slt;

    //int arrays[] = {1, 0, -1, 0, -2, 2};
    //int target = 0;

    int arrays[] = {0, 0, 0, 0};
    int target = 0;

    vector<int> nums(arrays, arrays+sizeof(arrays)/sizeof(int));
    vector<vector<int> > results = slt.fourSum(nums, target);
    vector<int> result;
    for (int i = 0; i < results.size(); i++)
    {
        result = results[i];
        cout << result[0] << ", "
             << result[1] << ", " 
             << result[2] << ", " 
             << result[3] << endl;
    } 

    return 0;
}

