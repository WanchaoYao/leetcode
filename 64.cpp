#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int> > minSum(m, vector<int>(n, 0));
        
        minSum[0][0] = grid[0][0];
        for (int i = 1; i < m; i++)
            minSum[i][0] = grid[i][0] + minSum[i-1][0];
        for (int j = 0; j < n; j++)
            minSum[0][j] = grid[0][j] + minSum[0][j-1];

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                minSum[i][j] = min(minSum[i-1][j], minSum[i][j-1]) + grid[i][j];
        
        return minSum[m-1][n-1];
    }
};

int main(void)
{
    Solution slt;
    int m, n;
    cin >> m >> n;
    vector<vector<int> > grid(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    int num = slt.minPathSum(grid);

    cout << num << endl;
    
    return 0;
}
