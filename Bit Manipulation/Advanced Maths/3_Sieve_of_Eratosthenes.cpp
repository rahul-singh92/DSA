#include <iostream>
using namespace std;

void bru_way(int n)
{
    vector<int> ls(n+1, 1);

    for(int i = 2; i*i <= n; i++)
    {
        if(ls[i] == 1)
        {
            for(int j = 2 * i; j <= n; j += i)
            {
                ls[j] = 0;
            }
        }
    }
    
    for(int i = 2; i <= n; i++)
    {
        if(ls[i] == 1) cout<<i<<" ";
    }
    cout<<endl;
}


//We can optimise it in far better way
// inside of inside loop we can start from j = i * i because before calculations would already been completed by before numbers
//Now if it is going from i*i and checking then in first loop we do not need to go till n, rather go till sqrt(n)
int main()
{
    int n = 30;

    bru_way(n);
}