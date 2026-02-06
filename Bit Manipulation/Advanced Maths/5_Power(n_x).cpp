#include <iostream>
using namespace std;

int bru_way(int x, int n)
{
    int ans = 1;
    for(int i = 1; i <= n; i++) ans *= x;
    return ans;
}

double bet_way(double x, int n)
{
    int m = n;
    if(n < 0) n = -n;
    double ans = 1.0;
    while(n > 0)
    {
        if(n % 2 == 1)
        {
            ans *= x;
            n -= 1;
        }
        else
        {
            n = n / 2;
            x *= x;
        }
    }
    if(m < 0) ans = 1.0 / ans;
    return ans;
}

int main()
{
    double x = 2.1, n = 2;

    double ans = bet_way(x, n);
    cout<<ans<<endl;
}