#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalSize = nums1.size()+nums2.size();
        vector<int> nums;

        int minNumber;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            minNumber = min(nums1[i], nums2[j]);
            //cout << "i: " << i << " j: " << j << endl;
            //cout << "minNumber: " << minNumber << endl;
            for (; i < nums1.size(); i++)
            {
                if (nums1[i] == minNumber)
                {
                    //cout << "nums1[" << i << "]: " << nums1[i] << endl;
                    nums.push_back(nums1[i]);
                }
                else
                {
                    break;
                }
            }

            for (; j < nums2.size(); j++)
            {
                if (nums2[j] == minNumber)
                {
                    //cout << "nums2[" << j << "]: " << nums2[j] << endl;
                    nums.push_back(nums2[j]);
                }
                else
                {
                    break;
                }
            }
        }

        if (i < nums1.size())
            for (; i < nums1.size(); i++)
                    nums.push_back(nums1[i]);

        if (j < nums2.size())
            for (; j < nums2.size(); j++)
                    nums.push_back(nums2[j]);

        /*
        cout << "nums: ";
        for (int k = 0; k < totalSize; k++)
            cout << nums[k] << " ";
        cout << endl;
        */

        double median;
        if (totalSize % 2 == 1)
            median = nums[(totalSize-1)/2];
        else
            median = 0.5 * (nums[(totalSize-1)/2] + nums[(totalSize-1)/2 + 1]);

        return median;
    }
};

int main(void)
{
    Solution slt;

    int array1[] = {0, 1};
    int array2[] = {1, 3, 4};
    vector<int> nums1(array1, array1 + sizeof(array1)/sizeof(int));
    cout << "nums1: ";
    for (int k = 0; k < nums1.size(); k++)
        cout << nums1[k] << " ";
    cout << endl;
    vector<int> nums2(array2, array2 + sizeof(array2)/sizeof(int));
    cout << "nums2: ";
    for (int k = 0; k < nums2.size(); k++)
        cout << nums2[k] << " ";
    cout << endl;

    double median;
    median = slt.findMedianSortedArrays(nums1, nums2);
    cout << "median: " << median << endl;

    return 0;
}
