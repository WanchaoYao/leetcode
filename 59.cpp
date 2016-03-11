#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix(n, vector<int>(n, 0));

        int num = 1;
        for (int i = 0; i < (n + 1) / 2; i++)
        {
            // Up
            for (int j = i; j <= n - 1 - i; j++)
                matrix[i][j] = num++;
            // Right
            if (n - 1 - i >= 0 && n - 1 - i >= i)
                for (int j = i + 1; j <= n - 2 - i; j++)
                    matrix[j][n-1-i] = num++;
            // Below
            if (n - 1 - i > i)
                for (int j = n - 1 - i; j >= i; j--)
                    matrix[n-1-i][j] = num++;
            // Left
            if (n - 1 - i > i)
                for (int j = n - 2 - i; j >= i + 1 ; j--)
                    matrix[j][i] = num++;
        }
        
        return matrix;
    }
};

int main(void)
{
    Solution slt;

    int n;
    cin>> n;

    vector<vector<int> > matrix = slt.generateMatrix(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    
    return 0;
}
