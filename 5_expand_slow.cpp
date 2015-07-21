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
            int j, k, curLength;
            
            // Odd length
            j = i - 1;
            k = i + 1;
            curLength = 1;
            while (j >= 0 && k < length && s[j] == s[k])
            {
                j--;
                k++;
                curLength += 2;
            }
            
            if (curLength > longestLength)
            {
                startIndex = j + 1;
                longestLength = curLength;
            }

            // Even length
            j = i - 1;
            k = i;
            curLength = 0;
            while (j >= 0 && k < length && s[j] == s[k])
            {
                j--;
                k++;
                curLength += 2;
            }
            
            if (curLength > longestLength)
            {
                startIndex = j + 1;
                longestLength = curLength;
            }
        }

        return s.substr(startIndex, longestLength);
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
