#include <string>
#include <set>
#include <cstdio>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int length = s.length();
        int* longestLengths = new int[length];
        int longestLength = 0, endIndex = 0;
        bool charSet[128] = {false};
        
        longestLengths[0] = 0;
        for (int i = 0; i < length; i++)
        {
            if (i > 0)
                longestLengths[i] = longestLengths[i-1] - 1;

            for (int j = endIndex; j < length; j++)
            {
                // The character is already in the set
                if (charSet[s[j]] == true)
                {
                    endIndex = j;
                    charSet[s[i]] = false;
                    if (longestLength < longestLengths[i])
                        longestLength = longestLengths[i];
                    break;
                }
                else
                {
                    charSet[s[j]] = true;
                    longestLengths[i]++;

                    // The character is the last character of the string
                    if (j == length - 1)
                    {
                        if (longestLength < longestLengths[i])
                            longestLength = longestLengths[i];
                        return longestLength;
                    }
                }
            }
        } 

        return longestLength;
    }
};

int main(void)
{
    Solution slt;
    std::string s("abcabcbb");
    printf("%s : %d\n", s.c_str(), slt.lengthOfLongestSubstring(s));
    s = "aaaaaa";
    printf("%s : %d\n", s.c_str(), slt.lengthOfLongestSubstring(s));
    s = "a";
    printf("%s : %d\n", s.c_str(), slt.lengthOfLongestSubstring(s));
    s = "abcdef";
    printf("%s : %d\n", s.c_str(), slt.lengthOfLongestSubstring(s));
    s = "alkzfmq";
    printf("%s : %d\n", s.c_str(), slt.lengthOfLongestSubstring(s));

    return 0;
}
