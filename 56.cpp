#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Definition for an interval.
 */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    bool static comp(const Interval& a, const Interval& b)
    {
        return a.start < b.start;
    }

    vector<Interval> merge(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n <= 1)
            return intervals;

        sort(intervals.begin(), intervals.end(), comp);
        vector<Interval> merged;
        Interval cur = intervals[0];
        for (int i = 1; i < intervals.size(); i++)
            if (intervals[i].start >= cur.start && intervals[i].start <= cur.end)
                cur.end = max(cur.end, intervals[i].end);
            else
            {
                merged.push_back(cur);
                cur = intervals[i];
            }
        merged.push_back(cur);
        
        return merged;
    }
};

int main(void)
{
    Solution slt;

    int start, end;
    vector<Interval> intervals;
    while (cin >> start >> end)
        intervals.push_back(Interval(start, end));
    vector<Interval> merged = slt.merge(intervals);
    for (int i = 0; i < merged.size(); i++)
        cout << "[" << merged[i].start << ", " << merged[i].end << "]" << endl;
    
    return 0;
}
