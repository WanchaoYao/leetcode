#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        if (n == -1)
            return 1.0/x;
        if (n == 1)
            return x;

        double sub = myPow(x, n / 2);
        double res = sub * sub * myPow(x, n % 2);

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
