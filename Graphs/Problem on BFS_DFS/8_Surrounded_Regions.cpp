#include <iostream>
using namespace std;

void dfs(int row, int col, vector<vector<int>>& visited, vector<vector<char>>& mat, vector<int> delrow, vector<int> delcol)
{
    visited[row][col] = 1;
    
    int n = mat.size();
    int m = mat[0].size();

    for(int k = 0; k < 4; k++)
    {
        int nrow = row + delrow[k];
        int ncol = col + delcol[k];

        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && mat[nrow][ncol] == 'O')
        {
            dfs(nrow, ncol, visited, mat, delrow, delcol);
        }
    }
}

vector<vector<char>> op_way(int n, int m, vector<vector<char>> mat)
{
    if(n == 0 || m == 0) return mat;

    vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delcol = {0, 1, 0, -1};

    vector<vector<int>> visited(n, vector<int>(m, 0));

    for(int j = 0; j < m; j++)
    {
        if(!visited[0][j] && mat[0][j] == 'O') dfs(0, j, visited, mat, delrow, delcol);
        if(!visited[n-1][j] && mat[n-1][j] == 'O') dfs(n-1, j, visited, mat, delrow, delcol);
    }

    for(int i = 0; i < n; i++)
    {
        if(!visited[i][0] && mat[i][0] == 'O') dfs(i, 0, visited, mat, delrow, delcol);
        if(!visited[i][m-1] && mat[i][m-1] == 'O') dfs(i, m-1, visited, mat, delrow, delcol);
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!visited[i][j] && mat[i][j] == 'O') mat[i][j] = 'X';
        }
    }
    return mat;
}

int main()
{
    vector<vector<char>> mat{
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'X', 'O', 'O'}
    };

    vector<vector<char>> ans = op_way((int)mat.size(), (int)mat[0].size(), mat);
    for(auto ii: ans)
    {
        for(auto i: ii) cout<<i<<" ";
        cout<<endl;
    }
}