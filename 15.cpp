#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > results;
        
        int size = nums.size();
        if (size < 3)
            return results;

        sort(nums.begin(), nums.end());
        int zero_idx = -1;
        for (int i = 0; i < size; i++)
        {
            if (nums[i] == 0)
            {
                zero_idx = i;
                break;
            }
            else if (nums[i] > 0)
                break;
        }
        
        int min_val = nums.front(), max_val = nums.back();
        if (min_val > 0 || max_val < 0)
            return results;

        int last_min_val = min_val - 1;
        for (int k = 0; k < size - 2; k++)
        {
            if (nums[k] == last_min_val)
                continue;

            if (nums[k] > 0)
                break;

            int last_mid_val = nums[k] - 1;
            int target_val = 0 - nums[k];
            for (int i = k + 1; i < size - 1; i++)
            {
                if (nums[i] == last_mid_val)
                    continue;

                if (nums[i] + nums[i+1] > target_val)
                    break;

                int last_max_val = last_mid_val - 1;
                for (int j = i + 1; j < size; j++)
                {
                    if (nums[j] == last_max_val)
                        continue;

                    if (nums[i] + nums[j] == target_val)
                    {
                        vector<int> result(3, 0);
                        result[0] = nums[k];
                        result[1] = nums[i];
                        result[2] = nums[j];
                        results.push_back(result);
                        break;
                    }
                    else if (nums[i] + nums[j] > target_val)
                        break;

                    last_max_val = nums[j];
                }

                last_mid_val = nums[i];
            }

            last_min_val = nums[k];
        }

        return results;
    }
};

int main(void)
{
    Solution slt;
    //int arrays[] = {-1, 0, 1, 2, -1, -4};
    int arrays[] = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
    vector<int> nums(arrays, arrays+sizeof(arrays)/sizeof(int));
    vector<vector<int> > results = slt.threeSum(nums);
    for (int i = 0; i < results.size(); i++)
        cout << results[i][0] << " + " << results[i][1] << " + " << results[i][2] << " = 0" << endl;

    return 0;
}
