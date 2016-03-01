#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int words_size = words.size();
        int word_len = words[0].length();
        int s_len = s.length(); 
        unordered_map<string, int> words_cnt;
        for (int i = 0; i < words_size; i++)
            words_cnt[words[i]]++;

        vector<int> indices;
        for (int i = 0; i <= s_len - words_size * word_len; i++)
        {
            unordered_map<string, int> occurences;
            bool flag = true;
            for (int j = 0; j < words_size; j++)
            {
                string word = s.substr(i + j * word_len, word_len);
                if (words_cnt.find(word) != words_cnt.end())
                    occurences[word]++;
                else
                {   
                    flag = false;
                    break;
                }

                if (occurences[word] > words_cnt[word])
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
                indices.push_back(i);
        }

        return indices;
    }
};

int main(void)
{
    string s, word;
    cin >> s;
    vector<string> words;
    while (cin >> word)
        words.push_back(word);

    Solution slt;
    vector<int> indices = slt.findSubstring(s, words);
    for (int i = 0; i < indices.size(); i++)
        cout << indices[i] << " ";
    cout << endl;

    return 0;
}
