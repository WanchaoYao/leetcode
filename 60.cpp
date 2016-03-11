#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string s(n, '0');
        vector<char> set(n, '0');
        for (int i = 0; i < n; i++)
            set[i] += i + 1;
        int factor = 1;
        for (int i = 1; i <= n; i++)
            factor *= i;
        for (int i = n; i > 0; i--)
        {
            factor /= i;
            int set_idx = (k-1) / factor;
            k -= set_idx * factor;
            s[n-i] = set[set_idx];
            set.erase(set.begin()+set_idx);
        }
        
        return s;
    }
};

int main(void)
{
    Solution slt;
    int n, k;
    cin >> n >> k;

    string s = slt.getPermutation(n, k);
    cout << s << endl;
    
    return 0;
}
