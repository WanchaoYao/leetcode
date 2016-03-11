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

    void doSolve(int& cnt, vector<string>& str, int i, int j, int n)
    {
        if (i == n || j == n)
            return;

        // false -> no clash
        bool flag = check(str, i, j, n);

        // Clash
        if (flag == true)
            doSolve(cnt, str, i, j + 1, n);
        else
        {
            str[i][j] = 'Q';
            if (i == n - 1)
                cnt++;
            else
                doSolve(cnt, str, i + 1, 0, n);
            str[i][j] = '.';
            doSolve(cnt, str, i, j + 1, n);
        }


    }

    int totalNQueens(int n) {
        vector<string> str(n, string(n, '.'));
        int cnt = 0;
        doSolve(cnt, str, 0, 0, n);
        
        return cnt;
    }
};

int main(void)
{
    Solution slt;

    int n, cnt = 0;
    cin >> n;
    cnt = slt.totalNQueens(n);
    cout << cnt << endl;
    
    return 0;
}
