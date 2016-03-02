#include <string>
#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<char> >& board)
{
    cout << "***************\n";
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

class Solution {
public:
    bool checkCell(vector<vector<char> >& board, int row, int col, char c)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == c)
                return false;
            if (board[i][col] == c)
                return false;
            if (board[row-row%3+i/3][col-col%3+i%3] == c)
                return false;
        }

        return true;
    }

    void solveSudoku(vector<vector<char> >& board) {
        vector<int> indices;
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] == '.')
                    indices.push_back(9*i+j);

        int size = indices.size();
        int i = 0;
        while (i < size)
        {
            int idx = indices[i];
            int row = idx / 9;
            int col = idx % 9;
            char c;
            if (board[row][col] == '.')
                c = '1';
            else
                c = board[row][col] + 1;
            for (; c < '9' + 1; c++)
            {
                // Check
                if (checkCell(board, row, col, c) == false)
                    continue;
                
                board[row][col] = c;
                break;
            }

            if (c < '9' + 1)
            {
                i++;
            }
            else // Backtrack
            {
                board[row][col] = '.';
                i--;
            }
        }
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
    slt.solveSudoku(board);

    print(board);

    return 0;
}
