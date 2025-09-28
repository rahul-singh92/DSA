#include <iostream>
#include <vector>
using namespace std;

//Brute force O(i * j * (i + j)) almost n^3
// vector<vector<int>> set_mat(vector<vector<int>> vec, int i, int j)
// {
//     vector<vector<int>> ans = vec;
//     for(int k = 0;k < i;k++)
//     {
//         for(int l = 0;l < j;l++)
//         {
//             if(vec[k][l] == 0)
//             {
//                 for(int m = 0;m < j;m++)
//                 {
//                     ans[k][m] = 0;
//                 }
//                 for(int m = 0;m < i;m++)
//                 {
//                     ans[m][l] = 0;
//                 }
//             }
//         }
//     }
//     return ans;
// }


//Better by using space complexity of O(i+j) and time for O(n^2)
// vector<vector<int>> set_mat(vector<vector<int>> &vec, int i, int j)
// {
//     int *col = new int[j]();
//     int *row = new int[i]();
//     for(int k = 0;k < i;k++)
//     {
//         for(int l = 0;l < j;l++)
//         {
//             if(vec[k][l] == 0)
//             {
//                 col[l] = 1;
//                 row[k] = 1;
//             }
//         }
//     }

//     for(int k = 0;k < i;k++)
//     {
//         for(int l = 0;l < j;l++)
//         {
//             if(row[k] || col[l])
//             {
//                 vec[k][l] = 0;
//             }
//         }
//     }
//     return vec;
// }

//Now to reduce the space complexity we will assume col[0] to be row and row[1] to be col where we will declare a variable for col 0
vector<vector<int>> set_mat(vector<vector<int>> vec, int i, int j)
{  
    // int *col = new int[j]();  --> vec[0][..]
    // int *row = new int[i]();  --> vec[..][0]
    int col0 = 1;
    for(int k = 0;k < i;k++)
    {
        for(int l = 0;l < j;l++)
        {
            if(vec[k][l] == 0)
            {
                //mark the i-th row
                vec[k][0] = 0;
                //mark the j-th column
                if(l != 0)
                {
                    vec[0][l] = 0;
                }
                else
                {
                    col0 = 0;
                }
            }
        }
    }

    for(int k = 1;k < i;k++)
    {
        for(int l = 1;l < j;l++)
        {
            if(vec[k][l] != 0)
            {
                if(vec[0][l] == 0 || vec[k][0] == 0)
                {
                    vec[k][l] = 0;
                }
            }
        }
    }
    if(vec[0][0] == 0)
    {
        for(int l = 0;l < j;l++)
        {
            vec[0][l] = 0;
        }
    }
    if(col0 == 0)
    {
        for(int k = 0;k<i;k++)
        {
            vec[k][0] = 0;
        }
    }

    return vec;   
}

int main()
{
    int i,j;
    cin>>i>>j;
    vector<vector<int>> vec(i, vector<int>(j,0));
    for(int k = 0;k < i;k++)
    {
        for(int l = 0;l < j;l++)
        {
            cin >> vec[k][l];
        }
    }
    vector<vector<int>> ans = set_mat(vec,i,j);
    cout<<endl;
    for(auto it1 : ans)
    {
        for(auto it2: it1)
        {
            cout<<it2<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}