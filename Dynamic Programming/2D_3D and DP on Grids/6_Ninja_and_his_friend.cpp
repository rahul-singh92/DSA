#include <iostream>
using namespace std;

// Recursive Way
int recursive_way(int i, int j1, int j2, vector<vector<int>>& grid)
{
    int n = grid.size(), m = grid[0].size();

    if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)  return -1e8; // any big negative number

    if(i == n - 1)
    {
        if(j1 == j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }


    int maxi = 0;
    for(int dj1 = -1; dj1 <= 1; dj1++)
    {
        for(int dj2 = -1; dj2 <= 1; dj2++)
        {
            if(j1 == j2) maxi = max(maxi, grid[i][j1] + recursive_way(i+1, j1+dj1, j2+dj2, grid));
            else maxi = max(maxi, grid[i][j1] + grid[i][j2] + recursive_way(i+1, j1 + dj1, j2 + dj2, grid));
        }
    }
    return maxi;
}


// Memoization Way
int solve(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp)
{
    int n = grid.size(), m = grid[0].size();
    if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return -1e8;
    
    
    if(i == n - 1)
    {
        if(j1 == j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }

    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

    int maxi = 0;

    int curr = (j1 == j2)? grid[i][j1]: grid[i][j1] + grid[i][j2];

    for(int dj1 = -1; dj1 <= 1; dj1++)
    {
        for(int dj2 = -1; dj2 <= 1; dj2++)
        {
            int ans = curr + solve(i+1, j1 + dj1, j2 + dj2, grid, dp);
            maxi = max(ans, maxi);
        }
    }
    return dp[i][j1][j2] = maxi;
}

int memo_way(vector<vector<int>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1))); // i j1 j2 so n m m
    return solve(0, 0, m - 1, grid, dp); // (i1, j1, i2, j2) -> (i, j1, j2) because i will always move next for both alex and bob
}

// Tabulation Way
int tabulation_way(vector<vector<int>>& grid)
{
    int n = grid.size(), m = grid[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

    for(int j1 = 0; j1 < m; j1++)
    {
        for(int j2 = 0; j2 < m; j2++)
        {
            if(j1 == j2) dp[n-1][j1][j2] = grid[n-1][j1];
            else dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
        }
    }

    for(int i = n - 2; i >= 0; i--)
    {
        for(int j1 = 0; j1 < m; j1++)
        {
            for(int j2 = 0; j2 < m; j2++)
            {
                int maxi = 0;
                int curr = (j1 == j2)? grid[i][j1]: grid[i][j1] + grid[i][j2];
                for(int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for(int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        int ans;
                        if(j1+dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2+dj2 <m)
                            ans = curr + dp[i+1][j1 + dj1][j2 + dj2];
                        else ans = -1e8;
                        maxi = max(maxi, ans);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][m-1];
}

int spaceOp_way(vector<vector<int>>& grid)
{
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> next(m, vector<int>(m, 0));
    vector<vector<int>> curr(m, vector<int>(m, 0));

    for(int j1 = 0; j1 < m; j1++)
    {
        for(int j2 = 0; j2 < m; j2++)
        {
            if(j1 == j2) next[j1][j2] = grid[n-1][j1];
            else next[j1][j2] = grid[n-1][j1] + grid[n-1][j2]; 
        }
    }

    for(int i = n - 2; i >= 0; i--)
    {
        for(int j1 = 0; j1 < m; j1++)
        {
            for(int j2 = 0; j2 < m; j2++)
            {
                int maxi = 0;
                int currEle = (j1 == j2)? grid[i][j1]: grid[i][j1] + grid[i][j2];

                // try all 9 row
                for(int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for(int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        if(j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
                            maxi = max(maxi, currEle + next[j1 + dj1][j2 + dj2]);
                        else
                            maxi = max(maxi, (int)-1e8);
                    }
                }
                curr[j1][j2] = maxi;
            }
        }
        next = curr;
    }
    return next[0][m-1];
}

int main()
{
    vector<vector<int>> grid = {
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5}  
    };
    // int ans = recursive_way(0, 0, grid[0].size() - 1, grid);
    // int ans = memo_way(grid);
    // int ans = tabulation_way(grid);
    int ans = spaceOp_way(grid);
    cout<<ans<<endl;
}