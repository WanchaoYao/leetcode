#include <string>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        int res = 0;
        stack<int> stk;

        for (int i = 0; i < len; i++)
        {
            if (s[i] == '(')
                stk.push(i);
            else
            {
                if (stk.empty())
                    stk.push(i);
                else
                {
                    if (s[stk.top()] == '(')
                    {
                        stk.pop();
                        if (stk.empty())
                            res = i + 1;
                        else
                            res = max(res, i - stk.top());
                    }
                    else
                        stk.push(i);
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
