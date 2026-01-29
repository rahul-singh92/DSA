#include <iostream>
using namespace std;

bool dfs(vector<vector<char>>& vec, string s, int i, int j, int ind)
{
    if(ind == s.size()) return true;

    if(i < 0 || j < 0 || i >= vec.size() || j >= vec[0].size() || vec[i][j] != s[ind]) 
        return false;

    char temp = vec[i][j];
    vec[i][j] = '#';
    
    bool found = dfs(vec, s, i + 1, j, ind + 1) ||
                 dfs(vec, s, i - 1, j, ind + 1) ||
                 dfs(vec, s, i, j + 1, ind + 1) ||
                 dfs(vec, s, i, j - 1, ind + 1);

    vec[i][j] = temp;

    return found;
}

bool opt_way(vector<vector<char>>& vec, string s)
{
    int rows = vec.size();
    int cols = vec[0].size();

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(dfs(vec, s, i, j, 0))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> vec = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string s = "ABCCED";

    cout<<opt_way(vec, s)<<endl;
}