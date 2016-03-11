#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void doPermute(vector<vector<int> >& res, vector<int> r, vector<int> v)
    {
        int size = v.size();
        if (size == 1)
        {
            r.push_back(v[0]);
            res.push_back(r);
            return;
        }

        for (int i = 0; i < size; i++)
        {
            vector<int> rr(r);
            vector<int> vv(v);
            rr.push_back(v[i]); 
            vv.erase(vv.begin() + i);
            doPermute(res, rr, vv);
        }
    }

    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> r;
        vector<int> v(nums);
        doPermute(res, r, v);

        return res;
    }
};

int main(void)
{
    Solution slt;

    int num;
    vector<int> nums;
    while (cin >> num)
        nums.push_back(num);
    vector<vector<int> > res = slt.permute(nums);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    
    return 0;
}
