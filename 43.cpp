#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string add(string num1, string num2)
    {
        if (num1.size() > num2.size())
            swap(num1, num2);
        string res = num2;
        int carry = 0;
        int i;
        for (i = num2.size() - 1; i >= 0; i--)
        {
            int d;
            char c;
            if (i >= num2.size() - num1.size())
            {
                d = (num2[i] - '0') + (num1[num1.size() - (num2.size() - i)] - '0') + carry;
                c = d % 10 + '0';
                carry = d / 10;   
            }
            else
            {
                if (carry == 0)
                    break;
                else
                {
                    d = (num2[i] - '0') + carry;
                    c = d % 10 + '0';
                    carry = d / 10;   
                }
            }

            res[i] = c;
        }

        if (carry == 1)
            res = "1" + res;

        return res;
    }

    string mul(string num, char c)
    {
        if (c == '0')
        return "0";
        if (c == '1')
            return num;
        if (c == '2')
            return add(num, num);

        string res = num;
        int op = c - '0';
        int carry = 0;
        for (int i = num.size() - 1; i >= 0; i--)
        {
            int d = (num[i] - '0') * op + carry;
            char cc = d % 10 + '0';
            carry = d / 10;   

            res[i] = cc;
        }

        if (carry > 0)
            res = char(carry + '0') + res;

        return res;
    }

    string multiply(string num1, string num2) {
        if (num1.size() > num2.size())
            swap(num1, num2);

        if (num1 == "0")
            return num1;
        if (num1 == "1")
            return num2;

        string fin_res, tmp_res;
        for (int i = num1.size() - 1; i >= 0; i--)
        {
            tmp_res = mul(num2, num1[i]) + string(num1.size() - 1 - i, '0');
            if (i == num1.size() - 1)
                fin_res = tmp_res;
            else
                fin_res = add(fin_res, tmp_res);
        }

        return fin_res;
    }
};

int main(void)
{
    Solution slt;

    /* test add and mul
    string num1, num2;
    char c;
    cin >> num1 >> num2 >> c;
    cout << slt.add(num1, num2) << endl;
    cout << slt.mul(num1, c) << endl;
    */

    string num1, num2;
    cin >> num1 >> num2;
    cout << slt.multiply(num1, num2) << endl;
    
    return 0;
}
