#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int flag = x >= 0 ? 1 : -1;
        int input = x >= 0 ? x : -x;
        int output = 0;
        while (input != 0)
        {
            int lastOutput = output;
            output *= 10;
            output += input % 10;
            if ((output - input % 10) / 10 != lastOutput)
                return 0;
            input /= 10;   
        }
        output *= flag;

        return output; 
    }
};

int main(void)
{
    Solution slt;
    int inputs[] = {0, 1, 123, -123, 1230, 1000000003, 1534236469};
    for (int i = 0; i < sizeof(inputs) / sizeof(int); i++)
        cout << inputs[i] << " -> " << slt.reverse(inputs[i]) << endl;

    return 0;
}
