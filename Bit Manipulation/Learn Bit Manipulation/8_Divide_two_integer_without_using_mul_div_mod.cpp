#include <iostream>
using namespace std;

int divide(int dividend, int divisor)
{
    if(dividend == divisor) return 1;

    bool sign = true;

    if((dividend >= 0 && divisor < 0) || (dividend < 0 && divisor > 0)) sign = false;

    long n = abs(dividend);
    long d = abs(divisor);

    long quotient = 0;
    while(n >= d)
    {
        int count = 0;
        while(n >= (d << (count + 1)))
        {
            count++;
        }
        quotient += 1 << count;
        n -= (d << count);
    }
    if(quotient == (1 << 31) && sign) return INT_MAX;
    if(quotient == (1 << 31) && !sign) return INT_MIN;
    return sign ? quotient : -quotient;
}

int main()
{
    int n = 22, d = 3;

    int ans = divide(n, d);
    cout<<ans<<endl;
}