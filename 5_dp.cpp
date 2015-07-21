#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        const int length = s.length();
        if (length <= 1)
            return s;

        bool dp[length][length];
        /*
        bool **dp = new bool*[length];
        for (int i = 0; i < length; i++)
            dp[i] = new bool[length];
        */
        
        int startIndex = 0, longestLength = 1;

        for (int i = 0; i < length; i++)
            dp[i][i] = true;
        
        for (int i = 0; i < length - 1; i++)
            if (s[i] == s[i+1])
            {
                startIndex = i;
                longestLength = 2;
                dp[i][i+1] = true;
            }
            else
                dp[i][i+1] = false;

        for (int l = 3; l <= length; l++)
        {
            // Early stop
            bool flag = false;
            for (int i = 0; i + l - 1 <= length; i++)
                if (dp[i][i+l-2])
                {
                    flag = true;
                    break;
                }
            if (!flag)
                for (int i = 0; i + l - 2 <= length; i++)
                    if (dp[i][i+l-3])
                    {
                        flag = true;
                        break;
                    }
            if (!flag)
                return s.substr(startIndex, longestLength);

            for (int i = 0; i + l <= length; i++)
                if (s[i] == s[i+l-1] && dp[i+1][i+l-2])
                {
                    startIndex = i;
                    longestLength = l;
                    dp[i][i+l-1] = true;
                }
                else
                    dp[i][i+l-1] = false;
        }

        /*
        for (int i = 0; i < length; i++)
            delete[] dp[i];
        delete[] dp;
        */

        return s.substr(startIndex, longestLength);
    }

    inline bool isPalindrome(const string& s)
    {
        bool flag = true;
        int length = s.length();
        for (int i = 0; i < length/2; i++)
            if (s[i] != s[length-1-i])
            {
                flag = false;
                break;
            }

        //cout << s << " " << flag << endl;

        return flag;
    }
};

int main(void)
{
    Solution slt;
    string str1 = "1";
    string strs[] = {"1", "", "1223", "1221", "111", "12231114", "12231113", "mwwfjysbkebpdjyabcfkgprtxpwvhglddhmvaprcvrnuxifcrjpdgnktvmggmguiiquibmtviwjsqwtchkqgxqwljouunurcdtoeygdqmijdympcamawnlzsxucbpqtuwkjfqnzvvvigifyvymfhtppqamlgjozvebygkxawcbwtouaankxsjrteeijpuzbsfsjwxejtfrancoekxgfyangvzjkdskhssdjvkvdskjtiybqgsmpxmghvvicmjxqtxdowkjhmlnfcpbtwvtmjhnzntxyfxyinmqzivxkwigkondghzmbioelmepgfttczskvqfejfiibxjcuyevvpawybcvvxtxycrfbcnpvkzryrqujqaqhoagdmofgdcbhvlwgwmsmhomknbanvntspvvhvccedzzngdywuccxrnzbtchisdwsrfdqpcwknwqvalczznilujdrlevncdsyuhnpmheukottewtkuzhookcsvctsqwwdvfjxifpfsqxpmpwospndozcdbfhselfdltmpujlnhfzjcgnbgprvopxklmlgrlbldzpnkhvhkybpgtzipzotrgzkdrqntnuaqyaplcybqyvidwcfcuxinchretgvfaepmgilbrtxgqoddzyjmmupkjqcypdpfhpkhitfegickfszermqhkwmffdizeoprmnlzbjcwfnqyvmhtdekmfhqwaftlyydirjnojbrieutjhymfpflsfemkqsoewbojwluqdckmzixwxufrdpqnwvwpbavosnvjqxqbosctttxvsbmqpnolfmapywtpfaotzmyjwnd", "aaabaaaa"};
    for (int i = 0; i < sizeof(strs)/sizeof(string); i++)
        cout << strs[i] << " -> " << slt.longestPalindrome(strs[i]) << endl;

    return 0;
}
