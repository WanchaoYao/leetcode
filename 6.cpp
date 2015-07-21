#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;

        const int length = s.length();
        const int setSize = 2 * numRows - 2;

        string rows[numRows];
        for (int i = 0; i < length; i++)
        {
            int rowNumber = i % setSize;
            if (rowNumber >= numRows)
                rowNumber = 2 * (numRows - 1) - rowNumber;
            rows[rowNumber] += s[i];
        }

        string output;
        for (int i = 0; i < numRows; i++)
            output += rows[i];
        
        return output;
    }
};

int main(void)
{
    Solution slt;
    string inputStrings[] = {"PAYPALISHIRING", "PAYPALISHIRING", "PAYPALISHIRING", "PAYPALISHIRING", "PAYPALISHIRING"}; 
    int inputInts[] = {1, 2, 3, 4, inputStrings[4].length()};
    for (int i = 0; i < sizeof(inputStrings) / sizeof(string); i++)
        cout << inputStrings[i] << " -> " << slt.convert(inputStrings[i], inputInts[i]) << endl;

    return 0;
}
