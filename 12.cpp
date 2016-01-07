#include <iostream>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        char romanNums[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};   
        string result = "";

        int thousandDigit = num / 1000;
        num %= 1000;
        for (int i = 0; i < thousandDigit; i++)
            result += 'M';
        
        int hundredDigit = num / 100;
        num %= 100;
        if (hundredDigit <= 3)
        {
            for (int i = 0; i < hundredDigit; i++)
                result += 'C';
        }
        else if (hundredDigit == 4)
            result += "CD";
        else if (hundredDigit <= 8)
        {
            result += 'D';
            for (int i = 0; i < hundredDigit - 5; i++)
                result += 'C';
        }
        else if (hundredDigit == 9)
            result += "CM";

        int tenDigit = num / 10;
        num %= 10;
        if (tenDigit <= 3)
        {
            for (int i = 0; i < tenDigit; i++)
                result += 'X';
        }
        else if (tenDigit == 4)
            result += "XL";
        else if (tenDigit <= 8)
        {
            result += 'L';
            for (int i = 0; i < tenDigit - 5; i++)
                result += 'X';
        }
        else if (tenDigit == 9)
            result += "XC";

        int singleDigit = num;
        if (singleDigit <= 3)
        {
            for (int i = 0; i < singleDigit; i++)
                result += 'I';
        }
        else if (singleDigit == 4)
            result += "IV";
        else if (singleDigit <= 8)
        {
            result += 'V';
            for (int i = 0; i < singleDigit - 5; i++)
                result += 'I';
        }
        else if (singleDigit == 9)
            result += "IX";

        return result;
    }
};

int main(void)
{
    Solution slt;
    int numbers[] = {3, 4, 6, 9, 19, 20, 45, 1980, 3999};
    for (int i = 0; i < sizeof(numbers)/sizeof(int); i++)
        cout << numbers[i] << " -> " << slt.intToRoman(numbers[i]) << endl;

    return 0;
}
