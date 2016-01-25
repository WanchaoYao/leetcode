class Solution {
public:
    int strStr(string haystack, string needle) {
        int haystack_len = haystack.length();
        int needle_len = needle.length();
        
        if (needle_len == 0)
            return 0;
        
        for (int i = 0; i <= haystack_len - needle_len; i++)
            if (haystack.compare(i, needle_len, needle) == 0)
                return i;
        
        return -1;
    }
};
