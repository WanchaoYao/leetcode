#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool inline check(vector<string>& str, int i, int j, int n)
    {
        for (int ii = 0; ii < i; ii++)
            if (str[ii][j] == 'Q')
                return true;

        for (int ii = i - 1, jj = j - 1; ii >= 0 && jj >= 0; ii--, jj--)
            if (str[ii][jj] == 'Q')
                return true;

        for (int ii = i - 1, jj = j + 1; ii >= 0 && jj < n; ii--, jj++)
            if (str[ii][jj] == 'Q')
                return true;

        return false;
    }

    void doSolve(vector<vector<string> >& strs, vector<string>& str, int i, int j, int n)
    {
        if (i == n || j == n)
            return;

        // false -> no clash
        bool flag = check(str, i, j, n);

        // Clash
        if (flag == true)
            doSolve(strs, str, i, j + 1, n);
        else
        {
            str[i][j] = 'Q';
            if (i == n - 1)
                strs.push_back(str);
            else
                doSolve(strs, str, i + 1, 0, n);
            str[i][j] = '.';
            doSolve(strs, str, i, j + 1, n);
        }


    }

    vector<vector<string> > solveNQueens(int n) {
        vector<string> str(n, string(n, '.'));
        vector<vector<string> > strs;
        doSolve(strs, str, 0, 0, n);
        
        return strs;
    }
};

int main(void)
{
    Solution slt;

    vector<vector<string> > strs;
    int n;
    cin >> n;
    strs = slt.solveNQueens(n);
    for (int i = 0; i < strs.size(); i++)
    {
        for (int j = 0; j < strs[i].size(); j++)
            cout << strs[i][j] << endl;
        cout << endl;
    }
    
    return 0;
}
