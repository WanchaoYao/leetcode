#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        const int length = s.length();
        if (length <= 1)
            return s;

        int p[2*length+1];
        string ss(2*length+1, '#');
        for (int i = 0; i < length; i++)
        {
            ss[1+2*i] = s[i];
            p[1+2*i] = 2;
            p[2*i] = 1;
        }
        p[2*length] = 1;

        int startIndex = 0, longestLength = p[0];
        for (int i = 1; i < 2*length+1; i++)
        {
            int j = 2 * startIndex - i;
            //cout << "i: " << i << " j: " << j << " idx: " << startIndex << endl;
            int curLength;
            if (j >= 0 && i < startIndex + longestLength)
                if (i + p[j] < startIndex + longestLength)
                {
                    p[i] = p[j];
                    curLength = p[i];
                }
                else
                    curLength = p[j];
            else
                curLength = p[i];
            
            //cout << "curLength before expand: " << curLength << endl;
            while (i - curLength >= 0 && i + curLength < 2 * length + 1 && ss[i+curLength] == ss[i-curLength])
                curLength++;
            p[i] = curLength;
            //cout << "curLength after expand: " << curLength << endl;
            
            if (curLength > longestLength)
            {
                startIndex = i;
                longestLength = curLength;
                //cout << "idx: " << startIndex << " longestLength: " << longestLength << endl;
            }
        }

        return s.substr((startIndex-longestLength+1)/2, longestLength-1);
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
