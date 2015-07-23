#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x == 0)
            return true;
        else if (x < 0)
            return false;
        else if (x % 10 == 0)
            return false;

        int reverse= 0, xx = x;
        while (x >= 10)
        {
            reverse *= 10;
            reverse += x % 10;
            x /= 10;
        }
        if (xx % 10 == x && xx / 10 == reverse)
            return true;
        else
            return false;
    }
};

int main(void)
{
    Solution slt;
    int numbers[] = {0, 1, -1, 10, 101, 111, -101, -111, 2147447412, -2147447412};
    for (int i = 0; i < sizeof(numbers) / sizeof(int); i++)
        cout << numbers[i] << " -> " << slt.isPalindrome(numbers[i]) << endl;

    return 0;
}
