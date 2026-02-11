#include <iostream>
using namespace std;

int bru_way(vector<vector<int>>& arr)
{
    int n = arr.size();

    vector<int> knowMe(n, 0);
    vector<int> Iknow(n, 0);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[i][j] == 1)
            {
                knowMe[j]++;
                Iknow[i]++;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(knowMe[i] == n-1 && Iknow[i] == 0)
        {
            return i;
        }
    }
    return -1;
}

int op_way(vector<vector<int>>& arr)
{
    int n = arr.size();

    int top = 0, down = n - 1;

    while(top < down)
    {
        // If top knows down it cant be celebrity
        if(arr[top][down] == 1) top++;

        //If down knows top it cant be celebrity
        else if(arr[down][top] == 1) down--;

        //If both does not know each other, it cant be celebrity
        else
        {
            top++;
            down--;
        }
    }

    // It means no celebrity is there
    if(top > down) return -1;

    // Check if the top == down person is celebrity
    for(int i = 0; i < n; i++)
    {
        if(i == top) continue;

        if(arr[top][i] == 1 || arr[i][top] == 0) return -1;
    }
    return top;
}

int main()
{
    vector<vector<int>> arr = {
         {0, 1, 1, 0}, 
         {0, 0, 0, 0}, 
         {1, 1, 0, 0}, 
         {0, 1, 1, 0}
    };

    int ans =  op_way(arr);
    cout<<ans<<endl;
}