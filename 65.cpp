#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isRealNumber(string s)
    {
        int len = s.length();
        if (len == 0)
            return false;
        if (s == "-" || s == "." || s == "+" || s == "-." || s == "+.")
            return false;

        int i = 0;
        if (s[i] == '-' || s[i] == '+')
            i++;

        int dotCnt = 0;
        for (; i < len; i++)
        {
            if (s[i] == '.')
            {
                dotCnt++;
                if (dotCnt >= 2)
                    return false;
            }
            else if (s[i] >= '0' && s[i] <= '9')
                continue;
            else
                return false;
        }

        return true;
    }

    bool isInteger(string s)
    {
        int len = s.length();
        if (len == 0)
            return false;
        if (s == "-" || s == "+")
            return false;

        int i = 0;
        if (s[i] == '-' || s[i] == '+')
            i++;

        int dotCnt = 0;
        for (; i < len; i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
                continue;
            else
                return false;
        }

        return true;
    }

    bool isNumber(string s) {
        int len = s.length();
        int start = 0;
        while (s[start] == ' ' || s[start] == '\t')
            start++;
        int end = len - 1;
        while (s[end] == ' ' || s[end] == '\t')
            end--;
        s = s.substr(start, end-start+1);


        int pos = s.find('e');
        if (pos == -1)
        {
            return isRealNumber(s);
        }
        else
        {
            return isRealNumber(s.substr(0, pos)) && isInteger(s.substr(pos + 1));
        }
    }
};

int main(void)
{
    Solution slt;
    string str;
    while (getline(cin, str))
        cout << slt.isNumber(str) << endl;
    
    return 0;
}
