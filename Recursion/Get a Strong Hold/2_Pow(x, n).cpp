#include <iostream>
using namespace std;

double myPow_bru_way(double x, int n)
{
    if(n == 0 || x == 1.0) return 1;

    long long temp = n;

    if(n < 0)
    {
        x = 1 / x;
        temp = -1 * 1LL * n;
    }

    double ans = 1;
    for(long long i = 0; i < temp; i++)
    {
        ans *= x;
    }
    return ans;
}

//Using Recursion

double power(double x, int n)
{
    //Anything raised to 0 is 1
    if(n == 0) return 1.0;

    //Anything raised to 1 is itself
    if(n == 1) return x;

    if(n % 2 == 0)
    {
        return power(x * x, n / 2);
    }
    return x * power(x, n - 1);
}

double myPow(double x, int n)
{
    int num = n;
    if(num < 0)
    {
        return (1.0 / power(x, -1 * num));
    }

    return power(x, num);
}

int main()
{
    cout<<myPow_bru_way(2.0000, 10)<<endl;
    cout<<myPow_bru_way(2.0000, -2)<<endl;
}