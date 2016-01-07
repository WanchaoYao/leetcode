#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int inline charToInt(char c)
    {
        int result;
        switch (c)
        {
            case 'I':
                result = 1;
                break;
            case 'V':
                result = 5;
                break;
            case 'X':
                result = 10;
                break;
            case 'L':
                result = 50;
                break;
            case 'C':
                result = 100;
                break;
            case 'D':
                result = 500;
                break;
            case 'M':
                result = 1000;
                break;
            default:
                break;
        }
        return result;
    }

    int romanToInt(string s) {
        int result = 0;
        int i = 0;
        for (i = 0; i < s.length() - 1; i++)
        {
            int cur_val = charToInt(s[i]);
            int next_val = charToInt(s[i+1]);
            if (cur_val < next_val)
            {
                result += (next_val - cur_val);
                i++;
            }
            else
                result += cur_val;
        }

        if (i == s.length() -1)
            result += charToInt(s[s.length()-1]);

        return result; 
    }
};

int main(void)
{
    Solution slt;
    string strs[] = {"III", "IV", "VI", "IX", "XIX", "XX", "XLV", "MCMLXXX", "MMMCMXCIX"};
    for (int i = 0; i < sizeof(strs)/sizeof(string); i++)
        cout << strs[i] << " -> " << slt.romanToInt(strs[i]) << endl;

    return 0;
}
