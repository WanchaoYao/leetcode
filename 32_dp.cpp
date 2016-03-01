#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        int res = 0;
        vector<int> longest(len, 0);

        for (int i = 1; i < len; i++)
        {
            if (s[i] == ')')
            {
                if (s[i-1] == '(')
                {
                    if (i == 2)
                        longest[i] = 2;
                    else
                        longest[i] = longest[i-2] + 2;
                    res = max(res, longest[i]);
                }
                else
                {
                    if (i - longest[i-1] - 1 >= 0 && s[i - longest[i-1] - 1] == '(')
                    {
                        if (i - longest[i-1] - 2 >= 0)
                            longest[i] = longest[i-1] + 2 + longest[i - longest[i-1] - 2];
                        else
                            longest[i] = longest[i-1] + 2;
                    }
                    res = max(res, longest[i]);
                }
            }
        }

        return res;   
    }
};

int main(void)
{
    string s;
    cin >> s;

    Solution slt;
    int n = slt.longestValidParentheses(s);
    cout << n << endl;

    return 0;
}
