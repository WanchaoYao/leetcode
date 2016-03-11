#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
public:
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

        bool** grid = new bool*[s.size()+1];
        for (int i = 0; i <= s.size(); i++)
        {
            grid[i] = new bool[pp.size()+1];
            memset(grid[i], false, sizeof(bool)*(pp.size()+1));
        }
        for (int i = 1; i <= s.size(); i++)
            grid[i][0] = false;
        for (int j = 1; j <= pp.size(); j++)
            if (pp[j-1] == '*')
                grid[0][j] = true;
            else
                break;
        grid[0][0] = true;

        for (int i = 1; i <= s.size(); i++)
            for (int j = 1; j <= pp.size(); j++)
            {
                if (pp[j-1] == '*')
                    grid[i][j] = grid[i][j-1] || grid[i-1][j];
                else
                    grid[i][j] = grid[i-1][j-1] && (pp[j-1] == '?' || s[i-1] == pp[j-1]);
            }

        bool res = grid[s.size()][pp.size()];

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
