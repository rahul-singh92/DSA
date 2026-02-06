#include <iostream>
using namespace std;

void bru_way(vector<int> queries)
{
    int n = queries[queries.size() - 1];
    vector<int> ls(n + 1, 1);

    for(int i = 1; i < ls.size(); i++) ls[i] = i;

    for(int i = 2; i*i <= n; i++)
    {
        if(ls[i] == i)
        {
            for(int j = i*i; j <= n; j+= i)
            {
                if(ls[j] == j) ls[j] = i;
            }
        }
    }

    for(int i = 0; i < queries.size(); i++)
    {
        int d = queries[i];
        while(d != 1)
        {
            cout<<ls[d]<<" ";
            d /= ls[d];
        }
        cout<<endl;
    }
}


int main()
{
    vector<int> queries = {2, 3, 4, 5, 6};
    bru_way(queries);
}