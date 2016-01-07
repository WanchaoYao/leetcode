#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        int result = 0;

        sort(nums.begin(), nums.end());
        int min_dis = INT_MAX;
        
        for (int i = 0; i < size - 2; i++)
        {
            // Omit duplicate numbers
            if (i > 0 && nums[i] == nums[i-1])
                continue;

            int last_idx = size - 1;
            while (last_idx > i + 1 && nums[i] + nums[i+1] + nums[last_idx] >= target)
                last_idx--;

            // All subsequent sets are increasing and not smaller than target
            if (last_idx == i + 1)
            {
                int sum = nums[i] + nums[i+1] + nums[i+2];
                int cur_dis = abs(sum - target);
                if (min_dis > cur_dis)
                {
                    min_dis = cur_dis;
                    result = sum;
                }
                break;
            }
            
            int n = last_idx;
            for (int m = i + 1; m < size - 1; m++)
            {
                if (m > i + 1 && nums[m] == nums[m-1])
                    continue;

                // n moves left from last_idx
                while (n > m && nums[i] + nums[m] + nums[n] >= target)
                    n--;

                int small_sum = nums[i] + nums[m] + nums[n], large_sum = small_sum;
                int nn = n + 1;
                while (nn < size && nums[n] == nums[nn])
                    nn++;
                if (nn < size)
                    large_sum = nums[i] + nums[m] + nums[nn];

                int large_sum_dis = abs(large_sum - target), small_sum_dis = abs(small_sum - target);
                if (large_sum_dis < small_sum_dis)
                {
                    if (min_dis > large_sum_dis)
                    {
                        result = large_sum;
                        min_dis = large_sum_dis;
                    }
                }
                else 
                {
                    if (min_dis > small_sum_dis)
                    {
                        result = small_sum;
                        min_dis = small_sum_dis;
                    } 
                }

                if (min_dis == 0)
                    return result;

                // All subsequent sets are increasing and not smaller than target
                if (nums[i] + nums[m] + nums[n] > target)
                    break;
            }
        }

        return result;
    }
};

int main(void)
{
    Solution slt;

    //int arrays[] = {-1, 2, 1, -4};
    //int target = 1;
    
    //int arrays[] = {43,75,-90,47,-49,72,17,-31,-68,-22,-21,-30,65,88,-75,23,97,-61,53,87,-3,33,20,51,-79,43,80,-9,34,-89,-7,93,43,55,-94,29,-32,-49,25,72,-6,35,53,63,6,-62,-96,-83,-73,66,-11,96,-90,-27,78,-51,79,35,-63,85,-82,-15,100,-82,1,-4,-41,-21,11,12,12,72,-82,-22,37,47,-18,61,60,55,22,-6,26,-60,-42,-92,68,45,-1,-26,5,-56,-1,73,92,-55,-20,-43,-56,-15,7,52,35,-90,63,41,-55,-58,46,-84,-92,17,-66,-23,96,-19,-44,77,67,-47,-48,99,51,-25,19,0,-13,-88,-10,-67,14,7,89,-69,-83,86,-70,-66,-38,-50,66,0,-67,-91,-65,83,42,70,-6,52,-21,-86,-87,-44,8,49,-76,86,-3,87,-32,81,-58,37,-55,19,-26,66,-89,-70,-69,37,0,19,-65,38,7,3,1,-96,96,-65,-52,66,5,-3,-87,-16,-96,57,-74,91,46,-79,0,-69,55,49,-96,80,83,73,56,22,58,-44,-40,-45,95,99,-97,-22,-33,-92,-51,62,20,70,90};
    //int target = 284;
    
    //int arrays[] = {6,-18,-20,-7,-15,9,18,10,1,-20,-17,-19,-3,-5,-19,10,6,-11,1,-17,-15,6,17,-18,-3,16,19,-20,-3,-17,-15,-3,12,1,-9,4,1,12,-2,14,4,-4,19,-20,6,0,-19,18,14,1,-15,-5,14,12,-4,0,-10,6,6,-6,20,-8,-6,5,0,3,10,7,-2,17,20,12,19,-13,-1,10,-1,14,0,7,-3,10,14,14,11,0,-4,-15,-8,3,2,-5,9,10,16,-4,-3,-9,-8,-14,10,6,2,-12,-7,-16,-6,10};
    //int target = -52;

    int arrays[] = {0, 1, 2};
    int target = 0;

    vector<int> nums(arrays, arrays+sizeof(arrays)/sizeof(int));
    int min_dis = slt.threeSumClosest(nums, target);
    cout << min_dis << endl;

    return 0;
}

