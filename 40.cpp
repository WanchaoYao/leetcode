#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void doCombinationSum(vector<vector<int> >& sets, vector<int>& set, vector<int>& candidates, int target, int idx)
    {
        if (0 == target)
        {
            sets.push_back(set);
            return;
        }

        for (int i = idx; i < candidates.size() && candidates[i] <= target;)
        {
            set.push_back(candidates[i]);
            doCombinationSum(sets, set, candidates, target - candidates[i], i + 1);
            set.pop_back();
            i++;
            while (i < candidates.size() && candidates[i-1] == candidates[i])
                i++;
        }
    }

    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        vector<int> set;
        vector<vector<int> > sets;
        sort(candidates.begin(), candidates.end());

        doCombinationSum(sets, set, candidates, target, 0);

        return sets;
    }
};

int main(void)
{
    int num, target;
    cin >> target;
    vector<int> nums;
    while (cin >> num)
        nums.push_back(num);

    Solution slt;
    vector<vector<int> > sets = slt.combinationSum2(nums, target);
    for (int i = 0; i < sets.size(); i++)
    {
        for (int j = 0; j < sets[i].size(); j++)
            cout << sets[i][j] << " ";
        cout << endl;
    }

    return 0;
}
