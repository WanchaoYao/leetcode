#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> nums;
        int m = matrix.size();
        if (m == 0)
            return nums;

        int n = matrix[0].size();
        for (int i = 0; i < (m + 1) / 2; i++)
        {
            // Up
            for (int j = i; j <= n - 1 - i; j++)
                nums.push_back(matrix[i][j]);
            // Right
            if (n - 1 - i >= 0 && n - 1 - i >= i)
                for (int j = i + 1; j <= m - 2 - i; j++)
                    nums.push_back(matrix[j][n-1-i]);
            // Below
            if (m - 1 - i > i)
                for (int j = n - 1 - i; j >= i; j--)
                    nums.push_back(matrix[m-1-i][j]);
            // Left
            if (n - 1 - i > i)
                for (int j = m - 2 - i; j >= i + 1 ; j--)
                    nums.push_back(matrix[j][i]);
        }
        
        return nums;
    }
};

int main(void)
{
    Solution slt;
    int m, n;
    cin >> m >> n;

    int num;
    vector<vector<int> > matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    vector<int> nums = slt.spiralOrder(matrix);
    for (int i = 0; i < nums.size(); i++) 
        cout << nums[i] << " ";
    cout << endl;
    
    return 0;
}
