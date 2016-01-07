#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        if (p.empty())
            return s.empty();

        if (p[1] == '*')
            // x* matches empty string or at least one character: x* -> xx*
            return isMatch(s, p.substr(2)) || 
                    !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p);
        else
            // trivial string
            return !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p.substr(1));
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
