#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    /* dp[i][j]:
     * true  -> s[0...i-1] matches p[0...j-1]
     * flase -> otherwise
     *
     * (1) trivial string
     * p[i][j] = p[i-1][j-1], if p[j-1] != '*' && (s[i-1] == p[j-1] || p[j-1] == '.')
     * (2) x* matches empty string
     * p[i][j] = p[i][j-2], if p[j-1] == '*' 
     * (3) x* -> xx*, i.e. x repeats for at least 1 times
     * p[i][j] = p[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'), if p[j-1] == '*'
     */
    bool isMatch(string s, string p)
    {
        int m = s.length(), n = p.length();

        vector<vector<bool> > dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true; // initialization

        for (int i = 0; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (p[j-1] == '*')
                    dp[i][j] = dp[i][j-2] || i > 0 && dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.');
                else
                    dp[i][j] = i > 0 && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.'); 

        return dp[m][n];
    }
};

int main(void)
{
    Solution slt;
    string ss[] = {"baccbbcbcacacbbc", "abc", "aa", "aa", "aaa", "aa", "aab", "aab", "aab", "aba", "aba", "abcd", "aaa"};
    string pp[] = {"c*.*b*c*ba*b*b*.a*","a*abc*b*", "a", "aa", "aa", "a*", "a*b", "c*a*b", "c*a*.*b*b", ".*", ".*.*", "d*", "a.a"};
    for (int i = 0; i < sizeof(ss) / sizeof(string); i++)
        cout << ss[i] << " , " << pp[i] << " -> " << slt.isMatch(ss[i], pp[i]) << endl;

    return 0;
}
