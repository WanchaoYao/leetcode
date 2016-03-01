#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkCells(vector<char>& cells)
    {
        vector<int> count(9 , 0);
        for (int j = 0; j < 9; j++)
        {
            if (cells[j] == '.')
                continue;

            int number = cells[j]-'1';
            count[number]++;
            if (count[number] > 1)
                return false;
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char> >& board) {
        vector<char> cells;

        // Check row
        for (int i = 0; i < 9; i++)
        {
            if (checkCells(board[i]) == false)
                return false;
        }

        // Check column
        for (int i = 0; i < 9; i++)
        {
            cells.clear();
            for (int j = 0; j < 9; j++)
                cells.push_back(board[j][i]);

            if (checkCells(cells) == false)
                return false;
        }

        // Check box
        for (int i = 0; i < 9; i += 3)
            for (int j = 0; j < 9 ;j += 3)
            {
                cells.clear();
                for (int ii = i; ii < i + 3; ii++)
                    for (int jj = j; jj < j + 3; jj++)
                    {
                        cells.push_back(board[ii][jj]);
                    }

                if (checkCells(cells) == false)
                    return false;
            }
        
        return true;
    }
};

int main(void)
{
    char c;
    vector<vector<char> > board(9, vector<char>(9));
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> board[i][j];

    Solution slt;
    bool res = slt.isValidSudoku(board);
    cout << res << endl;

    return 0;
}
