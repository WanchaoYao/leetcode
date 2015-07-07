#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n)
            return findMedianSortedArrays(nums2, nums1);

        int start = 0, end = m;
        int i, j;
        while (start <= end) 
        {
            i = (start+end)/2;
            j = (m+n+1)/2 - i;
            cout << "start: " << start << " end: " << end 
                 << " i: " << i << " j: " << j << endl;

            if (i == 0 || j == n || nums1[i - 1] <= nums2[j])
                if (j == 0 || i == m || nums1[i] >= nums2[j-1])
                    break;
                else
                    start = i + 1;
            else
                end = i - 1;
        };

        int maxNum;
        if (i == 0)
            maxNum = nums2[j-1];
        else if (j == 0)
            maxNum = nums1[i-1];
        else
            maxNum = max(nums1[i-1], nums2[j-1]);
        
        int minNum;
        if (i == m)
            minNum = nums2[j];
        else if (j == n)
            minNum = nums1[i];
        else
            minNum = min(nums1[i], nums2[j]);
        
        double median;
        if (i+j == (m-i)+(n-j))
            median = 0.5*(minNum+maxNum);
        else
            median = maxNum;

        return median;
    }
};

int main(void)
{
    Solution slt;

    int array1[] = {2};
    int array2[] = {};
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
