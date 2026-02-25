#include <iostream>
using namespace std;

int bru_way(vector<int>& ratings)
{
    int n = ratings.size();
    vector<int> candy(n, 1);

    bool updated = true;

    while (updated)
    {
        updated = false;

        for(int i = 1; i < n; i++)
        {
            if(ratings[i] > ratings[i-1] && candy[i] <= candy[i-1])
            {
                candy[i] = candy[i-1] + 1;
                updated = true;
            }
        }

        for(int i = n - 2; i >= 0; i--)
        {
            if(ratings[i] > ratings[i+1] && candy[i] <= candy[i+1])
            {
                candy[i] = candy[i+1] + 1;
                updated = true;
            }
        }
    }

    int sum = 0;
    for(int i = 0; i < n; i++) sum+= candy[i];

    return sum;
}

int bet_way(vector<int>& ratings)
{
    int n = ratings.size();
    vector<int> candy(n, 1);

    for(int i = 1; i < n; i++)
    {
        if(ratings[i] > ratings[i-1])
        {
            candy[i] = candy[i-1] + 1;
        }
    }

    for(int i = n - 2; i >= 0; i--)
    {
        if(ratings[i] > ratings[i+1])
        {
            candy[i] = max(candy[i], candy[i+1] + 1);
        }
    }

    int sum = 0;
    for(int i = 0; i < n; i++) sum+=candy[i];
    return sum;
}

int op_way(vector<int>& ratings)
{
    int n = ratings.size();
    int candies = n;

    int i = 1;
    while(i < n)
    {
        if(ratings[i] == ratings[i-1])
        {
            i++;
            continue;
        }

        int peak = 0;
        while(i < n && ratings[i] > ratings[i-1])
        {
            peak++;
            candies += peak;
            i++;
        }

        int valley = 0;
        while(i < n && ratings[i] < ratings[i-1])
        {
            valley++;
            candies += valley;
            i++;
        }
        candies -= min(peak, valley);
    }
    return candies;
}

int main()
{
    vector<int> ratings = {1, 0, 5};
    int ans = op_way(ratings);
    cout<<ans<<endl;
}