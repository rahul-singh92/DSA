#include <iostream>
using namespace std;

void op_way(vector<vector<int>>& matrix)
{
    int n = matrix.size();

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(matrix[i][j] == -1)
                matrix[i][j] = 1e9;
            if(i == j) matrix[i][j] = 0;
        }
    }


    // for each intermediate node k
    for(int k = 0; k < n; k++)
    {
        // check for every (i, j) pair
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {   
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(matrix[i][j] == 1e9)
                matrix[i][j] = -1;
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {
        {0, 2, -1, -1},
        {1, 0, 3, -1},
        {-1, -1, 0, -1},
        {3, 5, 4, 0}
    };

    op_way(matrix);
    
    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix.size(); j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}