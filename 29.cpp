#include <climits>
#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0)
            return INT_MAX;
            
        if (dividend == 0)
            return 0;
            
        if (divisor == 1)
            return dividend;
            
        if (divisor == -1)
            if (dividend == INT_MIN)
                return INT_MAX;
            else
                return -dividend;
        
        int sign = (dividend > 0 ^ divisor > 0) ? -1 : 1;
        long long_dividend = abs((long)dividend);
        long long_divisor = abs((long)divisor);

        int result = 0;
        while (long_dividend >= long_divisor)
        {
            long val = long_divisor;
            long multiplier = 1;
            while (long_dividend > (val << 1))
            {
                multiplier <<= 1;
                val <<= 1;
            }
            result += multiplier;
            long_dividend -= val;
        }
        
        return sign * result;
    }
};

int main(void)
{
    int m, n;
    cin >> m >> n;

    Solution slt;
    int result = slt.divide(m, n);
    cout << result << endl;
    cout << m << " / " << n << " = " <<  m/n << endl;
    cout << m << " % " << n << " = " <<  m%n << endl;

    return 0;
}
