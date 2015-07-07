#include <vector>
#include <set>
#include <cstdio>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::set<int> needNumbers;
        for (int i = 0; i < nums.size(); i++)
        {
            int anotherNumber = target - nums[i];
            if (needNumbers.find(anotherNumber) != needNumbers.end())
            {
                for (int j = 0; j < i; j++)
                {
                    if (anotherNumber == nums[j])
                    {
                        std::vector<int> indeces;
                        indeces.push_back(j + 1);
                        indeces.push_back(i + 1);
                        return indeces;
                    }
                }
            }
            else
                needNumbers.insert(nums[i]);
        }
    }
};

int main(void)
{
    int numsArray[] = {2, 7, 11, 15};
    std::vector<int> nums(numsArray, numsArray + sizeof(numsArray) / sizeof(int));
    int target = 9;
    Solution slt;
    std::vector<int> indeces = slt.twoSum(nums, target);
    printf("%d + %d = %d", nums[indeces[0] - 1], nums[indeces[1] - 1], target);
}
