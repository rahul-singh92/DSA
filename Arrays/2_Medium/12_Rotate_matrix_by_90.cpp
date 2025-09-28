#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//Brute Force: Here the time complexity is O(n*m) and space also O(n*m);
// vector<vector<int>> rot_by_90(vector<vector<int>> vec,int n,int m)
// {
//     vector<vector<int>> ans(n,vector<int>(m,0));
//     int k = 0;
//     for(int i = 0;i<m;i++)
//     {
//         for(int j = n-1; j>=0;j--)
//         {
//             ans[i][k] = vec[j][i];
//             k++;
//         }
//         k = 0;
//     }
//     return ans;
// }

//We observe that the resultant matrix is the transpose and and then the reverse of each row of the matrix so we can reduce the space complexity to O(1); 
vector<vector<int>> rot_by_90(vector<vector<int>> vec, int n, int m)
{
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<i;j++)
        {
            //Swap lower half of the matrix
            swap(vec[i][j],vec[j][i]);
        }
    }
    for(int i = 0;i<n;i++)
    {
        reverse(vec[i].begin(), vec[i].end());
    }
    return vec;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> vec(n,vector<int>(m,0));
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            cin>>vec[i][j];
        }
    }
    vector<vector<int>> ans = rot_by_90(vec,n,m);
    cout<<endl;
    for(auto it1: ans)
    {
        for(auto it2: it1)
        {
            cout<<it2<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}