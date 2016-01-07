#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

struct backtrackPoint
{
    int stringIndex, patternIndex;

    backtrackPoint() { stringIndex = patternIndex = 0; }
    backtrackPoint(int stringIndex, int patternIndex): stringIndex(stringIndex), patternIndex(patternIndex){ }
};

struct pattern
{
    string s;
    pattern(const string& s): s(s) { c = '\0'; }

    char c;
    pattern(char c): c(c) { s = ""; }

    pattern() { c = '\0'; s = ""; }
};

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        // get patterns
        vector<pattern> patterns;
        int start = 0, end = 0;
        for (int i = 0; i < p.length(); i++)
        {
            if (p[i] == '.')
            {
                end = i - 1;
                
                if (end >= start)
                    patterns.push_back(pattern(p.substr(start, end - start + 1)));

                if (i+1 < p.length() && p[i+1] == '*')
                {
                    patterns.push_back(pattern('.'));

                    i++;
                }
                else
                    patterns.push_back(pattern("."));

                start = i + 1;
            }
            else if (p[i] == '*')
            {
                end = i - 2;
                
                if (end >= start)
                    patterns.push_back(pattern(p.substr(start, end - start + 1)));

                patterns.push_back(pattern(p[i-1]));

                start = i + 1;
            }
        }
        if (p[p.length() - 1] != '*')
            patterns.push_back(pattern(p.substr(start)));

        // print patterns
        /*
        for (int i = 0; i < patterns.size(); i++)
        {
            cout << "Patterns[" << i << "]: ";
            if (patterns[i].s.length() > 0)
                cout << patterns[i].s << " ";
            else
                cout << patterns[i].c << "* ";
            cout << endl;
        }
        */
   
        int patternIndex = 0;
        int m = 0;
        stack<backtrackPoint> backtrackPoints;
        bool backtrack = false;
        while (true)
        {
            //cout << "stringIndex: " << m << " patternIndex: " << patternIndex << " backtrackPoints.size(): " << backtrackPoints.size() << endl;

            if (patternIndex == patterns.size()) // pass all sub pattern(s), check
            {
                if (m == s.length())
                    return true;
                if (m < s.length()) // the whole string matches preceding sub pattern(s) of the whole pattern, backtrack
                { 
                    if (backtrackPoints.size() > 0) 
                    {
                        backtrackPoint point = backtrackPoints.top();
                        backtrackPoints.pop();
                        m = point.stringIndex;
                        patternIndex = point.patternIndex;
                        backtrack = true;
                        continue;
                    }
                    else
                        return false;
                }
            }

            pattern currentPattern = patterns[patternIndex];

            if (m == s.length())
            {
                bool flag = true;
                for (int idx = patternIndex; idx < patterns.size(); idx++)
                    if (patterns[idx].s.length() > 0)
                    {
                        flag = false;
                        break;
                    } 
                if (flag) // current and latter sub pattern(s) are all star expression(s)
                    return true;
                else // backtrack
                {
                    if (backtrackPoints.size() > 0) 
                    {
                        backtrackPoint point = backtrackPoints.top();
                        backtrackPoints.pop();
                        m = point.stringIndex;
                        patternIndex = point.patternIndex;
                        backtrack = true;
                        continue;
                    }
                    else
                        return false;
                }
            }

            if (currentPattern.s.length() > 0) // trivial string
            {
                if (currentPattern.s.compare(".") == 0 || s.compare(m, currentPattern.s.length(), currentPattern.s) == 0)
                {
                    m += currentPattern.s.length();
                    patternIndex++;
                }
                else // backtrack
                {
                    if (backtrackPoints.size() > 0) 
                    {
                        backtrackPoint point = backtrackPoints.top();
                        backtrackPoints.pop();
                        m = point.stringIndex;
                        patternIndex = point.patternIndex;
                        backtrack = true;
                        continue;
                    }
                    else
                        return false;
                }
            }
            else // star expression
            {
                if (backtrack == true) // eat a character
                {
                    backtrack = false;
                    if (currentPattern.c == '.' || s[m] == currentPattern.c) // eat a character
                    {
                        m++;
                        backtrackPoints.push(backtrackPoint(m, patternIndex));
                        patternIndex++;
                    }
                    else // backtrack
                    {
                        if (backtrackPoints.size() > 0) 
                        {
                            backtrackPoint point = backtrackPoints.top();
                            backtrackPoints.pop();
                            m = point.stringIndex;
                            patternIndex = point.patternIndex;
                            backtrack = true;
                            continue;
                        }
                        else
                            return false;
                    }
                }
                else // eat no character, i.e. pass current star expression 
                {
                    backtrackPoints.push(backtrackPoint(m, patternIndex));
                    patternIndex++;
                }
            }
        }
        cout << "Error: undefined!" << endl;
    }
};

int main(void)
{
    Solution slt;
    string ss[] = {"abc", "aa", "aa", "aaa", "aa", "aab", "aab", "aab", "aba", "aba", "abcd", "aaa"};
    string pp[] = {"a*abc*b*", "a", "aa", "aa", "a*", "a*b", "c*a*b", "c*a*.*b*b", ".*", ".*.*", "d*", "a.a"};
    for (int i = 0; i < sizeof(ss) / sizeof(string); i++)
        cout << ss[i] << " , " << pp[i] << " -> " << slt.isMatch(ss[i], pp[i]) << endl;

    return 0;
}
