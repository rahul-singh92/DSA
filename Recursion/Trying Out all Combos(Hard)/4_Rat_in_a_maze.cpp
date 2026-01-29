#include <iostream>
using namespace std;

bool isSafe(int x, int y, int n, vector<vector<int>>& maze, vector<vector<int>>& visited)
{
    return (x >= 0 && x < n && y >= 0 && y < n &&
            maze[x][y] == 1 && visited[x][y] == 0);
}

void solve(int x, int y, int n, vector<vector<int>>& maze, vector<vector<int>>& visited,
            string path, vector<string>& res)
{
    if(x == n - 1 && y == n - 1)
    {
        res.push_back(path);
        return;
    }

    visited[x][y] = 1;

    if(isSafe(x + 1, y, n, maze, visited))
    {
        solve(x + 1, y, n, maze, visited, path + "D", res);
    }
    if(isSafe(x, y - 1, n, maze, visited))
    {
        solve(x, y - 1, n, maze, visited, path + "L", res);
    }
    if(isSafe(x, y + 1, n, maze, visited))
    {
        solve(x, y + 1, n, maze, visited, path + "R", res);
    }
    if(isSafe(x - 1, y, n, maze, visited))
    {
        solve(x - 1, y, n, maze, visited, path + "U", res);
    }

    //Backtrack unmark 0
    visited[x][y] = 0;
}

vector<string> findPath(vector<vector<int>>& maze, int n)
{
    vector<string> res;
    vector<vector<int>> visited(n, vector<int>(n, 0));
    if(maze[0][0] == 1)
    {
        solve(0, 0, n, maze, visited, "", res);
    }
    return res;
}

int main()
{
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    int n = maze.size();
    vector<string> paths = findPath(maze, n);

    for(auto i : paths) cout<<i<<endl;
    cout<<endl;
}