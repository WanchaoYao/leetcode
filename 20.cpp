#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;

        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (c == '(' || c == '[' || c == '{')
                parentheses.push(c);
            else
            {
                if (parentheses.empty())
                    return false;
                char cc = parentheses.top();
                if (c == ')' && cc == '(' || c == ']' && cc == '[' || c == '}' && cc == '{')
                    parentheses.pop();
                else
                    return false;
            }
        }

        if (parentheses.empty())
            return true;
        else
            return false;
    }
};

int main(void)
{
    Solution slt;

    string s[] = {"()", "()[]{}", "(]", "([)]"};
    for (int i = 0; i < sizeof(s)/sizeof(string); i++)
        cout << s[i] << ' ' << slt.isValid(s[i]) << endl;

    return 0;
}
