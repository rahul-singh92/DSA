#include <iostream>
using namespace std;

bool isValid(vector<vector<char>>& board, int row, int col, char c)
{
    //Check all rows in the current collumn
    for(int i = 0; i < 9; i++)
    {
        if(board[i][col] == c) return false;
    }

    //Check all colums
    for(int j = 0; j < 9; j++)
    {
        if(board[row][j] == c) return false;
    }

    //Calculate start indices of 3*3 sub box
    int boxRowStart = 3 * (row / 3);
    int boxColStart = 3 * (col / 3);

    //Check the 3*3 sub box for duplicate character
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[boxRowStart + i][boxColStart + j] ==c) return false;
        }
    }
    return true;
}

bool solveSudoku(vector<vector<char>>& board)
{
    //Traverse eaach cell in the board
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            //If current cell is empty
            if(board[i][j] == '.')
            {
                for(char c = '1'; c<='9'; c++)
                {
                    //Check if placing c is valid here
                    if(isValid(board, i, j,c))
                    {
                        board[i][j] = c;

                        //Recur to solve the rest of the board
                        if(solveSudoku(board))
                        {
                            return true;
                        }
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{
     vector<vector<char>> board {
        {'.', '7', '8', '5', '.', '.', '.', '.', '.'},
        {'.', '.', '3', '.', '.', '7', '8', '.', '.'},
        {'.', '.', '.', '1', '9', '.', '.', '.', '.'},
        {'.', '.', '7', '.', '.', '.', '2', '9', '.'},
        {'.', '9', '.', '.', '6', '1', '.', '4', '.'},
        {'.', '.', '.', '.', '.', '4', '.', '.', '.'},
        {'3', '.', '6', '.', '.', '2', '.', '.', '.'},
        {'.', '1', '.', '.', '.', '.', '.', '.', '4'},
        {'.', '.', '.', '.', '.', '.', '5', '.', '.'}
    };

    solveSudoku(board);

    for(auto i: board)
    {
        for(auto j: i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}