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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int size = intervals.size();
        if (size == 0)
        {
            intervals.push_back(newInterval);
            return intervals;
        }

        int left = 0, right = size - 1, mid;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (intervals[mid].start == newInterval.start)
                break;
            else if (intervals[mid].start < newInterval.start)
            {
                if (mid < size - 1 && newInterval .start < intervals[mid+1].start)
                    break;
                else
                    left = mid + 1;
            }
            else
                right = mid - 1;
        }
        
        if (intervals[mid].start > newInterval.start) // mid == 0
        {
            int i;
            for (i = mid; i < size && newInterval.end >= intervals[i].start; i++);
            if (i > 0)
                newInterval.end = max(newInterval.end, intervals[i-1].end);

            intervals.erase(intervals.begin(), intervals.begin() + i);
            intervals.insert(intervals.begin(), newInterval);
        }
        else
        {
            int j;
            if (intervals[mid].end >= newInterval.start)
            {
                newInterval.start = min(newInterval.start, intervals[mid].start);
                j = mid;
            }
            else
                j = mid + 1;

            int i;
            for (i = mid + 1; i < size && newInterval.end >= intervals[i].start; i++);
            newInterval.end = max(newInterval.end, intervals[i-1].end);

            intervals.erase(intervals.begin() + j, intervals.begin() + i);
            intervals.insert(intervals.begin() + j, newInterval);
        }

        return intervals;
    }
};

int main(void)
{
    Solution slt;

    int start, end;

    cin >> start >> end;
    Interval newInterval(start, end);

    vector<Interval> intervals;
    while (cin >> start >> end)
        intervals.push_back(Interval(start, end));
    vector<Interval> merged = slt.insert(intervals, newInterval);
    for (int i = 0; i < merged.size(); i++)
        cout << "[" << merged[i].start << ", " << merged[i].end << "]" << endl;
    
    return 0;
}
