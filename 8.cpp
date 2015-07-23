#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        const int length = str.length();

        int i = 0;
        // Escape whitespace character
        while (str[i] == ' ' || str[i] == '\t')
            i++;

        // Check first non-whitespace character
        int flag = 1;
        if (str[i] == '+')
        {
            flag = 1;
            i++;
        }
        else if (str[i] == '-')
        {
            flag = -1;
            i++;
        }
        else if (str[i] < '0' || str[i] > '9')
            return 0;

        int result = 0, lastResult;
        for (; i < length; i++)
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                lastResult = result;
                result *= 10;
                result += flag * (str[i] - '0');
                // Overflow: check if the operation if reversible 
                if (((result - flag * (str[i] - '0')) / 10) != lastResult)
                    if (flag == 1)
                        return INT_MAX;
                    else
                        return INT_MIN;
                // Overflow: + -> -
                if (result < 0 && flag == 1)
                    return INT_MAX;
                // Overflow: - -> + 
                if (result > 0 && flag == -1)
                    return INT_MIN;
            }
            else
                break;
        }

        return result;
    }
};

int main(void)
{
    Solution slt;
    string strs[] = {"   ", "    ", "0000", " +0000", 
                     "123", "+123", "-123", 
                     "0123", "+0123", "-0123",
                     "  +0123",
                     "2147483647", "-2147483648", "2147483648", "-2147483649",
                     "  n98", " -0123n"};
    for (int i = 0; i < sizeof(strs) / sizeof(string); i++)
        cout << strs[i] << " -> " << slt.myAtoi(strs[i]) << endl;

    return 0;
}
