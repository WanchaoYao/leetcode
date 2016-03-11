#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0.0 || x == 1.0)
            return x;
        if (x == -1.0)
        {
            if (n % 2 == 1)
                return -1.0;
            else
                return 1.0;
        }
        if (n == 0)
           return 1.0;

        if (n < 0)
        {
            x = 1 / x;
            n = -n;
            if (n == INT_MIN)
                n = INT_MAX;
        }
        cout << n << endl;

        double res = x;
        for (int i = 1; i < n; i++)
        {
            res *= x;
            if (res == 0.0)
                break;
        }

        if (n == INT_MAX)
            res *= x;
        cout << res << endl;

        return res;
    }
};

int main(void)
{
    Solution slt;

    double x;
    int n;
    cin >> x >> n;
    double res = slt.myPow(x, n);
    cout << res << endl;
    
    return 0;
}
