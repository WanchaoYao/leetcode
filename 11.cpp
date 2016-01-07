#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        int max_area = 0;
        int i = 0, j = height.size() - 1;
        while (i < j)
        {
            int w = j - i;
            int h = min(height[i], height[j]);
            max_area = max(max_area, w*h);
            while (height[i] <= h && i < j)
                i++;
            while (height[j] <= h && i < j)
                j--;
        }
 
        return max_area;
    }
};

int main(int argc, char** argv)
{
    Solution slt;

    vector<int> height;
    int single_int;
    for (int i = 1; i < argc; i++)
    {
        single_int = atoi(argv[i]);
        height.push_back(single_int);
    }

    for (int i = 0; i < height.size(); i++)
        cout << height[i] << " ";
    cout << "-> " << slt.maxArea(height) << endl;

    return 0;
}
