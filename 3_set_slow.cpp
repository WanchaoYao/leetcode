#include <string>
#include <set>
#include <cstdio>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int length = s.length();
        int* longestLengths = new int[length];
        int longestLength = 0, endIndex = 0;
        std::set<char> charSet;
        
        longestLengths[0] = 0;
        for (int i = 0; i < length; i++)
        {
            if (i > 0)
                longestLengths[i] = longestLengths[i-1] - 1;

            for (int j = endIndex; j < length; j++)
            {
                // The character is already in the set
                if (charSet.find(s[j]) != charSet.end())
                {
                    endIndex = j;
                    charSet.erase(s[i]);
                    if (longestLength < longestLengths[i])
                        longestLength = longestLengths[i];
                    break;
                }
                else
                {
                    charSet.insert(s[j]);
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
    //std::string s("abcabcbb");
    //std::string s("aaaaaa");
    //std::string s("a");
    //std::string s("abcdef");
    std::string s("alkzfmq");
    
    Solution slt;
    printf("%s : %d\n", s.c_str(), slt.lengthOfLongestSubstring(s));

    return 0;
}
