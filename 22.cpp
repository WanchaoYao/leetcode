#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> strs;

    vector<string> generateParenthesis(int n) {
        helper("", n, n);

        return strs;
    }

    void helper(string str, int left_cnt, int right_cnt)
    {
        if (left_cnt == 0 && right_cnt == 0)
        {
            strs.push_back(str);
            return ;
        }

        if (left_cnt > 0)
            helper(str + '(', left_cnt - 1, right_cnt);

        if (right_cnt > left_cnt)
            helper(str + ')', left_cnt, right_cnt - 1);
    }
};

int main(void)
{
    Solution slt;

    int n = 3;
    vector<string> strs = slt.generateParenthesis(n);
    for (int i = 0; i < strs.size(); i++)
        cout << strs[i] << " ";
    cout << endl;

    return 0;
}
