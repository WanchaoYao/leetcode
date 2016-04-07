#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int> > grid(m, vector<int>(n, 0));
        
        int ii = 0;
        for (; ii < m && obstacleGrid[ii][0] == 0; ii++)
            grid[ii][0] = 1;
        int jj = 0;
        for (; jj < n && obstacleGrid[0][jj] == 0; jj++)
            grid[0][jj] = 1;

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                    continue;

                grid[i][j] = grid[i-1][j] + grid[i][j-1];
            }
        
        return grid[m-1][n-1];
    }
};

int main(void)
{
    Solution slt;
    int m, n;
    cin >> m >> n;
    vector<vector<int> > obstacleGrid(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> obstacleGrid[i][j];

    int num = slt.uniquePathsWithObstacles(obstacleGrid);

    cout << num << endl;
    
    return 0;
}
