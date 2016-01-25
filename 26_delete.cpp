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
        
        vector<int>::iterator start = nums.begin();
        vector<int>::iterator i = nums.begin();
        while (i != nums.end())
        {
            i++;
            while (i != nums.end() && *i == *start)
                i++;

            i = nums.erase(start+1, i);
            start = i;
        }

        return nums.size();
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
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;

    return 0;
}
