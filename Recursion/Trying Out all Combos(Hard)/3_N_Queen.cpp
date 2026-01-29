#include <iostream>
using namespace std;

bool isSafe(int row, int col, vector<vector<char>>& board, int n)
{
    //Check all columns to the left
    for(int j = 0; j < col; j++)
    {
        if(board[row][j] == 'Q') return false;
    }

    // check upper left diagonal
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if(board[i][j] == 'Q') return false;
    }

    // check lower left diagonal
    for(int i = row, j = col; i < n && j >= 0; i++, j--)
    {
        if(board[i][j] == 'Q') return false;
    }

    return true;
}

void backtrack(int col, vector<vector<char>>& board, vector<vector<string>>& ans, int n)
{
    if(col == n)
    {
        vector<string> temp;
        for(int i = 0; i < n; i++)
        {
            string row(board[i].begin(), board[i].end());
            temp.push_back(row);
        }
        ans.push_back(temp);
        return;
    }

    //Try placing queen in all rows of current colummn
    for(int row = 0; row < n; row++)
    {
        //Place queen only if safe
        if(isSafe(row, col, board, n))
        {
            //Plsce Queen
            board[row][col] = 'Q';
            //Recurse for next colums

            backtrack(col + 1, board, ans, n);
            //Backtrack and remove the queen
            board[row][col] = '.';
        }
    }
}
//Brute Way
vector<vector<string>> brute_way(int n)
{
    vector<vector<string>> ans;

    vector<vector<char>> board(n, vector<char>(n, '.'));

    //Start Backtracking from column 0
    backtrack(0, board, ans, n);
    return ans;
}


void solve(int col, vector<string>& board, int n, vector<int>& leftRow, vector<int>& upperDiagonal,
            vector<int>& lowerDiagonal, vector<vector<string>>& ans)
{
    //If all queens are placed
    if(col == n)
    {
        ans.push_back(board);
        return;
    }

    // Iterate through all rows
    for(int row = 0; row < n; row++)
    {
        if(leftRow[row] == 0 && lowerDiagonal[row + col] == 0 &&
            upperDiagonal[(n - 1 )+ (col - row)] == 0)
        {
            //Place the queen
            board[row][col] = 'Q';

            //Mark the row and diagonals
            leftRow[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[(n - 1) + (col - row)] = 1;

            //Recurse the next column
            solve(col + 1, board, n, leftRow, upperDiagonal, lowerDiagonal, ans);

            //Backtrack and remove the queen
            board[row][col] = '.';
            leftRow[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[(n - 1) + (col - row)] = 0;
        }
    }
}

//Optimal way
vector<vector<string>> opt_way(int n)
{
    vector<vector<string>> ans;
    vector<string> board (n, string(n, '.'));
    vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);

    solve(0, board, n, leftRow, upperDiagonal, lowerDiagonal, ans);

    return ans;
}

int main()
{
    int n = 4;

    vector<vector<string>> res = opt_way(n);

    for(auto i: res)
    {
        for(auto j: i)
        {
            cout<<j<<endl;
        }
        cout<<endl;
    }
}