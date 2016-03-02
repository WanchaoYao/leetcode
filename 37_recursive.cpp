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

    bool doSolveSudoku(vector<vector<char> >& board, int row, int col)
    {
        if (row == 9)
            return true;

        if (col == 9)
            return doSolveSudoku(board, row + 1, 0);

        if (board[row][col] != '.')
            return doSolveSudoku(board, row, col + 1);

        for (char c = '1'; c <= '9'; c++)
        {
            if (checkCell(board, row, col, c))
            {
                board[row][col] = c;
                if (doSolveSudoku(board, row, col + 1))
                    return true;
                board[row][col] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char> >& board) {
        doSolveSudoku(board, 0, 0);
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
