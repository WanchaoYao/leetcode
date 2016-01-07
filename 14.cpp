#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        else if (strs.size() == 1)
            return strs[0];

        int minLen = strs[0].size();
        for (int i = 0; i < strs.size() - 1; i++)
        {
            const string& str1 = strs[i];
            const string& str2 = strs[i+1];
            int curLen = 0;
            for (int j = 0; j < min(str1.size(), str2.size()); j++)
                if (str1[j] == str2[j])
                    curLen++;
                else
                    break;
            minLen = min(minLen, curLen);
        }
        //cout << "minLen: " << minLen << endl;

        return strs[0].substr(0, minLen);
    }
};

int main(void)
{
    Solution slt;
    //string str_arrays[] = {"abc", "ac", "acb", "acca", "accac"};
    string str_arrays[] = {"aca", "cba"};
    vector<string> strs(str_arrays, str_arrays+sizeof(str_arrays)/sizeof(string));
    string prefix = slt.longestCommonPrefix(strs);
    for (int i = 0; i < strs.size(); i++)
        cout << strs[i] << " -> " << prefix << endl;

    return 0;
}
