#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        const int length = s.length();
        if (length <= 1)
            return s;

        int startIndex = 0, longestLength = 1;
        for (int i = 1; i < length; i++)
        {
            if (isPalindrome(s.substr(i-longestLength, longestLength+1)))
            {
                startIndex = i-longestLength;
                longestLength++;
            }
            else if (i-longestLength-1 >= 0 && isPalindrome(s.substr(i-longestLength-1, longestLength+2)))
            {
                startIndex = i-longestLength-1;
                longestLength += 2;
            }
        }

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
    string strs[] = {"1", "", "1223", "1221", "111", "12231114", "12231113", "mwwfjysbkebpdjyabcfkgprtxpwvhglddhmvaprcvrnuxifcrjpdgnktvmggmguiiquibmtviwjsqwtchkqgxqwljouunurcdtoeygdqmijdympcamawnlzsxucbpqtuwkjfqnzvvvigifyvymfhtppqamlgjozvebygkxawcbwtouaankxsjrteeijpuzbsfsjwxejtfrancoekxgfyangvzjkdskhssdjvkvdskjtiybqgsmpxmghvvicmjxqtxdowkjhmlnfcpbtwvtmjhnzntxyfxyinmqzivxkwigkondghzmbioelmepgfttczskvqfejfiibxjcuyevvpawybcvvxtxycrfbcnpvkzryrqujqaqhoagdmofgdcbhvlwgwmsmhomknbanvntspvvhvccedzzngdywuccxrnzbtchisdwsrfdqpcwknwqvalczznilujdrlevncdsyuhnpmheukottewtkuzhookcsvctsqwwdvfjxifpfsqxpmpwospndozcdbfhselfdltmpujlnhfzjcgnbgprvopxklmlgrlbldzpnkhvhkybpgtzipzotrgzkdrqntnuaqyaplcybqyvidwcfcuxinchretgvfaepmgilbrtxgqoddzyjmmupkjqcypdpfhpkhitfegickfszermqhkwmffdizeoprmnlzbjcwfnqyvmhtdekmfhqwaftlyydirjnojbrieutjhymfpflsfemkqsoewbojwluqdckmzixwxufrdpqnwvwpbavosnvjqxqbosctttxvsbmqpnolfmapywtpfaotzmyjwnd", "aaabaaaa"};
    for (int i = 0; i < sizeof(strs)/sizeof(string); i++)
        cout << strs[i] << " -> " << slt.longestPalindrome(strs[i]) << endl;

    return 0;
}
