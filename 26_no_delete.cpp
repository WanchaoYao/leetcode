#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1)
            return size;
        
        int i = 1, j = 1;
        for (; i < size; i++)
            if (nums[i] != nums[i - 1])
                nums[j++] = nums[i];

        return j;
    }
};

int main(void)
{
    int size;
    cin >> size;

    vector<int> nums(size, 0);
    for (int i = 0; i < size; i++)
        cin >> nums[i];
    
    Solution slt;
    int n = slt.removeDuplicates(nums);
    cout << "n = " << n << endl;
    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";
    cout << endl;

    return 0;
}
