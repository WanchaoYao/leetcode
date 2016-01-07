#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
        {
            vector<string> empty;
            return empty;
        }

        int size = digits.size();
        int resultsSize = 1;
        for (int i = 0; i < size; i++)
        {
            char c = digits[i];
            if (c == '0')
                continue;
            else if (c == '7' || c == '9')
                resultsSize *= 4;
            else
                resultsSize *= 3;
        }
        vector<string> results(resultsSize, string(size, ' '));

        int divisor = resultsSize;
        for (int i = 0; i < size; i++)
        {
            char c = digits[i];
            char set[4];
            int setSize = 3;

            if (c == '0')
                continue;
            else
            {
                switch (c)
                {
                    case '1':
                        set[0] = '0';
                        set[1] = '_';
                        set[2] = '0';
                        break;
                    case '2':
                        set[0] = 'a';
                        set[1] = 'b';
                        set[2] = 'c';
                        break;
                    case '3':
                        set[0] = 'd';
                        set[1] = 'e';
                        set[2] = 'f';
                        break;
                    case '4':
                        set[0] = 'g';
                        set[1] = 'h';
                        set[2] = 'i';
                        break;
                    case '5':
                        set[0] = 'j';
                        set[1] = 'k';
                        set[2] = 'l';
                        break;
                    case '6':
                        set[0] = 'm';
                        set[1] = 'n';
                        set[2] = 'o';
                        break;
                    case '7':
                        set[0] = 'p';
                        set[1] = 'q';
                        set[2] = 'r';
                        set[3] = 's';
                        setSize = 4;
                        break;
                    case '8':
                        set[0] = 't';
                        set[1] = 'u';
                        set[2] = 'v';
                        break;
                    case '9':
                        set[0] = 'w';
                        set[1] = 'x';
                        set[2] = 'y';
                        set[3] = 'z';
                        setSize = 4;
                        break;
                        break;
                    default:
                        break;
                }
            }

            divisor /= setSize;
            for (int j = 0; j < resultsSize; j++)
            {
                results[j][i] = set[(j/divisor)%setSize];
            }
        }

        return results;
    }
};

int main(void)
{
    Solution slt;

    //string digits = "233";
    string digits = "";
    vector<string> results = slt.letterCombinations(digits);
    for (int i = 0; i < results.size(); i++)
        cout << results[i] << endl;

    return 0;
}

