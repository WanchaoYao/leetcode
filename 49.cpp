#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string> > m;
        map<vector<int>, vector<string> >::iterator it;

        for (int i = 0; i < strs.size(); i++)
        {
            vector<int> cnts(26, 0);
            for (int j = 0; j < strs[i].size(); j++)
            {
                cnts[strs[i][j] - 'a']++;
            }
            it = m.find(cnts);
            if (it != m.end())
                it->second.push_back(strs[i]);
            else
                m.insert(pair<vector<int>, vector<string> >(cnts, vector<string>(strs.begin()+i, strs.begin()+i+1)));
        }
        
        vector<vector<string> > groups;
        for (it = m.begin(); it != m.end(); it++)
        {
            sort(it->second.begin(), it->second.end());
            groups.push_back(it->second);
        }

        return groups;
    }
};

int main(void)
{
    Solution slt;

    string str;
    vector<string> strs;
    while (cin >> str)
        strs.push_back(str);
    vector<vector<string> > groups;
    groups = slt.groupAnagrams(strs);
    for (int i = 0; i < groups.size(); i++)
    {
        for (int j = 0; j < groups[i].size(); j++)
            cout << groups[i][j] << " ";
        cout << endl;
    }
    
    return 0;
}
