#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool doIsMatch(string& s, string& p, int i, int j, int** grid)
    {
        if (i == s.size())
        {
            if (j == p.size())
                return true;
            else
            {
                if (p[j] != '*')
                    return false;
                else
                {
                    if (grid[i][j+1] == -1)
                        grid[i][j+1] = doIsMatch(s, p, i, j + 1, grid);
                    return grid[i][j+1] == 1;
                }
            }
        }
        else
        {
            if (j == p.size())
                return false;
            else
            {
                if (p[j] == '*')
                {
                    if (grid[i][j+1] == -1)
                        grid[i][j+1] = doIsMatch(s, p, i, j + 1, grid);
                    if (grid[i][j+1] == 1)
                        return true;

                    if (grid[i+1][j] == -1)
                        grid[i+1][j] = doIsMatch(s, p, i + 1, j, grid);
                    if (grid[i+1][j] == 1)
                        return true;

                    return false;
                }
                else if (p[j] == '?' || p[j] == s[i])
                {
                    if (grid[i+1][j+1] == -1)
                        grid[i+1][j+1] = doIsMatch(s, p, i + 1, j + 1, grid);
                    return grid[i+1][j+1] == 1;
                }
                else
                    return false;
            }
        }
    }
    
    bool isMatch(string s, string p) {
        if (p.size() - count(p.begin(), p.end(), '*') > s.size())
            return false;

        if (s == p)
            return true;

        // Omit continuous *, eg: a*****b
        string pp(1, p[0]);
        for (int j = 1; j < p.size(); j++)
            if (p[j] == '*' && p[j-1] == '*')
                continue;
            else
                pp += p[j];

        int** grid = new int*[s.size()+1];
        for (int i = 0; i <= s.size(); i++)
        {
            grid[i] = new int[pp.size()+1];
            memset(grid[i], -1, sizeof(int)*(pp.size()+1));
        }
        bool res = doIsMatch(s, pp, 0, 0, grid);
        for (int i = 0; i <= s.size(); i++)
            delete grid[i];
        delete[] grid;

        return res;
    }
};

int main(void)
{
    Solution slt;

    string str1, str2;
    cin >> str1 >> str2;
    cout << slt.isMatch(str1, str2) << endl;
    
    return 0;
}
