#include <iostream>
using namespace std;

// Using recursion
int fun(vector<vector<int>>& days, int day, int last)
{
    if(day == 0)
    {
        int maxi = 0;
        for(int i = 0; i < 3; i++)
        {
            if(i != last)
            {
                maxi = max(maxi, days[0][i]);
            }
        }
        return maxi;
    }

    int maxi = 0;
    for(int i = 0; i < 3; i++)
    {
        int points = days[day][i] + fun(days, day - 1, i);
        maxi = max(maxi, points);
    }
    return maxi;
}

int solve(vector<vector<int>>& days)
{
    return fun(days, days.size() - 1, 3);
}

// Using Memoization
int bet(vector<vector<int>>& points, int day, int last, vector<vector<int>>& dp)
{
    if(day == 0)
    {
        int maxi = 0;
        for(int i = 0; i < 3; i++)
        {
            if(i != last)
            {
                maxi = max(maxi, points[0][i]);
            }
        }
        return maxi;
    }

    if(dp[day][last] != -1) return dp[day][last];

    int maxi = 0;
    for(int i = 0; i < 3; i++)
    {
        if(i != last)
        {
            int point = points[day][i] + bet(points, day - 1, i, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[day][last] = maxi;
}

int sol(vector<vector<int>>& points)
{
    vector<vector<int>> dp(points.size(), vector<int>(4, -1));
    return bet(points, points.size() - 1, 3, dp);
}

// Using tabulation

int s(vector<vector<int>>& points)
{
    vector<vector<int>> dp(points.size(), vector<int>(4, 0));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for(int day = 1; day < points.size(); day++)
    {
        for(int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;


            for(int task = 0; task < 3; task++)
            {
                if(task != last)
                {
                    int point = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }
    return dp[points.size() - 1][3];
}

// Space optimisation
int space_op(vector<vector<int>>& points)
{
    vector<int> dp(4, 0);
    dp[0] = max(points[0][1], points[0][2]);
    dp[1] = max(points[0][0], points[0][2]);
    dp[2] = max(points[0][0], points[0][1]);
    dp[3] = max(points[0][1], max(points[0][1], points[0][2]));

    for(int day = 1; day < points.size(); day++)
    {
        vector<int> temp(4, 0);
        for(int last = 0; last < 4; last++)
        {
            temp[last] = 0;

            for(int task = 0; task < 3; task++)
            {
                if(task != last)
                {
                    temp[last] = max(temp[last], points[day][task] + dp[task]);
                }
            }
        }
        dp = temp;
    }
    return dp[3];
}

int main()
{
    vector<vector<int>> days = {{10, 40, 70}, {20, 50, 80}, {30, 60, 90}};
    // int ans = solve(days);  Using recursion
    // int ans = sol(days); // using memoization
    // int ans = s(days); // Using tabulation
    int ans = space_op(days);
    cout<<ans<<endl;
}