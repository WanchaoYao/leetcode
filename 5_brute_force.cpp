#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        const int length = s.length();
        if (length == 0)
            return s;

        int* lengths = new int[length];
        int startIndex = 0, longestLength = 0;
        for (int i = 0; i < length; i++)
        {
            int minLength;
            if (i == 0)
                minLength = 1;
            else
                minLength = min(lengths[i-1] - 2, 1);

            int maxLength = length - i;
            if (maxLength < longestLength)
                break;

            for (int lengthIter = minLength; lengthIter <= maxLength; lengthIter++)
            {
                if (isPalindrome(s.substr(i, lengthIter)))
                {
                    lengths[i] = lengthIter;
                    if (lengthIter > longestLength)
                    {
                        startIndex = i;
                        longestLength = lengthIter;
                    }
                }
            }
        }

        delete[] lengths;

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

