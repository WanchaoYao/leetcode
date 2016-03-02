#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        for (int i = 1; i < n; i++)
        {
            char pre = str[0];
            int cnt = 1;
            string next = "";
            for (int j = 1; j < str.size(); j++)
                if (str[j] == pre)
                    cnt++;
                else
                {
                    next += char(cnt + '0');
                    next += pre;
                    pre = str[j];
                    cnt = 1;
                }
                        
            next += char(cnt + '0');
            next += pre;
            str = next;
        }

        return str;
    }
};

int main(void)
{
    int n;
    cin >> n;

    Solution slt;
    string s = slt.countAndSay(n);
    cout << s << endl;

    return 0;
}
