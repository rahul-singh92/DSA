#include <iostream>
using namespace std;

int bru_way(int l, int r)
{
    int ans = 0;
    for(int i = l; i <= r; i++)
    {
        ans ^= i;
    }
    return ans;
}

int XOR_till_N(int n)
{
    if(n % 4 == 1) return 1;
    if(n % 4 == 2) return n + 1;
    if(n % 4 == 3) return 0;
    return n;
}

//The XOR of a number from 1 to n follow a pattern of n % 4
int op_way(int l, int r)
{
    return XOR_till_N(l - 1) ^ XOR_till_N(r);
}

int main()
{
    int l = 3, r = 5;

    int ans = op_way(l, r);
    cout<<ans<<endl;
}