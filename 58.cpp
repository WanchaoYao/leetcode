#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        char c;
        int end = s.size() - 1;
        while (end >= 0 && s[end] == ' ')
            end--;

        int start = end - 1;
        while (start >= 0 && s[start] != ' ')
            start--;

        if (end == -1)
            return 0;
        
        return end - start;
    }
};

int main(void)
{
    Solution slt;

    string str;
    getline(cin, str);

    int res = slt.lengthOfLastWord(str);
    cout << res << endl;
    
    return 0;
}
